#include <iostream>
#include <stdexcept>

class array {
private:
    int* arr;
    int size;

public:
    array(int size) : size(size) {
        arr = new int[size];
    }

    ~array() {
        delete[] arr;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    int getElement(int element)
    {
        return arr[element];
    }

    
};

int main() {
    array Array(4);
    Array[0] = 2;
    Array[1] = 5;
    Array[2] = 43;
    Array[3] = 21;

    std::cout << "Size of array = " << Array.getSize() << std::endl;
    for (int i = 0; i < Array.getSize(); ++i)
    {
        std::cout << Array[i] << " " << std::endl;

    }
    int elem = Array.getElement(2);
    std::cout << "get array element = " << elem << std::endl;

    return 0;
}