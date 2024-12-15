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
    }

    // Copy Constructor
    SmartPointer(const SmartPointer<T>& other) {
        if (other.ptr != nullptr) {
            ptr = new T(*other.ptr); 
        } 
        
        else {
            ptr = nullptr;
        }
    }

    // Copy Assignment Operator
    SmartPointer& operator=(const SmartPointer<T>& other) {
        if (this != &other) {
            delete ptr;
            if (other.ptr != nullptr) {
                ptr = new T(*other.ptr);
            } 
            
            else {
                ptr = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() {
    return *ptr;
    }

    const T& operator*() const { 
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    const T* operator->() const { 
        return ptr;
    }


    friend ostream& operator<<(ostream& os, const SmartPointer<T>& smartPtr) {
        if (smartPtr.ptr != nullptr) {
            os << *smartPtr.ptr; 
        } 
        
        else {
            os << "null";
        }
        return os;
    }
};

#endif // SMARTPOINTER_H
