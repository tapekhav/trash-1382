// swap for int
void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

// swap for char*
void swap(char*& a, char*& b){
    char temp[20];
    strcpy(temp, b);
    strcpy(b, a);
    strcpy(a, temp);
}