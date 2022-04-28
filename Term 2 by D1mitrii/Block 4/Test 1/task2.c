


class CustomStack {

    public:
        // методы push, pop, size, empty, top + конструкторы, деструктор

        CustomStack(){
            count = 0;
            mData = new int[arr_size];
        }

        ~CustomStack(){
            delete [] mData;
        }

        void push(int val){
            if(count == (size() - 2)){
                extend(5);
            }
            mData[count++] = val;
        }

        void pop(){
            try{
                mData[--count] = 0;
            }
            catch(...){
                throw "error";
            }
        }

        int top(){
            if(empty()) throw "error";
            return mData[count-1];
        }

        size_t size(){
            return count;
        }

        bool empty(){
            return (count == 0);
        }

    private:
        // поля класса, к которым не должно быть доступа извне
        int count;
        int arr_size = 100;

        void extend(int n){
            arr_size += n;
            int* new_mData = new int[arr_size];
            memcpy(new_mData, mData, count * sizeof(int));
            delete [] mData;
            mData = new_mData;
        }

    protected:  // в этом блоке должен быть указатель на массив данных

        int* mData;
};

bool is_integer(string str){
    try
    {
        int i = stoi(str);
        return true;
    }
    catch(const std::invalid_argument&)
    {
        return false;
    }
    
}

int main()
{
    CustomStack Stack;

    int right_num;
    int left_num;

    string str_input;

    while (cin >> str_input)
    {
        if(is_integer(str_input)){

            Stack.push(stoi(str_input));
        }
        else
        {
            try
            {
                right_num = Stack.top();
                Stack.pop();
                left_num = Stack.top();
                Stack.pop();
            }
            catch(const char* exception)
            {
                cout << exception;
                return 0;
            }
            
            switch (str_input[0])
            {
            case '+':
                Stack.push(left_num + right_num);
                break;

            case '-':
                Stack.push(left_num - right_num);
                break;

            case '*':
                Stack.push(left_num * right_num);
                break;
            
            case '/':
                Stack.push(left_num / right_num);
                break;
            
            default:
                break;
            }

        }
        
    }

    if (Stack.size() > 1)
    {
        cout << "error";
    }
    else{
        cout << Stack.top();
        Stack.pop();
    }
    return 0;
}