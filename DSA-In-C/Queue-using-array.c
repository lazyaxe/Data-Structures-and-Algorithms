/*
Queue implementation by Arrays by LazyAxe
*/
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 5

int Queue[MAX_SIZE];

/*Intializing the front and rear to -1 to indicate the Queue is not initalized.*/
int front=-1;
int rear=-1;


bool isQueueFull()
{
    /*
        A condition to check if the Queue is full by checking if the rear==MAX_SIZE-1 i.e. Because the array's indexing is from 0 to n-1 meaning it's one behind.
        If it was rear==MAX_SIZE, The index would be out of range.
    */
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
    if(front==-1 && rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EnQueue(int InputValue)
{
    if (isQueueFull()) 
    {
        printf("\nQueue is full, can't EnQueue %d.\n", InputValue);
        return;
    }
    if (isQueueEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    Queue[rear] = InputValue;
    printf("\nEnQueued %d\n", Queue[rear]);   
}


void DeQueue()
{
    if(isQueueEmpty())
    {
        printf("\n Queue is empty.\n");
        return;
    }
    else if(front==rear)
    {
    /*
        The front should only be equal to rear, if its the the first element.
        Then the DeQueue should "remove" all the elements.
    */
        printf("\nDeQueued %d\n", Queue[front]);
        front=rear=-1;
    }
    else
    {
        front++;
        printf("\nDeQueued %d\n", Queue[front]);
    }
}

void display()
{
    if(isQueueEmpty())
    {
        printf("\n---------------------------------------\n");
        printf("\nQueue is empty, no display.\n");
        printf("\n---------------------------------------\n");

    }
    else
    {
        printf("\n-------------THE QUEUE-----------------\n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\n---------------------------------------\n");
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

