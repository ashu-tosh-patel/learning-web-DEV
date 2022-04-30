#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(
        sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int countNodes(struct Node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}

void swapKth(struct Node **head_ref, int k)
{

    int n = countNodes(*head_ref);

    if (n < k)
        return;

    if (2 * k - 1 == n)
        return;

    Node *x = *head_ref;
    Node *x_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        x_prev = x;
        x = x->next;
    }

    Node *y = *head_ref;
    Node *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++)
    {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
        x_prev->next = y;

    if (y_prev)
        y_prev->next = x;

    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    int t = x->data;
    int u = y->data;
    x->data = t + u;
    y->data = t + u;

    if (k == 1)
        *head_ref = y;
    if (k == n)
        *head_ref = x;
}

int main()
{
    // Let us create the following
    // linked list for testing
    // 1->2->3->4->5->6->7->8
    struct Node *head = NULL;
    for (int i = 8; i >= 1; i--)
            push(&head, i);

    cout << "Original Linked List: ";
    printList(head);

    //run the loop for length/2

    for (int k = 1; k < 5; k++)
    {
        swapKth(&head, k);
    }
    printList(head);

    return 0;
}