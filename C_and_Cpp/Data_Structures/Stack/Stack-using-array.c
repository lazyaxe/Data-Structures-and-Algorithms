//Stack C IMPLEMENTATION
/*
    ~>Stack is an abstract data type, that behaves like the real world stack.
    ~>Stack Data Structure(SDS), follows LIFO(Last-In-First-Out) order, where the element which is the latest insert is the first to be removed.
*/

/*
Basic Operations of stack:
    1. push: add/insert/appending an item on a stack
    2. pop: remove an item from a stack.
    3. peep: read a particular item on a stack
    4. change: change a particular item on a stack
*/

#include <stdio.h>
#define SIZE 2 //Change the size of Stack here

//initializing top to be -1, beacuse stack is empty
int top=-1;//top counter will do the appending & the deletion
int Stack[SIZE];

//push operation: inserstion at the last index of an array/append
void push(int value)
{
    //EDGE CASE 1: The first element/item
    if(top==-1)
    {
        top=0;
        printf("push: %d.\n", value);
    }
    //EDGE CASE 2: stack is full
    else if(top==SIZE-1)
    {
        printf("%d can't be pushed.\n", value);
        printf("The stack is full.\n");
        return;
    }
    //Normal case
    else
    {
        printf("push: %d.\n", value);
        top++;
    }
    //Appending/Insertion logic .i.e. simply arrray element initalization
    Stack[top]=value;
    return;
}

//pop operation: deletion of the first index in the array.
void pop()
{
    //EDGE CASE: The stack is empty.
    if(top==-1)
    {
        printf("The stack is empty.\n");
        return;
    }
    printf("pop: %d\n", Stack[top]);
    top--;
    return;
}

//peep operation:
void peep(int index)
{
    //EDGE CASE 1: If stack is empty
    if(top==-1)
    {
        printf("The stack is empty.\n");
        return;
    }
    //EDGE CASE 2: If index is out of range
    if(0>top || top<index)
    {
        printf("%d index is out of range\n", index);
        return;
    }
    printf("peep: %d, index: %d\n", Stack[index], index);
}

void change(int new_value, int index)
{
    //EDGE CASE 1: If stack is empty
    if(top==-1)
    {
        printf("The stack is empty.\n");
        return;
    }
    //EDGE CASE 2: If index is out of range
    if(index>top || 0>top)
    {
        printf("%d index is out of range\n", index);
        return;
    }
    Stack[index]=new_value;
    printf("change: %d, index: %d\n", Stack[index], index);
}
void user_input_stack_operations()
{
    printf("Which operation to call(Enter corresponding number)?:\n1. PUSH\n2. POP\n3. PEEP\n4. CHANGE\n5. EXIT THE FUNCTION\n");
    int user_choice=0;
    int input_value;
    int index;
    printf("Your choice: ");
    scanf(" %d", &user_choice);
    switch (user_choice)
    {
        case 1:
            printf("Enter the number to push: ");
            scanf("%d", &input_value);
            push(input_value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter the index: ");
            scanf("%d", &index);
            peep(index);
            break;
        case 4:
            printf("Enter the number to change: ");
            scanf("%d", &input_value);
            printf("Enter the index: ");
            scanf("%d", &index);
            change(input_value, index);
            break;
        case 5:
            return;

        default:
            printf("Invaild choice!\n");
            while(getchar()!='\n');
            break;
    }
    return user_input_stack_operations();//recursive call
}
int main()
{
    user_input_stack_operations(); 
    return 0;
}
