template <typename T>
class Link {
private:
    T material;
public:
    Link(T material) {
        this->material = material;
    }

    T get_material() {
        return this->material;
    }
};

template <typename T>
class Node {
public:
    Link<T>* link;
    Node* next;
    explicit Node(Link<T>* link);

};

template <typename T>
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void add(Node<T>* newNode);
    Node<T>* get_head() {
        return this->head;
    }
};


