#include <stdexcept>

template <typename T>
class StackNode
{
public:
    T data;
    StackNode *next;

    StackNode(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack
{
private:
    StackNode<T> *topNode;
    int stackSize;

public:
    Stack() : topNode(nullptr), stackSize(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    int size()
    {
        return stackSize;
    }

    void push(T value)
    {
        StackNode<T> *newNode = new StackNode<T>(value);
        newNode->next = topNode;
        topNode = newNode;
        stackSize += 1;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow");
        }

        StackNode<T> *temp = topNode;
        T popValue = temp->data;
        topNode = topNode->next;
        delete temp;
        stackSize -= 1;

        return popValue;
    }

    bool isEmpty() const
    {
        return stackSize == 0;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return topNode->data;
    }
};
