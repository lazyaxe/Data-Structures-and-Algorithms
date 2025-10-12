#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left_node;
    struct Node *right_node;
}Node;

Node *root=NULL;

Node* create_new_node(int input_value)
{
    Node* temp= (Node*)malloc(sizeof(Node));
    if(temp!=NULL)
    {
        temp->key=input_value;
        temp->left_node=NULL;
        temp->right_node=NULL;
        return temp;
    }
    else
    {
        return NULL;
    }
}

Node* insert_node(Node *cursor,  int input_value)
{
    /*
        Now there will be two cases whem the return would be used differently. 
        CASE 1. Empty tree:
            If the tree is empty then the current node i.e. root node == NULL.
            Then it'll just return the temp to root and it'll be stored as a reference
        CASE 2. Tree with node(s):
            If this then it'll return the key to cursor->left_node or cursor->right_node 
    */
    if(cursor == NULL )//CASE 1: If cursor is at|referencing to NULL
    {
        return create_new_node(input_value);
    }
    else//CASE 2
    {
        if(cursor->key > input_value)
        {
            /*
                Recursive Code:
                    ~> The cursor first will be at root node since cursor = temp
                    ~> A comparision by if condition will be made to see if insert key is smaller than the root node or not.
                    
                    CASE 1: Condition is true:
                        ~> Here the cursor->left_node= will call insert_node() function till till cursor==NULL i.e. Traversing the left sub-tree.
                        ~> If it finds a leaf node, it fill return the reference to newly created node.
                    
                    CASE 2:
                        go to 'else'
            */
            cursor->left_node = insert_node(cursor->left_node, input_value);

            printf("\n%d inserted in left sub-tree\n", input_value);
        }
        else
        {
            /*
                Recursive Code:
                    ~> The cursor first will be at root node since cursor = temp
                    ~> Here the cursor->right_node = will call insert_node() function till cursor == NULL i.e. Traversing the right sub-tree.
                    ~> If it finds a leaf node, it fill return the reference to newly created node.
            */
            cursor->right_node = insert_node(cursor->right_node, input_value);
            printf("\n%d inserted in right sub-tree.\n", input_value);
        }
    }

    //during unwinding the 
    return cursor;
}

Node* search_node(Node *cursor, int key)
{
    if(cursor==NULL)
    {
        return NULL;
    }
    else
    {
        if(cursor->key > key)
        {
            cursor->left_node = search_node(cursor->left_node, key);
        }
    }
}

Node* find_min_node(Node *cursor)
{
    if(cursor==NULL)
    {
        return cursor;
    }
    else
    {
        if(cursor->left_node == NULL)
        {
            return cursor;
        }
        return find_min_node(cursor->left_node);
    }
}

Node* find_max_node(Node *cursor)
{
    if(cursor==NULL)
    {
        return cursor;
    }
    else
    {
        if(cursor->right_node == NULL)
        {
            return cursor;
        }
        return find_max_node(cursor->right_node);
    }
}

Node* find_min_node_iterative(Node *cursor)
{
    if(cursor==NULL)
    {
        return cursor;
    }
    else
    {
        while (cursor->left_node != NULL)
        {
           cursor = cursor->left_node;
        }
        return cursor;
    }  
}

Node* find_max_node_iterative(Node *cursor)
{
    if(cursor==NULL)
    {
        return cursor;
    }
    else
    {
        while (cursor->right_node != NULL)
        {
           cursor = cursor->right_node;
        }
        return cursor;
    }  
}

Node* delete_node(Node* cursor, int input_value)
{
    if(cursor == NULL)
    {
        /*
            Now there will be two cases whem the return would be used differently. 
            CASE 1. Empty tree:
                If the tree is empty then the current node i.e. root node == NULL. 
                Then it'll just return the temp to root and it'll be stored as a reference

            CASE 2. Tree with node(s):
                If this then it'll return the key to cursor->left_node or cursor->right_node 
        */
        printf("\nEmpty tree, %d cannot be deleted\n", input_value);
       return cursor;
    }
    else
    {
        if(cursor->key > input_value)
        {
            /*
                Recursive Code:
                    ~> The cursor first will be at root node since cursor = temp
                    ~> A comparision by if condition will be made to see if insert key is smaller than the root node or not.

                    If Condition is true:
                        ~> Here the cursor->left_node= will call insert_node() function till till cursor==NULL i.e. Traversing the left sub-tree.
                        ~> If it finds a leaf node, it'll free the reference to that node.
            */
            cursor->left_node = delete_node(cursor->left_node, input_value);

            printf("\n%d deleted in left sub-tree\n", input_value);
        }
        else if(cursor->key < input_value)
        {
            /*
                Recursive Code:
                    ~> The cursor first will be at root node since cursor = temp
                    ~> Here the cursor->righg_node= will call insert_node() function till till cursor==NULL i.e. Traversing the right sub-tree.
                    ~> If it finds a leaf node, it'll free the reference to that node.
            */
            cursor->right_node = delete_node(cursor->right_node, input_value);

            printf("\n%d deleted in right sub-tree.\n", input_value);
        }
        else
        {
            //CASE 1: If it's a leaf node
            if(cursor->left_node == NULL && cursor->right_node == NULL)
            {
                printf("\n%d, leaf node\n", input_value);

                free(cursor);
            }

            //CASE 2: If it's a non leaf node(w/ a single child node)
            else if(cursor->left_node == NULL)
            {
                Node *temp_cursor = cursor;
                cursor = cursor->right_node;
                printf("\n%d, non-leaf node w/ one child node \n", input_value);
                free(temp_cursor);
            }
            else if(cursor->right_node == NULL)
            {
                Node *temp_cursor = cursor;
                cursor = cursor->right_node;
                printf("\n%d, non-leaf node w/ one child node \n", input_value);
                free(temp_cursor);
            }
            
            //CASE 3: If it's a non-lead node (w/ two child nodes)
            else
            {
                //By using inorder successor
                printf("\n%d, non-leaf node w/ two child nodes \n", input_value);
                Node* inorder_successor = find_min_node(cursor->right_node);
                cursor->key = inorder_successor->key;

                free(inorder_successor);

                /*
                    //If you want inorder predecessor:
                    Node* inorder_predessor = find_max_node(cursor->right_node);
                    cursor->key = inorder_predessor->key;
                    free(inorder_predessor);
                */
            }
            return cursor;
        }
    }

}



void show()
{

}



int main()
{
    delete_node(root, 89);
    root = insert_node(root, 12);
    root = insert_node(root, 13);
    root = insert_node(root, 89);
    find_max_node(root);
    find_max_node_iterative(root);
    find_min_node(root);
    find_min_node_iterative(root);
    delete_node(root, 89);

    return 0;
}
