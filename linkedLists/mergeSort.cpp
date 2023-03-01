#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void displayNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// merge linked list node
Node *mergeSortHigh(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"slow: "<<endl;
    displayNode(slow);
    cout<<"fast: "<<endl;
    displayNode(fast);
    Node *mid = slow->next;
    cout<<"mid: "<<endl;
    displayNode(mid);
    slow->next = NULL;
    Node *left = mergeSortHigh(head);
    Node *right = mergeSortHigh(mid);

    cout<<"left: "<<endl;
    displayNode(left);
    cout<<"right: "<<endl;
    displayNode(right);
    Node *newHead = NULL;
    if (left->data < right->data)
    {
        newHead = left;
        left = left->next;
    }
    else
    {
        newHead = right;
        right = right->next;
    }
    
    Node *temp = newHead;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if (left != NULL)
    {
        temp->next = left;
    }
    if (right != NULL)
    {
        temp->next = right;
    }
    return newHead;
}

int main() {
    // insert 5 nodes
    Node *n1 = new Node();
    n1->data = 6;
    Node *n2 = new Node();
    n2->data = 2;
    Node *n3 = new Node();
    n3->data = 9;
    Node *n4 = new Node();
    n4->data = 3;
    Node *n5 = new Node();
    n5->data = 4;

    // link nodes
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    // display nodes
    displayNode(head);

    // sort nodes
    Node *newNodes = mergeSortHigh(head);

    // display nodes
    displayNode(newNodes);

    return 0;
}