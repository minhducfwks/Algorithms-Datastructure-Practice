#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
private:
    int frontIndex, rearIndex, size;
    unsigned capacity;
    int *arrayQueue;

public:
    Queue(unsigned cap)
    {
        capacity = cap;
        frontIndex = size = 0;
        rearIndex = cap - 1;
        arrayQueue = new int[(capacity * sizeof(int))];
    }
    int isFull()
    {
        return (size == capacity);
    }
    int isEmpty()
    {
        return (size == 0);
    }
    int enqueue(int data)
    {
        if (isFull())
        {
            return INT8_MIN;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arrayQueue[rearIndex] = data;
        size++;
        return data;
    }
    int dequeue()
    {
        if (isEmpty())
            return INT8_MIN;
        int temp = arrayQueue[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return temp;
    }
    int front()
    {
        if (isEmpty())
            return INT8_MIN;
        return arrayQueue[frontIndex];
    }
    int rear()
    {
        if (isEmpty())
            return INT8_MIN;
        return arrayQueue[rearIndex];
    }
};

int main()
{
    class Queue q(5);
    q.enqueue(10);
    q.enqueue(21);
    
    // Sử dụng vòng lặp và kiểm tra giá trị trả về của dequeue
    int data;
    while ((data = q.dequeue()) != INT8_MIN)
    {
        cout << data << endl;
    }
    
    std::cout << std::endl;
    return 0;
}
