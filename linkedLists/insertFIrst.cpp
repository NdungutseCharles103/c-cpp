#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void displayNode(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertFirst(Node **head, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

int main() {
    Node *head = new Node();
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();

    n1->data = 2;
    n1->next = n2;
    n2->data = 3;
    n2->next = n3;
    n3->data = 4;
    n3->next = NULL;

    head->data = 1;
    head->next = n1;

    displayNode(head);
    insertFirst(&head, 0);
    displayNode(head);

}