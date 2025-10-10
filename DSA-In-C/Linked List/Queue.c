#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next_node;
}Node;

Node *front=NULL;

Node *rear=NULL; 

int queue_size=0;

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

void EnQueue(int input_value)
{
    Node* new_node=create_node(input_value);
    if(front==NULL)
    {
        front=new_node;
        rear=new_node;
    }
    else if(queue_size!=0)
    {
        Node *cursor=front;
        while(cursor->next_node != NULL)
        {
            cursor=cursor->next_node;
        }
        cursor->next_node=new_node;
        rear=new_node;
    }
    else
    {
        free(new_node);
    }
    queue_size++;
}

void DeQueue()
{
    if(front==NULL)
    {
        printf("\nThe Queue is empty\n");
    }
    else if(queue_size != 0)
    {
        Node *cursor=front;
        front=front->next_node;
        free(cursor);
    }
    else 
    {
        return;
    }
    queue_size--;
}

void change(int input_value, int index)
{
    if(index<0 || index>queue_size)
    {
        printf("Error: Invalid index\n");
        return;
    }
    else
    {
        Node *cursor = front;
        for(int i=0; i < index-1; i++)
        {
            cursor = cursor->next_node;
        }
        cursor->value = input_value;
    }
}

void display()
{
    Node *cursor=front;
    printf("\nDISPLAY:\n");
    while(cursor!=NULL)
    {
        printf("%d-->", cursor->value);
        cursor=cursor->next_node;
    }
    printf("NULL\n");
}

void queue_operations()
{
    printf("\nWhich operation to call(Enter corresponding number)?:\n1. EnQueue\n2. DeQueue\n3. Display Queue\n4. Exit Function\n");
    int user_choice=0;
    int input_value;
    int index;
    printf("Your choice: ");
    scanf(" %d", &user_choice);
    switch (user_choice)
    {
        //Enqueue
        case 1:
            printf("Enter the number to enqueue: ");
            scanf("%d", &input_value);
            EnQueue(input_value);
            break;

        //Dequeue
        case 2:
            DeQueue();
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
    return queue_operations();//recursive call
}

int main()
{
    queue_operations();
    return 0;
}