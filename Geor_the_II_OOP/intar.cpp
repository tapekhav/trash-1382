#include <iostream>

class IntArray{
    int size;
    int* data;
public:
    IntArray(int size = 2):size(size),data(new int[size]){
        for(int i = 0; i < size; ++i){
            data[i] = i + 1;
        }
    }
    ~IntArray(){
        delete [] data;
    }
    void print(){
        for(int i = 0; i < size; ++i){
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }

    void set(int val, int index){
        data[index] = val;
    }

    IntArray(const IntArray& obj):size(obj.size){
        data = new int[size];
        for(int i = 0; i < size; ++i){
            data[i] = obj.data[i];
        }
    }

    IntArray& operator=(const IntArray& obj){
        if(this != &obj){
            delete []data;
            size = obj.size;
            data = new int[size];
            for(int i = 0; i < size; ++i){
                data[i] = obj.data[i];
            }
        }
        return *this;
    }

    IntArray(IntArray&& obj){
        std::swap(size, obj.size);
        std::swap(data, obj.data);
    }

    IntArray& operator=(IntArray&& obj){
        if(this != &obj){
            std::swap(size, obj.size);
            std::swap(data, obj.data);
        }
        return *this;
    }
};

IntArray f(){
    return IntArray(20);
}

int main(){
    IntArray arr1{5};
    IntArray arr2;
    arr2 = std::move(arr1);
    arr2.set(100, 2);
    arr1.print();
    IntArray arr3 = f();
}