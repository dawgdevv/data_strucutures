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

Node *merge(Node *head1, Node *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    Node *temp1 = head1;

    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }

    temp1->next = head2;

    return head1;
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
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {7, 8, 9, 10, 11};
    Node *head1 = converttoll(v1);
    Node *head2 = converttoll(v2);

    Node *merged = merge(head1, head2);

    print(merged);
}