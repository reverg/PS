#include <iostream>
#include "LinkedList.cpp"

using namespace std;

Node *findBeginning(LinkedList *list)
{
    Node *slow = list->head;
    Node *fast = list->head;

    // Find first meet point
    // Far from loop start point for (LOOP_SIZE - k)
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    // Error checkiing
    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }

    // two pointers meet at loop start point
    slow = list->head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

int main()
{
    LinkedList loopList;
    loopList.insertHead(5);
    loopList.insertHead(4);
    loopList.insertHead(3);
    loopList.insertHead(2);
    loopList.insertHead(1);
    loopList.insertHead(0);
    loopList.head->next->next->next->next->next->next = loopList.head->next->next;

    Node *loopStart = findBeginning(&loopList);
    loopStart->next = nullptr; // remove loop before print list
    loopList.printList();
}