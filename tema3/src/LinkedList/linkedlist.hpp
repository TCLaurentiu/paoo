#pragma once
#include <utility>
#include <string>
#include <memory>
#include <optional>
#include <vector>

typedef struct Node {
  std::pair<std::string, int> element;
  std::shared_ptr<Node> next;

  Node(std::pair<std::string, int>);
} Node;

typedef struct LinkedList {
  public:
    LinkedList();
    // insert the pair at the front of the linkedlist
    void insert_front(std::pair<std::string, int>);
    std::optional<int> get_second(std::string); 

    // find the pair containing string, remove it from the list, and return its corresponding int
    std::optional<int> remove(std::string string);

    std::vector<std::string> first_component_to_vector();

    void print();

  private:
    std::shared_ptr<Node> head;


} LinkedList;