#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int val;
    struct node *left;
    struct node *right;
} node;

node *insert(node *head, int data)
{
    // happens dinamically and costs O(log(n)) time.
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return 2;

    n->val = data;
    n->left = NULL;
    n->right = NULL;
    // if no head
    if (!head)
    {
        head = n;
        return head;
    } 

    // find parent for the node;
    node *curr_node = head;
    while (curr_node != NULL)
    {
        if (curr_node->val > data)
        {
            if (curr_node->left)
            {
                curr_node = curr_node->left;
            }
            else
            {
                curr_node->left = n;
                break;
            }
        }
        else
        {
            if (curr_node->right)
            {
                curr_node = curr_node->right;
            }
            else
            {
                curr_node->right = n;
                break;
            }
        }
    }
    return head;
}

int main(void)
{
    node *head = NULL;

    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 3);
    return 0;
}