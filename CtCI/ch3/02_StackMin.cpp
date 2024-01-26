#include <iostream>
#include "Stack.cpp"

template <typename T>
class StackMin
{
private:
    Stack<T> stack;
    Stack<T> minStack;

public:
    void push(T value)
    {
        if (minStack.isEmpty() || value <= minStack.peek())
            minStack.push(value);
        stack.push(value);
    }

    T peek()
    {
        return stack.peek();
    }

    T min()
    {
        return minStack.peek();
    }

    T pop()
    {
        auto value = stack.pop();
        if (value == min())
            minStack.pop();
        return value;
    }

    bool isEmpty()
    {
        return stack.isEmpty();
    }
};

int main()
{
    StackMin<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6})
    {
        stack.push(v);
        std::cout << "Pushed value: " << v << ", min value: " << stack.min() << std::endl;
    }
    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        std::cout << "Popped value: " << v;
        if (stack.isEmpty())
            std::cout << ", stack is empty" << std::endl;
        else
            std::cout << ", min value: " << stack.min() << std::endl;
    }
    return 0;
}