#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    //constructor
    explicit SmartPointer(T* ptr = nullptr) {
        this->ptr = ptr;
    }

    //destructor
    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    friend ostream& operator<<(ostream& os, const SmartPointer<T>& smartPtr) {
        os << *smartPtr.ptr;  // dereferencing the SmartPointer to access the Car object
        return os;
    }
};

#endif // SMARTPOINTER_H
