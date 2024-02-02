#include <iostream>
#include "Stack.cpp"

using namespace std;

template <typename T>
class MyQueue
{
private:
    Stack<T> stackNewest;
    Stack<T> stackOldest;

public:
    int size()
    {
        return stackNewest.size() + stackOldest.size();
    }

    void push(T value)
    {
        stackNewest.push(value);
    }

    T peek()
    {
        shiftStacks();
        return stackOldest.peek();
    }

    T pop()
    {
        shiftStacks();
        return stackOldest.pop();
    }

    bool isEmpty()
    {
        return size() == 0;
    }

private:
    void shiftStacks()
    {
        if (stackOldest.isEmpty())
        {
            while (!stackNewest.isEmpty())
            {
                stackOldest.push(stackNewest.pop());
            }
        }
    }
};

int main()
{
    MyQueue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.push(i);
        cout << "Queued value " << i << endl;
    }

    for (int i = 0; i < 5; ++i)
        cout << "Removed value " << queue.pop() << endl;

    for (int i = 10; i < 15; ++i)
    {
        queue.push(i);
        cout << "Queued value " << i << endl;
    }

    while (!queue.isEmpty())
        cout << "Removed value " << queue.pop() << endl;
}