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
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    Node *head = convertAtoll(v);
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}