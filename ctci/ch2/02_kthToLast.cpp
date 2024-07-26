#include <iostream>
#include "LinkedList.cpp"

using namespace std;

// Solution 1
// space: O(N), time: O(N)
Node *kthToLastReference(Node *head, int k, int &i)
{
    if (head == nullptr)
        return nullptr;

    Node *nd = kthToLastReference(head->next, k, i);
    i += 1;
    if (i == k)
        return head;

    return nd;
}

Node *kthToLastReference(Node *head, int k)
{
    int i = 0;
    return kthToLastReference(head, k, i);
}

// Solution 2
// space: O(1), time: O(N)
Node *kthToLastIterative(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *ptr1 = head;
    Node *ptr2 = head;

    int i = 0;
    while (i < k && ptr1)
    {
        ptr1 = ptr1->next;
        i++;
    }

    // out of bound
    if (i < k)
        return nullptr;

    while (ptr1 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}

int main()
{
    LinkedList ll;
    for (int i = 10; i > 0; --i)
        ll.insertHead(i);
    ll.printList();

    cout << kthToLastReference(ll.head, 4)->data << endl;
    cout << kthToLastIterative(ll.head, 6)->data << endl;
}