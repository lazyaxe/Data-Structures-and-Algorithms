#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 6

int top=-1;
int rear=-1;

int Queue[MAX_SIZE];

bool isQueueFull()
{
    if((rear + 1) % MAX_SIZE == top)
    {
        /*
            Because in circular queue last and first element are linked with each other, If the rear element comes around to from MAX_SIZE-1 to front, we can say Queue is full.
        */
        return true;
    }
    else
    {
        return false;
    }
}

bool isQueueEmpty()
{
    if(top==-1 && rear==-1)
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
        printf("Queue is full. Can't EnQueue %d", InputValue);
        return;
    }
    else if(isQueueEmpty())
    {
        top=rear=0;
        
    }
    else
    {
        rear=(rear+1)%MAX_SIZE;
    }
    Queue[rear]=InputValue;
    printf("\nEnQueued %d\n", Queue[rear]);
}

void DeQueue()
{
    if(isQueueEmpty())
    {
        printf("\nQueue is empty.\n");
    }
    else if(top==rear)
    {
        printf("\nDeQueued %d\n", Queue[top]);
        top=rear=-1;
    }
    else
    {
        printf("\nDeQueued %d\n", Queue[top]);
        top=(top+1)%MAX_SIZE;
    }
}

void show()
{
    if(isQueueEmpty())
    {
        printf("\nNothing to show.\n");
    }
    else
    {
        printf("\n-------------THE CIRCULAR QUEUE-----------------\n");
        for(int i=top; i<=rear; i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\n------------------------------------------------\n");
    }
}

int main()
{
    show();

    EnQueue(45);
    EnQueue(12);
    EnQueue(445);
    EnQueue(-1);
    EnQueue(69);
    EnQueue(420);

    show();

    EnQueue(4);

    DeQueue();
    show();

    DeQueue();
    show();

    DeQueue();
    show();

    DeQueue();
    show();

    DeQueue();
    show();

    DeQueue();
    show();


}