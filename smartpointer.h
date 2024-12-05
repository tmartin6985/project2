#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* ptr = nullptr) {
        this->ptr = ptr;
    }

    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }
};

#endif // SMARTPOINTER_H
