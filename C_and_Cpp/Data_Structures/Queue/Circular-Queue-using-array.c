//CIRCULAR LINKED LIST USING ARRAY

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 2 //Change the size of circular queue from here

// -1 equivalent to NULL here
int front = -1;
int rear = -1;


int Queue[MAX_SIZE];

bool isQueueEmpty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isQueueFull()
{
    if((rear + 1) % MAX_SIZE == front)
    {
        /*
            ~> Because in circular queue last and first element are linked with each other, If the rear element comes around to from MAX_SIZE-1 to front, we can say Queue is full.
        */
        return true;
    }
    else
    {
        return false;
    }
}


void EnQueue(int input_value)
{
    if (isQueueFull())
    {
        printf("Queue is full. Can't EnQueue %d\n", input_value);
        return;
    }
    else if(isQueueEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX_SIZE;
    }
    Queue[rear] = input_value;
    printf("\nEnQueued %d\n", Queue[rear]);
}

void DeQueue()
{
    if(isQueueEmpty())
    {
        printf("\nQueue is empty.\n");
    }
    else if(front == rear)
    {
        printf("\nDeQueued %d\n", Queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDeQueued %d\n", Queue[front]);
        front = (front+1) % MAX_SIZE;
    }
}

void peek(int index)
{
    if (isQueueEmpty())
    {
        printf("The Queue is empty.\n");
    }
    else if(index < MAX_SIZE)
    {
        printf("Index: %d, Value: %d \n", index, Queue[(index) % MAX_SIZE]);
    }
    else
    {
        printf("Index out of range\n");
    }
}

void change(int value, int index)
{
    if (isQueueEmpty())
    {
        printf("The Queue is empty.\n");
    }
    else if(index < MAX_SIZE)
    {
        printf("Index: %d, %d changed to %d\n", index, Queue[(index - 1) % MAX_SIZE], value);
        Queue[(index - 1) % MAX_SIZE]=value;
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
        for(int i = front; i <= rear; i++)
        {
            peek(i);
        }
        printf("\n------------------------------------------------\n");
    }
}

void circular_queue_operations()
{
    printf("Which operation to call(Enter corresponding number)?:\n1. EnQueue\n2. DeQueue\n3. Peek\n4. Display Queue\n5. Change a element\n6. Exit Function\n");
    int user_choice = 0;
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
            while(getchar() != '\n');
            break;
    }
    return circular_queue_operations();//recursive call
}

int main()
{
    circular_queue_operations();
    return 0;

}