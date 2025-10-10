//CIRCULAR LINKED LIST:

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3 //Change the size of circular linked list from here

typedef struct Node
{
    int value;
    struct Node *next_node;
}Node;

Node *front = NULL;

Node *rear = NULL; 

int circular_queue_size=0;

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
    if(circular_queue_size == 0)
    {
        printf("\n New Queue Created \n");
        printf("\n %d is appended\n", input_value);
        
        front = new_node;
        rear = new_node;
        rear->next_node = front;

    }
    else if(circular_queue_size != 0 && circular_queue_size != MAX_SIZE)
    {
        rear->next_node = new_node;//Current last element's next node is new node

        rear = new_node;//So the new_node is the rear 
        
        rear->next_node = front; //So the last element must be connected to first element

        printf("\n %d is appended\n", input_value);
    }
    else if(circular_queue_size==MAX_SIZE)
    {
        printf("\n Circular queue is full \n");
        free(new_node);
        return;
    }
    circular_queue_size++;
}

void DeQueue()
{
    if(circular_queue_size==0)
    {
        printf("The Circular Queue is empty\n");
        return;
    }

    Node *deletion_node = front;
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = deletion_node->next_node;
        printf("\n %d deleted\n", deletion_node->value);
        rear->next_node = front;
    }
    free(deletion_node);
    circular_queue_size--;
}

void peek(int index)
{
    if(index == 0)
    {
        printf("%d", front->value);
    }
    else if(index == circular_queue_size)
    {
        printf("%d", rear->value);
    }
    else if(index>0 && index<circular_queue_size)
    {
        Node *cursor = front;
        for(int i=0; i<index-1; i++)
        {
            cursor = cursor->value;
        }
        printf("%d\n", cursor->value);
    }
}

void show()
{
    if(circular_queue_size == 0)
    {
        printf("The circular queue is empty.\n");
    }
    else
    {
        Node* cursor = front;
        for (int i = 0; i < circular_queue_size; i++)
        {
            printf("%d-->", cursor->value);
            cursor = cursor->next_node;
        }
        printf("\n");
    }
}

void change(int input_value, int index)
{
    if(circular_queue_size == 0)
    {
        printf("The circular queue is empty.\n");
    }
    else
    {
        Node* cursor = front;
        for (int i = 0; i < circular_queue_size; i++)
        {;
            cursor = cursor->next_node;
        }
        cursor->value=input_value;
        printf("\n");
    }
}

void circular_queue_operations()
{
    printf("Which operation to call(Enter corresponding number)?:\n1. EnQueue\n2. DeQueue\n3. Peek\n4. Display Queue\n5. Change a element\n6. Exit Function\n");
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
        //Peek a element
        case 3:
            printf("Enter the index: ");
            scanf("%d", &index);
            peek(index);
            break;
        //Display the Queue
        case 4:
            show();
            break;
        //Change a queue
            case 5:
            printf("Enter the new value: ");
            scanf("%d", &input_value);
            printf("Enter the index: ");
            scanf("%d", &index);
            change(input_value, index);
            break;
        //exit the function
        case 6:
            return;
        //If Invaild input
        default:
            printf("Invaild choice!\n");
            while(getchar()!='\n');
            break;
    }
    return circular_queue_operations();//recursive call
}

int main()
{
    circular_queue_operations();
    return 0;
}