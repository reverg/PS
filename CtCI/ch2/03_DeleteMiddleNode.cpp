#include <iostream>
#include "LinkedList.cpp"

using namespace std;

bool deleteNode(Node *n)
{
    if (n == NULL || n->next == NULL)
        return false;

    Node *nextNode = n->next;
    n->data = nextNode->data;
    n->next = nextNode->next;

    return true;
}

int main()
{
    LinkedList ll;
    for (int i = 5; i > 0; --i)
        ll.insertHead(i);
    ll.printList();

    deleteNode(ll.head->next->next);
    ll.printList();

    deleteNode(ll.head->next);
    ll.printList();
}