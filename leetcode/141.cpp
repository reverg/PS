class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;

        ListNode *fast = head->next;
        ListNode *slow = head;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
(Runtime, Memory) = (67.28%, 54.34%). #141 -> #142 -> #2360 -> #2608.
거쳐온 주소를 hash map에 다 때려박으면 시간, 공간 모두 O(N).
속도가 차이나는 두 포인터를 쓰면 루프에 들어간 후에 최대 루프 길이만큼 더 가면
따라잡게 된다. 따라서 시간은 O(N+K) = O(N). 공간은 포인터 2개만 쓰므로 O(1).
*/