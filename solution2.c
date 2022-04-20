#include <iostream>

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
        i += n;
    }

private:
    int mData[100];
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

    Stack.extend(-5);

    cout << Stack.top() << endl;
    Stack.pop();
    cout << Stack.top() << endl;


    return 0;
}

