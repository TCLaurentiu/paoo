#include "linkedlist.hpp"
#include <vector>
#include <iostream>

Node::Node(std::pair<std::string, int> element) {
  this->element = element;
  this->next = nullptr;
}

LinkedList::LinkedList() {
  this->head = nullptr;
}

std::optional<int> LinkedList::get_second(std::string string){
  std::shared_ptr<Node> iter = this -> head;
  while (iter != NULL){
    if (iter->element.first == string){
      return iter->element.second;
    }
    iter = iter->next;
  }
  return {};
}

void LinkedList::insert_front(std::pair<std::string, int> element) {
  std::shared_ptr<Node> new_node = std::make_shared<Node>(element);
  new_node -> next = this -> head;
  this -> head = new_node;
}

void LinkedList::print(){
  std::shared_ptr<Node> iter = this->head;
  while(iter != NULL){
    std::cout << "String: " << iter->element.first << " and int:" << iter->element.second << "\n";
    iter = iter->next;
  }
}

std::optional<int> LinkedList::remove(std::string string) {

  // we walk the list keeping the current node and previous node pointers
  std::shared_ptr<Node> iter = this->head;
  std::shared_ptr<Node> lagging_iter = nullptr;
  
  int to_return;
  while(iter != NULL){
    if(iter->element.first == string){
      to_return = iter->element.second;
      // removing the first element of the list
      if(lagging_iter == nullptr){
        this->head = this->head->next;
        return to_return;
      } else {
        // removing element in the middle of the list
        lagging_iter->next = iter->next;
        return to_return;
      }
    }

    lagging_iter = iter;
    iter = iter -> next;

  }

  return {};

}

std::vector<std::string> LinkedList::first_component_to_vector() {
  std::vector<std::string> v;
  std::shared_ptr<Node> iter = this->head;
  while(iter != NULL){
    v.push_back(iter->element.first);
    iter = iter -> next;
  }
  return v;
}