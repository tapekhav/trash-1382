#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 500

typedef struct{
	char arr[SIZE];
	int count;
    	int size;	
} ArrayStack;

int isEmpty(ArrayStack* stack);
int count(ArrayStack* stack);

// функция initStack
ArrayStack* initStack(){
    ArrayStack* stack = malloc(sizeof(ArrayStack));
    stack->count = 0;
    stack->size = SIZE;
    return stack;
}

// функция pop
void pop(ArrayStack* stack){
    stack->arr[stack->count--] = '\0';
}

// функция push
void push(ArrayStack* stack, char new_value){
    if (count(stack) != stack->size)
    {
        stack->arr[++stack->count] = new_value;
    }
}

// функция top
char top(ArrayStack* stack){
    if(!isEmpty(stack)) return stack->arr[stack->count];
    return 0;
}

// функция isEmpty
int isEmpty(ArrayStack* stack){
    if (count(stack) == 0)
    {
        return 1;
    }
    else return 0;
    
}

// функция count
int count(ArrayStack* stack){
    return stack->count;   
}

int main()
{
    char ch;
    ArrayStack* stack = initStack();
    char result[] = "correct";
    scanf("%c", &ch);
    while (ch != '\n')
    {
        if(strchr(")>}]", ch)){
            if(isEmpty(stack)) strcpy(result, "wrong");
            if(ch == ')' && top(stack) == '('){
                pop(stack);
            }
            else if ((int)top(stack)+2 == (int)ch)
            {
                pop(stack);
            }
            else
            {
                strcpy(result, "wrong");
            }
        }
        else if(strchr("(<{[", ch)){
            push(stack, ch);
        }

        scanf("%c", &ch);
    }
    printf("%s", result);
    return 0;
}