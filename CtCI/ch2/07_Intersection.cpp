#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int getListLength(LinkedList *list)
{
    int len = 0;
    Node *ptr = list->head;
    while (ptr)
    {
        len += 1;
        ptr = ptr->next;
    }
    return len;
}

Node *intersection(LinkedList *ll1, LinkedList *ll2)
{
    int len1 = getListLength(ll1);
    int len2 = getListLength(ll2);

    Node *ptr1 = (len1 > len2) ? ll1->head : ll2->head;
    Node *ptr2 = (len1 > len2) ? ll2->head : ll1->head;

    int i = 0;
    while (i < abs(len1 - len2) && ptr1)
    {
        ptr1 = ptr1->next;
        i += 1;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return nullptr;
}

int main()
{
    LinkedList inter;
    inter.insertHead(1);
    inter.insertHead(2);
    inter.insertHead(7);

    LinkedList ll1;
    ll1.insertHead(9);
    ll1.insertHead(5);
    ll1.insertHead(1);
    ll1.insertHead(3);
    ll1.insertTail(inter.head);

    LinkedList ll2;
    ll2.insertHead(6);
    ll2.insertHead(4);
    ll2.insertTail(inter.head);

    Node *interNode = intersection(&ll1, &ll2);
    if (interNode != nullptr)
    {
        cout << interNode->data << endl;
    }
    else
    {
        cout << "nullptr" << endl;
    }
}