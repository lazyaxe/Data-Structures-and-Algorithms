/*
Queue implementation by Arrays by LazyAxe
*/
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 5

int Queue[MAX_SIZE];

int front=-1;
int rear=-1;


bool isQueueFull()
{
    if(rear==MAX_SIZE-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isQueueEmpty()
{
    if(front>rear||rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void EnQueue(int input_value)
{

    if(isQueueEmpty())
    {
        rear++;
        front=rear;
        Queue[rear]=input_value;

    }
    else if(isQueueFull())
    {
        printf("\nQueue is full, can't EnQueue %d.\n", input_value);
    }
    else
    {
         rear++;
         Queue[rear]=input_value;
    }
}

void DeQueue()
{
    if(isQueueEmpty())
    {
        printf("\n Queue is empty.\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(isQueueEmpty())
    {
        printf("\nQueue is empty, no display.\n");
    }
    else
    {
        printf("\n-------------THE QUEUE-----------------\n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    }
}

int main()
{
    display();

    EnQueue(12);
    EnQueue(42);
    EnQueue(14);
    EnQueue(0);
    EnQueue(43);
    EnQueue(69);
    
    display();

    printf("%d", isQueueFull());
    printf("%d", isQueueEmpty());

    
    DeQueue();
    display();
    
    DeQueue();
    display();

    DeQueue();
    display();

    DeQueue();
    display();

    DeQueue();
    display();

    DeQueue();
    return 0;
}

