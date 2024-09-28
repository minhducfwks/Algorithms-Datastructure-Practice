#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000


class Stack{
private:
    int top;
    int stackArray[MAX];
public:
    Stack(){
        top = -1;
    }
    bool push(int  item);
    int pop();
    bool isEmpty();
    bool isFull();
    int peek();
};

bool Stack::push(int item){
    if(!isFull()){
        stackArray[++top] = item;
        return true;
    }
    return false;
}

int Stack::pop(){
    return stackArray[top--];
}

int Stack::peek(){
    return stackArray[top];
}

bool Stack::isFull(){
    return  top == MAX - 1;
}

bool Stack::isEmpty(){
    return  top == -1;
}

int main()
{
    class Stack  s;
    for (int i = 0; i < 10; i++)
    {
        s.push(rand() % 20);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << s.pop() << endl;
    }
    

    std::cout << std::endl;
    return 0;
}