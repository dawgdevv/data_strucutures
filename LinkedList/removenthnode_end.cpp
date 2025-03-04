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

Node *removenthfromend(Node *head, int n)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == n)
    {
        Node *newhead = head->next;
        delete (head);

        return newhead;
    }

    int res = cnt - n;

    temp = head;

    while (temp != NULL)
    {

        res--;

        if (res == 0)
        {
            break;
        }

        temp = temp->next;
    }

    Node *delnode = temp->next;

    temp->next = temp->next->next;
    delete (delnode);

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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    Node *head = converttoll(v);

    head = removenthfromend(head, 2);

    print(head);
}