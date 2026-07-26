#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next_node;
}Node;

Node *bottom=NULL;

Node *top=NULL; 

int stack_size=0;

Node* create_node(int value)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    if(new_node != NULL)
    {
        new_node->next_node=NULL;
        new_node->value=value;
        return new_node;
    }
}

void push(int input_value)
{
    Node* new_node=create_node(input_value);
    if(bottom==NULL)
    {
        bottom=new_node;
        top=new_node;
    }
    else if(stack_size!=0)
    {
        Node *cursor=bottom;
        while(cursor->next_node != NULL)
        {
            cursor=cursor->next_node;
        }
        cursor->next_node=new_node;
        top=new_node;
    }
    else
    {
        free(new_node);
    }
    stack_size++;
}

void pop()
{
    if(bottom==NULL)
    {
        printf("\nThe Queue is empty\n");
    }
    else if(stack_size != 0)
    {
        Node *cursor=bottom;
        bottom=bottom->next_node;
        free(cursor);
    }
    else 
    {
        return;
    }
    stack_size--;
}

void change(int input_value, int index)
{
    if(index<0 || index>stack_size)
    {
        printf("Error: Invalid index\n");
        return;
    }
    else
    {
        Node *cursor = bottom;
        for(int i=0; i < index-1; i++)
        {
            cursor = cursor->next_node;
        }
        cursor->value = input_value;
    }
}

void display()
{
    Node *cursor=bottom;
    printf("\nDISPLAY:\n");
    printf("NULL\n");
    while(cursor!=NULL)
    {
        printf("^\n");
        printf("%d\n", cursor->value);
        cursor=cursor->next_node;
    }
}

void stack_operations()
{
    printf("\nWhich operation to call(Enter corresponding number)?:\n1. push\n2. pop\n3. Display Queue\n4. Exit Function\n");
    int user_choice=0;
    int input_value;
    int index;
    printf("Your choice: ");
    scanf(" %d", &user_choice);
    switch (user_choice)
    {
        //push
        case 1:
            printf("Enter the number to push: ");
            scanf("%d", &input_value);
            push(input_value);
            break;

        //pop
        case 2:
            pop();
            break;

        //Display the Queue
        case 3:
            display();
            break;

        //exit the function
        case 5:
            return;

        //If Invaild input
        default:
            printf("Invaild choice!\n");
            while(getchar()!='\n');
            break;
    }
    return stack_operations();//recursive call
}

int main()
{
    stack_operations();
    return 0;
}