#include <iostream>
#include "Stack.cpp"
#include <vector>

using namespace std;

template <typename T>
class SortedStack
{
private:
    Stack<T> st;
    bool sorted;

    void sort()
    {
        if (sorted)
            return;

        Stack<T> helper;
        while (!st.isEmpty())
        {
            T value = st.pop();

            while (!helper.isEmpty() && value < helper.peek())
                st.push(helper.pop());

            helper.push(value);
        }

        while (!helper.isEmpty())
            st.push(helper.pop());

        sorted = true;
    }

public:
    SortedStack() : sorted(false) {}

    void push(T value)
    {
        st.push(value);
        sorted = false;
    }

    T peek()
    {
        sort();
        return st.peek();
    }

    T pop()
    {
        sort();
        return st.pop();
    }

    bool isEmpty()
    {
        return st.isEmpty();
    }

    int size()
    {
        return st.size();
    }
};

int main()
{
    SortedStack<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6})
    {
        stack.push(v);
        cout << "Pushed value: " << v << endl;
    }

    cout << endl;

    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        cout << "Popped value: " << v << endl;
    }
    return 0;
}