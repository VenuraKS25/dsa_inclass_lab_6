#include<iostream>

using namespace std;

class Stack_Array{
    private:
    int size;
    int* stack;
    int top;

    public:
    Stack_Array(int size)
    {
        top = -1;
        this->size = size;
        stack = new int[size];
    }
    ~Stack_Array()
    {
        delete[] stack;
    }

    void push(int data);
    int pop();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
    
};

bool Stack_Array::isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_Array::isFull()
{
    if(top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack_Array::push(int data)
{
    if(isFull())
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int Stack_Array::pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else
    {
        int pop_data = stack[top];
        top--;
        return pop_data;
    }
}

void Stack_Array::display()
{
    for(int i = top; i>-1; i--)
    {
        cout<<stack[i]<<endl;
    }
}

void Stack_Array::clear()
{
    top = -1;
}

int main()
{

    Stack_Array stack_arr(10);
    srand(time(NULL));

    cout<<"Using Stack - Array"<<endl;
    for(int i = 0; i<10; i++)
    {
        int data = rand();
        stack_arr.push(data);
    }
    stack_arr.display();

    cout<<endl;
    for(int i = 0; i<5; i++)
    {
        stack_arr.pop();
    }
    stack_arr.display();
    cout<<endl;
    for(int i = 0; i<4; i++)
    {
        int data = rand();
        stack_arr.push(data);
    }
    stack_arr.display();
    cout<<endl;
    return 0;
}