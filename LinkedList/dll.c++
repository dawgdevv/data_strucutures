#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node *convertAtoDLL(vector<int> v)
{
    if (v.empty())
        return nullptr;
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        temp->next = new Node(v[i]);
        temp->next->prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node *deletTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    Node *prev = NULL;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    prev = tail->prev;
    prev->next = NULL;
    tail->prev = NULL;
    delete tail;
    return head;
}

Node *deletekth(Node *head, int k)
{
    Node *temp = head;

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *back = NULL;
    Node *front = NULL;
    int cnt = 1;

    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
        if (cnt == k)
        {
            back = temp->prev;
            temp->prev = NULL;
            front = temp->next;
            temp->next = NULL;
            back->next = front;
            front->prev = back;
            delete temp;
            break;
        }
    }
    return head;
}

Node *deletevalue(Node *head, int value)
{
    Node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *back = NULL;
    Node *front = NULL;
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp->data == value)
        {
            back = temp->prev;
            temp->prev = NULL;
            front = temp->next;
            temp->next = NULL;
            back->next = front;
            front->prev = back;
            delete temp;
            break;
        }
    }
    return head;
}

Node *insertathead(Node *head, int data)
{
    Node *newnode = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    temp->prev = newnode;
    newnode->next = temp;
    head = newnode;
    return head;
}

Node *InsertatTail(Node *head, int data)
{
    Node *newTail = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = newTail;
        return head;
    }

    // while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newTail;
    newTail->prev = temp;

    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 44, 5, 6};
    Node *head = convertAtoDLL(v);

    head = insertathead(head, 44);
    print(head);
}