/*
  A Bad Implementaion of Linked List by me.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct  Node//typedef because i hate writing struct keyword frequently.
{
    int value;//Any datatype
    struct Node *next_node_reference;
}Node;

Node *head_pointer;

Node *tail_pointer;

void append_node(int input_value)
{
    /*
        We are trying to append the node to the last element by storing it's reference to the tail_pointer node 
    [head_pointer]-->[node_1]-->[appended_node]<--[tail_pointer]
                                |
                                V
                               NULL
    */
    Node *temp=(Node*)malloc(sizeof(Node));//allocate enough space for a struct

    if(temp!=NULL)//If temp is not null then space is allocated...
    {
        temp->value=input_value;
        if(head_pointer==NULL)//[head_pointer]--> NULL, means no nodes are in the linked list.
        {
            head_pointer=tail_pointer=temp;//If the list is empty, the new node becomes both head_pointer and tail_pointer.
            
            //[head_pointer]-->[appended_node]<--[tail_pointer]
            
            

        }
        else
        {
            tail_pointer->next_node_reference=temp;
            /*
            tail_pointer is a reference of the previous last node(node_n-1)

            [last_node]<---[tail_pointer]

            tail_pointer->next_node_reference accesses
            the previous_last_node's member named 'next_node_reference' which stores the reference to the next node which is NULL because it's the last node so there are no nodes after this node.

            And we modify the next_node_reference by storing the reference of the temp.

            [last_node(previously)]--->[last_node]``
                  ^ 
                  |            
            [tail_pointer]

            */

            tail_pointer=temp;
            //We are changing what is the tail_pointer poinzter is referencing to 
            /* 
             [head_pointer]-->[node_1]-->[appended_node]<--[tail_pointer]
                                       |
                                       V
                                      NULL
            */
        }
    }
}

void insert_node(int input_value, int index)// Index of 0 to n-1
{
    Node *temp= (Node*)malloc(sizeof(Node));
    temp->value=input_value;
    temp->next_node_reference=head_pointer;//the temp struct points to head_pointer's reference i.e. first node
    if(index<0)
    {
        printf("Error. Invaild index value");
    }
    else if(index==1)
    {
        /*
            Here the head copies the head_pointer's refernce i.e. address of the first_node.
    INDEX:                     0            1          2          3
            [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                ^                                  |
                                |                                  V
                                |                                  NULL
                            [temp(basically a struct controlled by a pointer)]
        */
       head_pointer=temp;
    }
    else if(index!=1)
    {
        Node *cursor = head_pointer;
        /*
            INDEX:              0          1          2          3
            [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                ^                                  |
                                |                                  V
                           [cursor] and [temp(pointer to Node)]        NULL

        The role of cursor: To traverse the nodes of the linked list,
        EXAMPLE:
            GOAL: To insert a node at index 2.

            WORKING:
                The If condition checks that index is bigger than one or not. 
                If true. the for loop is triggered the for loop will iterate index - 1 times(The loop will iterate 1 time)
                i.e. because the cursor is currently pointing to node ,so only index can cause an out of bounds error
                so we need to check for index-1 cause it's already at 0th index. 
                secondly -1 because we need to "link" the inserted_node with the node_1 


                                              Here,
                                        [inserted_node]
                                               |
                                               V
                INDEX:              0          1          2          3
                [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                    ^                                  |
                                    |                                  V
                                 [cursor] and [temp(pointer)]        NULL

                
                and then link node_2(previous):
        */

        for(int i = 0; i<index-1; i++)
        {
            cursor=cursor->next_node_reference;
            /*
                INDEX:              0           1          2          3
                [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                        [cursor] and [temp(pointer)]                 NULL
            */
        }
        
        
        temp->next_node_reference=cursor->next_node_reference;
        /*
            Explaination:
                    temp is pointer to a allocated struct Node. The temp pointer can access the struct's member named next_node_reference and init to cursor's reference to the node's next_node_reference so we can link temp to previous node.

                INDEX:              0             1               2          3
                                          +------------------------+
                                          |                        |
                                          |                        V
                [head_pointer]-->[node_1]--  [inserted_node]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                                  ^                                     |
                                                  |                                     V
                                    [cursor] and [temp(pointer)]                       NULL
        */
        cursor->next_node_reference=temp;
        /*
        Because the cursor is pointing the the node that we want BEFORE the inserted node, we link them both by init-ing the next_node_reference of that node to temp referenced node's address

            INDEX:                   0           1               2           3         4  
                [head_pointer]-->[node_1]-->[inserted_node]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                                  ^                                     |
                                                  |                                     V
                                    [cursor] and [temp(pointer)]                       NULL
        */
    }


}
void print_node()
{
    Node *cursor=head_pointer;
    //cursor ptr now references to head_pointer's reference i.e. the first node(not the head_pointer but the first node's address)

    while(cursor!=NULL)//checking if the cursor points to NULL or not.i.e. is the list empty or not
    {
        printf("%d-->", cursor->value);
        cursor=cursor->next_node_reference;
        /*
            cursor is a pointer to struct Node  or a struct Node pointer,

            so cursor has the reference of the first node because of the initialization above 

            so here the cursor is initialized again to bear the refernce of the second node or the next node 

            now the while loop will check the condition for which the next node have to be not NULL to trigger
            i.e. cursor has to point to a valid place.
        */
    }
    printf("\n");
}

void append_via_head(int input_value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->next_node_reference=head_pointer;
    temp->value=input_value;
    if(head_pointer==NULL)
    {
        head_pointer=temp;
    }
    else
    {
        Node *cursor;
        cursor=head_pointer;
        while(cursor->next_node_reference!=NULL)
        {
            cursor=cursor->next_node_reference;
        }
        cursor->next_node_reference=temp;
    } 
}

void delete_node(int index)
{


    /*
    CASE 1:
    Let's say we want to delete the node_1
                INDEX:              0           1          2          3
                [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                                    [cursor1]                         NULL
            */
    Node *cursor;
    cursor=head_pointer;
    if(index==0)
    {
        /*
        CASE 1 SOLUTION:
        We can unlink the node_1 from the head_pointer, can make the head pointer point to the next node i.e. node_2
                INDEX:              0           1          2          3

                      +------------------------+
                      |                        |
                      |                        V
                [head_pointer]   [node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                             [cursor(acts as a Node)]                  NULL
            */
        head_pointer=cursor->next_node_reference;
        // We make head_pointer to point to the address stored at cursor's referenced Node's next_node_reference i.e. node_2.
        
        cursor->next_node_reference=NULL;
        /*
            Because cursor is pointing to the same refernce as head_pointer i.e. the reference of node_1 the the re-init the the next_node_refernce to NULL
            INDEX:                 0           1          2          3

                      +------------------------+
                      |                        |
                      |                        V
                [head_pointer]   [node_1]   [node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                             [cursor(acts as a Node)]                  NULL

            Which now:
            INDEX:                  0           1          2          3

                [head_pointer]--->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                             [cursor(acts as a Node)]                  NULL

        */
       free(cursor);
    }
    else
    {
        cursor=head_pointer;
        Node *deletion_node=head_pointer;
        for(int i=0; i<index-1; i++)
        {
            cursor=cursor->next_node_reference;
        }
        deletion_node=cursor->next_node_reference;//deletion_node goes one Node further i.e the Node we want to delete.

        cursor->next_node_reference=deletion_node->next_node_reference;
        deletion_node->next_node_reference=NULL;

        /*
            INDEX:                   0           1          2          3
                [head_pointer]-->[node_1]-->[node_2]-->[node_3]-->[node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                              [cursor1(acts as a Node)]              NULL


            INDEX:                  0           1          2          3
                                                +--------------------+
                                                |                    |
                                                |                    V
                [head_pointer]-->[node_1]-->[node_2]   [node_3]-->[node_4]<--[tail_pointer]
                                                ^                     |
                                                |                     V
                              [cursor1(acts as a Node)]              NULL
            
            INDEX:                  0           1          2          3
                                                +--------------------+
                                                |                    |
                                                |                    V
                [head_pointer]-->[node_1]-->[node_2]   [node_3]   [node_4]<--[tail_pointer]
                                      ^                               |
                                      |                               V
                              [cursor1(acts as a Node)]              NULL



        */
       free(deletion_node);
    }

}
int main(void)
{
    printf("How many nodes? :");
    int number_of_nodes=4;//Assumption
    for(int i =0; i<number_of_nodes; i++)
    {
        printf("\nInput node value for node %d ? :", i+1);
        int input_value;
        scanf("%d", &input_value);
        append_node(input_value);
        printf("Node value inserted. At Node %d \n", i+1);
    }
    print_node();

    insert_node(69, 2);
    print_node();

    delete_node(2);
    print_node();
    return 0;
}  