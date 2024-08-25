class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                break;
        }

        if (fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

/*
(Runtime, Memory) = (67.28%, 54.34%). #141 -> #142 -> #2360 -> #2608.
CtCI 2.8문제인데 설명이 복잡해서 아래 써둔거 보는게 낫다.

hash를 쓰면 처음 겹치는 주소 return하면 된다. 시간, 공간 모두 O(N).

투 포인터를 쓰면 조금 복잡하다. 루프의 시작점까지의 거리를 K라 하자.
느린 포인터가 루프의 시작점에 도달했을 때 빠른 포인터는 2K만큼 이동했으므로
루프 안에서 K만큼 더 돈 상태이다. 루프의 길이를 L이라 놓으면 빠른 포인터가
느린 포인터를 따라잡는데 L-K만큼의 시간이 더 필요하다. 따라서 두 포인터가
겹치는 때는 L만큼의 시간이 흘렀을 때고, 이 때 느린 포인터는 루프 안에서 L-K만큼
이동해있다. 이제 K만큼 이동하면 루프의 시작점에 도달하게 되는데 K는 출발점에서
루프의 시작점까지 거리였으므로 포인터 하나를 head로 옮기고 두 포인터를 1칸씩 옮겨서
둘이 겹치는 지점을 찾으면 된다. 지금까지 총 K + (L-K) + K만큼 돌았으므로 시간복잡도는
O(N). 공간은 포인터 2개 썼으므로 O(1)이다. 루프 크기가 K보다 작더라도 mod 값으로
바뀔 뿐이고 흐름에는 영향이 없다.
*/