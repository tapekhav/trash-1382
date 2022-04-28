void pow(int &a, int b){
    int n = a;
    if(b == 0){
        n = 1;
    }
    else{
        for (int i = 0; i < b - 1; i++)
        {
            n *= a;
        }
    }
    a = n;
}