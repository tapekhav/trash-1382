#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListStack{
	char sym;
    	struct ListStack* next;	
} ListStack;

int isEmpty(ListStack* head);
int count(ListStack* head);

// функция initStack
ListStack* initStack(){
    ListStack* stack = malloc(sizeof(ListStack));
    stack->next = NULL;
    return stack;
}

// функция pop
void pop(ListStack* head){
    ListStack* cur = head;
    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

// функция push
void push(ListStack* head, char value){
    ListStack* new_elem = malloc(sizeof(ListStack));
    new_elem->next = NULL;
    new_elem->sym = value;
    
    ListStack* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_elem;
}

// функция top
char top(ListStack* head){
    if(!isEmpty(head)){
        ListStack* cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        return cur->sym;
    }
    return 0;
}

// функция isEmpty
int isEmpty(ListStack* head){
    if (count(head) == 0)
    {
        return 1;
    }
    else return 0;
    
}

// функция count
int count(ListStack* head){
    int count = 0;
    ListStack* cur = head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    return count-1;
}

int main()
{
    char ch;
    ListStack* stack = initStack();
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