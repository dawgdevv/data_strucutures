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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

Node *rotatewithk(Node *head, int k)

{

    if (!head || !head->next || k == 0)
    {
        return head;
    }

    Node *curr = head;
    int len = 1;
    while (curr->next != NULL)
    {
        curr = curr->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return head;

    Node *newlast = head;
    for (int i = 0; i < len - k - 1; i++)
    {
        newlast = newlast->next;
    }

    Node *newhead = newlast->next;
    newlast->next = nullptr;
    curr->next = head;

    return newhead;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node *head = converttoll(v);

    Node *rotated = rotatewithk(head, 2);

    print(rotated);
}