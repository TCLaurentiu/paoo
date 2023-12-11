#include "linkedlist.hpp"

Node::Node(std::pair<std::string, int> element) {
  this->element = element;
  this->next = nullptr;
}

LinkedList::LinkedList() {
  this->head = nullptr;
}

void LinkedList::insert_front(std::pair<std::string, int> element) {
  std::shared_ptr<Node> new_node = std::make_shared<Node>(element);
  new_node -> next = this -> head;
  this -> head = new_node;
}