#include <iostream>

using namespace  std;


class Stack{
public:
    Stack(){
        cnt = 0;
    }
    int size(){
        return cnt;
    }
    void push(int elem){
        arr[cnt] = elem;
        cnt ++;
    }
    int top(){
        return arr[cnt-1];
    }
    void pop(){
        cnt--;
    }
    int empty(){
        //empty => 1
        int res = cnt==0 ? 1 : 0;
        return res;
    }
private:
    int cnt;
    int arr[100];
};

int main(){

    Stack st;
    cout << st.size() << endl;
    st.push(10);
    cout << st.top() << endl;
    st.push(22);
    st.push(100);
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() <<endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.empty() << endl;
    st.pop();
    cout << st.empty() << endl;


    return 0;
}