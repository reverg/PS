#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int value) : data(value), next(nullptr) {}
    Node(Node *head, int value) : data(value), next(head) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr) {}
    LinkedList(Node *node) : head(node) {}

    void insertHead(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void insertTail(Node* newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void deleteList()
    {
        Node *nextNode;
        while (head)
        {
            nextNode = head->next;
            delete (head);
            head = nextNode;
        }
    }

    void printList()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
