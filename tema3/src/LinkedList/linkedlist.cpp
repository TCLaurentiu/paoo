#include "linkedlist.hpp"

Node::Node(std::pair<std::string, int> element) {
  this->element = element;
  this->next = nullptr;
}

LinkedList::LinkedList() {
  this->head = nullptr;
}
