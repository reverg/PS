#include <iostream>
#include "LinkedList.cpp"

using namespace std;

// Solution 1 - iterative
LinkedList sumListsIterative(LinkedList *list1, LinkedList *list2)
{
    Node *ptr1 = list1->head;
    Node *ptr2 = list2->head;

    LinkedList ret;

    int carry = 0;
    while (ptr1 && ptr2)
    {
        int val = (ptr1->data + ptr2->data) + carry;
        carry = int(val / 10);
        val %= 10;

        ret.insertTail(val);

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1)
    {
        int val = ptr1->data + carry;
        carry = int(val / 10);
        val %= 10;
        ret.insertTail(val);
        ptr1 = ptr1->next;
    }

    while (ptr2)
    {
        int val = ptr2->data + carry;
        carry = int(val / 10);
        val %= 10;
        ret.insertTail(val);
        ptr2 = ptr2->next;
    }

    return ret;
}

// Solution 2 - recursive
Node *sumListsRecursiveNode(Node *partlist1, Node *partlist2, int carry)
{
    if (partlist1 == nullptr && partlist2 == nullptr && carry == 0)
    {
        return nullptr;
    }

    int val = carry;
    if (partlist1)
    {
        val += partlist1->data;
    }
    if (partlist2)
    {
        val += partlist2->data;
    }

    Node *resNode = new Node(val % 10);
    resNode->next = sumListsRecursiveNode(partlist1 ? (partlist1->next) : nullptr, partlist2 ? (partlist2->next) : nullptr, val > 9 ? 1 : 0);

    return resNode;
}

LinkedList sumListsRecursive(LinkedList *list1, LinkedList *list2)
{
    LinkedList ret;
    ret.head = sumListsRecursiveNode(list1->head, list2->head, 0);
    return ret;
}

int main()
{
    LinkedList ll1;
    ll1.insertHead(6);
    ll1.insertHead(1);

    LinkedList ll2;
    ll2.insertHead(4);

    LinkedList ll_sum_iter = sumListsIterative(&ll1, &ll2);
    ll_sum_iter.printList();

    LinkedList ll_sum_rec = sumListsRecursive(&ll1, &ll2);
    ll_sum_rec.printList();
}