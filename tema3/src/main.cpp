#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <barrier>
#include "textloader.hpp"
#include "linkedlist.hpp"
#include "stringinthashmap.hpp"

#define bucket_count 1000

const auto processor_count = std::thread::hardware_concurrency();

std::unique_ptr<StringIntHashMap> map = std::make_unique<StringIntHashMap>(bucket_count);

std::vector<std::string> words = read_file_as_word_vector("../res/mobydick.txt");
int word_count = words.size();

std::vector<std::pair<std::string, int>> most_frequent_per_thread;

std::mutex map_mutex;
std::barrier finished_frequency_counting_barrier(processor_count);

void count_frequencies(int thread_index) {
  int part_size = word_count / processor_count;
  int starting_index = part_size * thread_index;
  
  int ending_index;
  // the last thread needs to deal with all the left over words
  // even if the word count isn't a multiple of processor_count
  if (thread_index == processor_count - 1){
    ending_index = word_count;
  } else {
    ending_index = part_size * (thread_index + 1);
  }

  for (int i = starting_index; i < ending_index; i ++){
    std::lock_guard<std::mutex> guard(map_mutex);
    std::optional<int> current_freq = map->get(words[i]);
    if (current_freq.has_value()){
      map->insert_reorder(std::make_pair(words[i], current_freq.value() + 1));
    } else {
      map->insert_reorder(std::make_pair(words[i], 1));
    }
  }

  finished_frequency_counting_barrier.arrive_and_wait();

  int buckets_per_thread = bucket_count / processor_count;
  int starting_bucket = buckets_per_thread * thread_index;
  int ending_bucket = thread_index == processor_count - 1 ? bucket_count : buckets_per_thread * (thread_index + 1);
  std::pair<std::string, int> largest_in_thread;
  std::optional<std::pair<std::string, int>> largest_in_bucket;

  for (int i=starting_bucket;i<ending_bucket;i++){
    largest_in_bucket = map->get_largest_in_bucket(i);
    if (largest_in_bucket.has_value()){
      if (largest_in_bucket.value().second > largest_in_thread.second) {
        largest_in_thread = largest_in_bucket.value();
      }
    }
  }

  {  
    std::lock_guard<std::mutex> guard(map_mutex);
    most_frequent_per_thread.push_back(largest_in_thread);
  }
  finished_frequency_counting_barrier.arrive_and_wait();

}

int main()
{
  std::vector<std::thread> threads(processor_count);

  for (int i =0;i<processor_count;i++){
    threads[i] = std::thread(count_frequencies, i);
  }

  for (int i = 0;i<processor_count;i++){
    threads[i].join();
  }

  std::cout << "Most common words found by each thread: \n";
  for (auto &item : most_frequent_per_thread) {
    std::cout << "Word " << item.first << " appeared " << item.second << " times\n"; 
  }

}