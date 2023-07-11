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

    array(array&& obj) noexcept : size(std::move(obj.size))
    {
        obj.size = 5;
        std::cout << "Call Move construcor" << std::endl;
    }

    array& operator =(array&& obj) noexcept
    {
        if (this != &obj)
        {
            size = std::move(obj.size);
            std::cout << "Call move operator = " << std::endl;
        }
        return *this;
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

    array& operator=(const array& obj)
    {
        if (this != &obj)
        {
            delete[] arr;
            size = obj.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }

    array(const array& obj) : size(obj.size)
    {
        arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = obj.arr[i];
        }
    }
    
};

int main() {
    array Array(4);
    Array[0] = 2;
    Array[1] = 5;
    Array[2] = 43;
    Array[3] = 21;

    array Array2(4);
    Array2[0] = 4;
    Array2[1] = 1;
    Array2[2] = 53;
    Array2[3] = 91;

    std::cout << "Size of array = " << Array.getSize() << std::endl;
    for (int i = 0; i < Array.getSize(); ++i)
    {
        std::cout << Array[i] << " " << std::endl;

    }
    int elem = Array.getElement(2);
    std::cout << "get array element = " << elem << std::endl;

    Array = Array2;
    std::cout << "Size of assigned array = " << Array.getSize() << std::endl;
    for (int i = 0; i < Array.getSize(); ++i)
    {
        std::cout << Array[i] << " " << std::endl;

    }

    array Array4(std::move(Array2));

    Array = std::move(Array4);

    return 0;
}