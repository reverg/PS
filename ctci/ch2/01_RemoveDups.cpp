#include <iostream>
#include "LinkedList.cpp"
#include <unordered_map>
#include <random>

using namespace std;

static inline int random_range(const int min, const int max)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

// Solution 1
// space O(N), time O(N)
// use hash
void removeDuplicates1(Node *head)
{
    if (head == nullptr)
        return;

    unordered_map<int, int> node_map;

    Node *prev = head;
    Node *curr = head->next;
    node_map[head->data] = 1;

    while (curr != nullptr)
    {
        while (curr && node_map.find(curr->data) != node_map.end())
            curr = curr->next;

        prev->next = curr;
        prev = curr;

        if (curr)
        {
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
}

// Solution 2
// space O(1), time O(N^2)
// use two pointers
void removeDuplicates2(Node *head)
{
    if (head == nullptr)
        return;

    Node *curr = head;
    while (curr)
    {
        Node *runner = curr;
        while (runner->next != nullptr)
        {
            if (runner->next->data == curr->data)
                runner->next = runner->next->next;
            else
                runner = runner->next;
        }
        curr = curr->next;
    }
}

int main()
{
    LinkedList ll;
    for (int i = 0; i < 10; ++i)
    {
        ll.insertHead(random_range(1, 7));
    }
    ll.printList();
    removeDuplicates2(ll.head);
    ll.printList();
}