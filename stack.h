#ifndef ST_STACK_H
#define ST_STACK_H

#include <iostream>

template<typename T>
class Stack {
    template<class A>
    class Node {
    public:
        A value_;
        Node<A> *next;
        Node(A _v, Node<A> *_n = nullptr) : value_(_v), next(_n) {};
    };
public:
    int size_ = 0;
    Node<T> *first = nullptr;
    Stack(): size_(0), first(nullptr) {}
    T top() {
        if (is_empty())
            throw "the stack is empty";
        return first->value_;
    };

    T pop() {
        if (is_empty()) {
            throw "the stack is empty";
        }

        Node<T> *a = first;
        T return_val = first->value_;
        first = first->next;
        size_--;
        delete a;
        return return_val;
    };

    void push(T value) {
        size_++;
        first = new Node<T>(value, first);
    };

    bool is_empty() { return (first == nullptr); };

    void print(std::ostream &out = std::cout) { out << first->value_; }
/*
//    T operator[](int index) {
//        Node<T> *a = first;
//        while (index > 0) {
//            if (a->next == nullptr)
//                throw "index > size";
//            a = a->next;
//            index--;
//        }
//        return a->value_;
//    } */
};

#endif //ST_STACK_H
