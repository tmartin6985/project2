#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>
#include <ostream>

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    //constructor
    explicit SmartPointer(T* ptr = nullptr) {
        this->ptr = ptr;
        std::cout << "SmartPointer constructor called with pointer: " << ptr << std::endl; //for bug testing
    }

    //destructor
    ~SmartPointer() {
        delete ptr;
        std::cout << "SmartPointer destructor called. Object deleted.\n"; //for bug testing
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const SmartPointer<T>& smartPtr) {
        if (smartPtr.ptr) {
            os << *smartPtr.ptr;  // Dereference the pointer and print the object it points to
        } else {
            os << "null";  // Handle null pointer case
        }
        return os;
    }
};

#endif // SMARTPOINTER_H
