#pragma once
#include <utility>
#include <string>
#include <memory>
#include <optional>

typedef struct LinkedList {
  std::pair<std::string, int> element;
  std::shared_ptr<LinkedList> next;

  public:
    // insert the pair at the front of the linkedlist
    void insert_front(std::pair<std::string, int>);

    // find the pair containing string, remove it from the list, and return its corresponding int
    std::optional<int> remove(std::string string);

} LinkedList;