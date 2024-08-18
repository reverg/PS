class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA)
        {
            ptrA = ptrA->next;
            lenA++;
        }
        while (ptrB)
        {
            ptrB = ptrB->next;
            lenB++;
        }

        ptrA = headA;
        ptrB = headB;
        if (lenA > lenB)
        {
            for (int i = 0; i < lenA - lenB; i++)
                ptrA = ptrA->next;
        }
        else if (lenB > lenA)
        {
            for (int i = 0; i < lenB - lenA; i++)
                ptrB = ptrB->next;
        }

        while (ptrA)
        {
            if (ptrA == ptrB)
                return ptrA;

            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return NULL;
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
(Runtime, Memory) = (89.39%, 60.52%)
CtCI에 나온 문제. 두 연결 리스트의 길이를 확인하고 긴 리스트의 포인터를
헤드에서 차이만큼 옮겨서 길이를 맞춘 뒤, 동시에 진행하면서 교점이 있나
확인한다. 교점 없이 끝에 도달하면 만나지 않는 것. 시간복잡도는 길이 N, M인
연결 리스트 2개에 대해 O(N+M)이고 공간복잡도는 포인터 2개만 사용하므로 O(1).
*/