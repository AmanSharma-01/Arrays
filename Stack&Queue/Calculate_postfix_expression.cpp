// C++ program to evaluate value of a postfix expression 
#include <iostream> 
#include <string.h> 

using namespace std;

struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

    if (!stack) return NULL; 

    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

    if (!stack->array) return NULL; 

    return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 

int evaluatePostfix(char* exp) 
{ 
    struct Stack* st = createStack(strlen(exp));
    int i;

    if(!st) return -1;

    for(i=0;exp[i]; ++i)
    {
        if(isdigit(exp[i]))
        {
            push(st, exp[i]-'0');
        }
        else
        {
            int val1 = pop(st);
            int val2 = pop(st);

            switch(exp[i])
            {
                case '+': push(st, val2+val1); break;
                case '-': push(st, val2-val1); break;
                case '*': push(st, val2*val1); break;
                case '/': push(st, val2/val1); break;
            }
        }
    }
    return pop(st);
}

int main() 
{ 
    char exp[] = "231*+4-"; 
    cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
    return 0; 
} 