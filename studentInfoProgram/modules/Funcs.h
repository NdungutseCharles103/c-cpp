#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>

using namespace std;

// Linked List student
struct Student
{
    string name;
    int age;
    int rollNumber;
    float marks;
    Student *next;
};

// print student
void printStudent(Student *st)
{
    cout << "Name: " << st->name << endl;
    cout << "Age: " << st->age << endl;
    cout << "Roll Number: " << st->rollNumber << endl;
    cout << "Marks: " << st->marks << endl;
    cout << endl;
}

// insert student at the specified position
void insert(Student **head, Student *newNode, int pos)
{
    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Student *temp = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// merge linked list student
Student *mergeSortHigh(Student *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Student *slow = head;
    Student *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Student *mid = slow->next;
    slow->next = NULL;
    Student *left = mergeSortHigh(head);
    Student *right = mergeSortHigh(mid);
    Student *sorted = NULL;
    if (left->marks >= right->marks)
    {
        sorted = left;
        left = left->next;
    }
    else
    {
        sorted = right;
        right = right->next;
    }
    Student *s = sorted;
    while (left != NULL && right != NULL)
    {
        if (left->marks >= right->marks)
        {
            s->next = left;
            left = left->next;
        }
        else
        {
            s->next = right;
            right = right->next;
        }
        s = s->next;
    }
    while (left != NULL)
    {
        s->next = left;
        left = left->next;
        s = s->next;
    }
    while (right != NULL)
    {
        s->next = right;
        right = right->next;
        s = s->next;
    }
    return sorted;
}

// push student at the begginning of the linked list
void push(Student **head, Student *newNode)
{
    newNode->next = *head;
    *head = newNode;
}


#endif