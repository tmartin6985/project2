#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
using namespace std; 

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    // Constructor
    explicit SmartPointer(T* inputPtr = nullptr) {
        ptr = inputPtr;
        cout << "SmartPointer constructor called with pointer " << ptr << endl;
    }

    // Copy Constructor
    SmartPointer(const SmartPointer<T>& other) {
        if (other.ptr != nullptr) {
            ptr = new T(*other.ptr); // Create a deep copy
        } else {
            ptr = nullptr;
        }
        cout << "SmartPointer copy constructor called.\n";
    }

    // Copy Assignment Operator
    SmartPointer& operator=(const SmartPointer<T>& other) {
        if (this != &other) {
            delete ptr;
            if (other.ptr != nullptr) {
                ptr = new T(*other.ptr);
            } else {
                ptr = nullptr;
            }
        }
        cout << "SmartPointer copy assignment operator called.\n";
        return *this;
    }

    // Destructor
    ~SmartPointer() {
        delete ptr;
        cout << "SmartPointer destructor called. Object deleted.\n";
    }

    T& operator*() {
    return *ptr;
    }

    const T& operator*() const { // Const version
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    const T* operator->() const { // Const version
        return ptr;
    }


    friend ostream& operator<<(ostream& os, const SmartPointer<T>& smartPtr) {
        if (smartPtr.ptr != nullptr) {
            os << *smartPtr.ptr; // Dereference the pointer and print the object it points to
        } else {
            os << "null";
        }
        return os;
    }
};

#endif // SMARTPOINTER_H
