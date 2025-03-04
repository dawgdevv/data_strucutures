#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *reverseall(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *converttoll(vector<int> v)
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
    vector<int> v = {1, 2, 3, 4, 5, 6};

    Node *head = converttoll(v);

    head = reverseall(head);

    print(head);
}