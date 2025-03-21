#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : data(value), left(nullptr), right(nullptr){ } // TODO: Implement constructor here
    Node(T value,Node<T>* l,Node<T>* r):data(value),left(l),right(r){};

    void print() {
        data.print();
    }
};


#endif // NODE_H