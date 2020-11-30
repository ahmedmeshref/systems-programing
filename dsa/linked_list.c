#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    // next hold address to a node, forthat its data type is struct node
    struct node *next;
} node;

node *prepend(node *head, int num)
{
    // allocate memory for the new node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(head);
        printf("Failed to allocate memory.\n");
        return head;
    }

    // set val for the node
    n->val = num;

    if (head != NULL)
    {
        node *temp = head;
        n->next = temp;
    }
    else
    {
        n->next = NULL;
    }
    head = n;
    return head;
}

void printNodes(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("Val: %d\n", temp->val);
        temp = temp->next;
    }
}

int main(void)
{
    node *head = NULL;

    head = prepend(head, 3);
    head = prepend(head, 2);

    // print all values
    printNodes(head);

    // free up all mem used
    while (head != NULL)
    {
        node *temp = head->next;
        free(head);
        head = temp;
    }
}