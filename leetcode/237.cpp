/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;

        // ListNode *tmp = node->next->next;
        // node->next->next = NULL;
        // node->next = tmp;
    }
};

/*
(Runtime, Memory) = (19.37%, 35.10%)
시간, 공간 복잡도 모두 O(1)으로 끝난다.
14~15행처럼 풀면 원래 node->next였던게 GC가 안 되지 않을까?란 생각이
들긴 하는데, 17~19행처럼 쓰면 pointer가 다 끊기므로 될 것 같기도 하다.
*/