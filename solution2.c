#include <iostream>
#include <cstdlib>

using namespace std;


class CustomStack {
public:
    void Stack() {
        i = 0;
    };

    int size() const{
        return i;
    }

    int top(){
        return mData[i - 1];
    }

    void push(int elem){
        mData[i] = elem;
        ++i;
    }

    void pop(){
        --i;
    }

    bool empty() const{
        if (i == 0) return true;
        return false;
    }

    void extend(int n){
        mData = (int*)realloc(mData, (i + n) * sizeof(int));
        //i += n;
    }

    void free(){
        delete mData;
    }
private:
    int* mData = (int*)(malloc(20 * sizeof(int)));
    int i;
};


int main() {
    CustomStack Stack{};

    cout << Stack.empty();

    Stack.push(123);
    Stack.push(342);
    Stack.push(321);
    Stack.push(324);


    cout << Stack.size() << endl;
    cout << Stack.empty() << endl;
    Stack.extend(5);
    cout << Stack.empty() << endl;

    cout << Stack.top() << endl;
    Stack.pop();
    cout << Stack.top() << endl;

    Stack.free();

    return 0;
}

