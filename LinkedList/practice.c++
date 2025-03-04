#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *convertAtoll(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        temp->next = new Node(v[i]);
        temp = temp->next;
    }

    return head;
}
Node *deletehead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}
void print(Node *head)
{

    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertAtoll(v);
    head = deletehead(head);
    print(head);
}