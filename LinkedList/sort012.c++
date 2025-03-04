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

Node *convertoll(vector<int> v)
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

Node *sort012ll(Node *head)

{

    Node *temp = head;
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }

        else if (temp->data == 2)
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    if (zerohead->next == NULL)
    {
        one->next = twohead->next;
        two->next = NULL;
        head = onehead->next;
    }

    else if (onehead->next == NULL)
    {
        zero->next = twohead->next;
        two->next = NULL;
        head = zerohead->next;
    }

    else if (twohead->next == NULL)
    {
        zero->next = onehead->next;
        one->next = NULL;
        head = zerohead->next;
    }

    else
    {
        zero->next = onehead->next;
        one->next = twohead->next;
        two->next = NULL;

        head = zerohead->next;
    }

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main()
{
    vector<int> v = {0, 1, 0, 2, 0, 1, 2, 0, 0, 2, 1, 2, 2, 2, 0, 0, 0, 0, 1, 2, 0, 1, 0, 2};

    Node *head = convertoll(v);

    head = sort012ll(head);

    print(head);
}