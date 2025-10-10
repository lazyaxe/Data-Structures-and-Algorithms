//QUEUE implementation by ARRAYS
/*
    ~>Queue is an abstract data type, that behaves like the real world Queue.
    ~>Queue Data Structure(QDS), follows FIFO(First-In-First-Out) order, where the element which is the first inserted is the first to be removed.
*/

/*
Basic Operations of Queue:
    1. EnQueue: add/insert/appending an item in a Queue
    2. DeQueue: remove an item from a Queue.
    3. Peek: read a particular item in a Queue.
    4. Change: change a particular item in a Queue.
*/

#include <stdbool.h>
#include <stdio.h>

#define SIZE 5 //Change the size of Queue here

int Queue[SIZE];

/*
    Intializing the front and rear to -1 to indicate the Queue is not initalized.
*/
int front=-1;
int rear=-1;


bool isQueueFull()
{
    /*
        A condition to check if the Queue is full by checking if the rear==SIZE-1 i.e. Because the array's indexing is from 0 to n-1 meaning it's one behind.
        If it was rear==SIZE, The index would be out of range.
    */
    if(rear==SIZE-1)
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
    /*
        A condition to check if the Queue is empty by checking if the front==-1 and rear==-1 i.e. Because the array's indexing is from 0 to n-1 meaning it's one behind.
    */
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

void peek(int index)
{
    if(isQueueEmpty())
    {
        printf("The Queue is empty.\n");
        return;
    }
    if(index>front || index<rear)
    {
        printf("The index is out of range\n");
        return;
    }
    printf("Queue[%d]=%d\n", index, Queue[index]);
}

void change(int new_value, int index)
{
    if(isQueueEmpty())
    {
        printf("The Queue is empty.\n");
        return;
    }
    if(index>front || index<rear)
    {
        printf("The index is out of range\n");
        return;
    }
    printf("Queue[%d]=%d\n", index, Queue[index]);
    printf("now\n");
    printf("Queue[%d]=%d\n", index, new_value);
    Queue[index]=new_value;
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

void queue_operations()
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
            display();
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
    return queue_operations();//recursive call
}

int main()
{
    queue_operations();
    return 0;
}

