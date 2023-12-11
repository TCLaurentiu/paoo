#include "linkedlist.hpp"
#include <iostream>

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

void LinkedList::print(){
  std::shared_ptr<Node> iter = this->head;
  while(iter != NULL){
    std::cout << "String: " << iter->element.first << " and int:" << iter->element.second;
    iter = iter->next;
  }
}