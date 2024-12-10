#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "smartpointer.h"
using namespace std;

template <typename T>
class Node {
public:
    SmartPointer<T> data;
    Node* next;

    Node(SmartPointer<T> data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void add(SmartPointer<T> item) {
        Node<T>* newNode = new Node<T>(item);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void display() const {
        Node<T>* temp = head;
        while (temp) {
            cout << *(temp->data) << endl;
            temp = temp->next;
        }
    }

    int getSize() const {
        return size;
    }

    SmartPointer<T> get(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node<T>* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
            size--;
            return;
        }

        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }

        Node<T>* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }

    ~LinkedList() {
        Node<T>* temp = head;
        while (temp) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

#endif // LINKEDLIST_H
