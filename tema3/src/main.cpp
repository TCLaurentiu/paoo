#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "textloader.hpp"
#include "linkedlist.hpp"
#include "stringinthashmap.hpp"

const auto processor_count = std::thread::hardware_concurrency();

StringIntHashMap map(1000);
std::vector<std::string> words = read_file_as_word_vector("../res/mobydick.txt");
int word_count = words.size();

int main()
{
}