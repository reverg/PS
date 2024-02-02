#include <iostream>
#include "LinkedList.cpp"
#include <stack>

using namespace std;

bool isPalindrome(LinkedList *list)
{
    Node *fastRunner = list->head;
    Node *slowRunner = list->head;

    stack<int> st;

    // go to the middle point
    while (fastRunner != NULL && fastRunner->next != NULL)
    {
        st.push(slowRunner->data);
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
    }

    // length is odd number: skip one
    if (fastRunner != NULL)
    {
        slowRunner = slowRunner->next;
    }

    while (slowRunner != NULL)
    {
        int t = st.top();
        if (t != slowRunner->data)
        {
            return false;
        }
        st.pop();
        slowRunner = slowRunner->next;
    }

    return true;
}

int main()
{
    LinkedList ll1;
    ll1.insertHead(6);
    ll1.insertHead(1);
    ll1.insertHead(6);

    LinkedList ll2;
    ll2.insertHead(5);
    ll2.insertHead(7);

    cout << isPalindrome(&ll1) << " " << isPalindrome(&ll2) << endl;
}