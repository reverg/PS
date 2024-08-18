class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *preceder = head;
        for (int i = 0; i < n; i++)
            preceder = preceder->next;

        if (preceder == nullptr)
            return head->next;

        ListNode *follower = head;
        while (preceder->next != nullptr)
        {
            preceder = preceder->next;
            follower = follower->next;
        }

        follower->next = follower->next->next;
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
(Runtime, Memory) = (47.52%, 23.17%)
Cracking the Coding Interview에 있는 문제. 빠른 포인터와 느린 포인터를
쓰고, 빠른 포인터를 K개 앞에 보내두면 빠른 포인터가 연결 리스트의 끝에
도착했을 때 느린 포인터는 연결 리스트의 마지막에서 K번째 노드에 도착해있다.
만약 연결 리스트의 길이가 K이면 빠른 포인터가 nullptr가 돼서 14행에서
런타임 에러가 난다. 10~11행처럼 따로 처리하는 과정이 필요.
*/