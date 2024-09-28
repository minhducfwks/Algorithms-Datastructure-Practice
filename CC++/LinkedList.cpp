#include <iostream>
#include <algorithm>
using namespace std;

// Singly linkedlist
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->next = nullptr;
        this->data = data;
    }
};

void traverseLinkedList(Node *head)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << "\t";
        cur = cur->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void insertAtSpecificPos(Node *&head, int data, int pos)
{
    if (pos < 0)
    {
        cout << "Invalid position" << endl;
        return;
    }
    Node *newNode = new Node(data);
    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    Node *cur = head;
    int count = 0;
    while (cur != nullptr && count < pos - 1)
    {
        cur = cur->next;
        count++;
    }
    if (cur == nullptr)
    {
        cout << "Position out of range" << endl;
        return;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

int main()
{
    Node *head = new Node(8);
    traverseLinkedList(head);
    insertAtHead(head, 10);
    traverseLinkedList(head);
    insertAtSpecificPos(head, 2, 1);
    traverseLinkedList(head);

    return 0;
}
