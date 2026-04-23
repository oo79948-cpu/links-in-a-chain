
#include "link.hpp"

template <typename T>
Node<T>::Node(Link<T>* link) {
    this->link = link;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::add(Node<T>* new_node) {
    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    size++;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *next = nullptr;
    Node<T> *current = this->head;
    while(current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}