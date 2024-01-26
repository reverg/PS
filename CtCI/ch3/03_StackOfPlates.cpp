#include <iostream>
#include "Stack.cpp"
#include <vector>

using namespace std;

template <typename T, size_t Capacity>
class SetOfStacks
{
private:
    vector<Stack<T> *> stacks;

public:
    SetOfStacks()
    {
        Stack<T> *newStack = new Stack<T>();
        stacks.emplace_back(newStack);
    }

    void push(T value)
    {
        if (stacks[stacks.size() - 1]->size() < Capacity)
        {
            stacks[stacks.size() - 1]->push(value);
        }
        else
        {
            Stack<T> *newStack = new Stack<T>();
            newStack->push(value);
            stacks.emplace_back(newStack);
        }
    }

    T peek()
    {
        return stacks[stacks.size() - 1]->peek();
    }

    T pop()
    {
        T val = stacks[stacks.size() - 1]->pop();
        if (stacks[stacks.size() - 1]->size() == 0)
        {
            stacks.pop_back();
        }
        return val;
    }

    T popAt(int idx)
    {
        T val = stacks[idx - 1]->pop();
        if (stacks[idx - 1]->isEmpty())
        {
            stacks.erase(stacks.begin() + idx - 1);
        }
        return val;
    }

    bool isEmpty()
    {
        return stacks.size() == 0 && stacks[0].size() == 0;
    }

    int size()
    {
        return stacks.size();
    }
};

int main()
{
    SetOfStacks<int, 2> stack;
    for (int i = 0; i < 13; ++i)
    {
        stack.push(i);
        cout << i << " is pushed into the stack " << stack.size() << endl;
    }
    cout << "Current stack size is " << stack.size() << endl
         << endl;

    cout << stack.popAt(4) << " is popped from the stack 4" << endl;
    cout << stack.popAt(4) << " is popped from the stack 4" << endl;
    cout << "Current stack size is " << stack.size() << endl
         << endl;

    while (stack.size() != 0)
    {
        size_t stackNo = stack.size();
        cout << stack.pop() << " is popped from the stack " << stackNo << endl;
    }
}