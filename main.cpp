#include <iostream>

#include "src/link.cpp"

int main() {
  LinkedList<std::string> list;

  Link<std::string> gold = Link<std::string>("gold");
  Node<std::string>* node_one = new Node(&gold);
  list.add(node_one);

  Link<std::string> silver = Link<std::string>("silver");
  Node<std::string>*  node_two = new Node(&silver);
  list.add(node_two);

  Link<std::string> bronze = Link<std::string>("bronze");
  Node<std::string>*  node_three = new Node(&bronze);
  list.add(node_three);

  Node<std::string>*  retrieved_node_two = node_one->next;
  Node<std::string>*  retrieved_node_three = node_two->next;
  std::cout << "======================================="<< std::endl;
  std::cout << "Retrieved node two material: " << retrieved_node_two->link->get_material() << std::endl;
  std::cout << "Retrieved node tree material: " << retrieved_node_three->link->get_material() << std::endl;
  std::cout << "======================================="<< std::endl;
  std::cout << "Travers string list from HEAD" << std::endl;
  auto current = list.get_head();
  int count = 0;
  while (current != nullptr) {
    count++;
    std::cout << count << ": " << current->link->get_material() << std::endl;
    current = current->next;
  }
  std::cout << "======================================="<< std::endl;

  LinkedList<int> numList;
  Link<int> day = Link<int>(22);
  Node<int>* num_node_one = new Node(&day);
  numList.add(num_node_one);
  Link<int> month = Link<int>(04);
  Node<int>* num_node_two = new Node(&month);
  numList.add(num_node_two);
  Link<int> year = Link<int>(2026);
  Node<int>* num_node_three = new Node(&year);
  numList.add(num_node_three);
  std::cout << "Travers int list from HEAD" << std::endl;

  auto num_current = numList.get_head();
  count = 0;
  while (num_current != nullptr) {
    count++;
    std::cout << count << ": " << num_current->link->get_material() << std::endl;
    num_current = num_current->next;
  }
  std::cout << "======================================="<< std::endl;
}
