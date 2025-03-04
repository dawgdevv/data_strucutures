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
        this->next = next;
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

Node *even_odd(Node *head) // non efficient solution time complexity-O(n)
{
    vector<int> arr;

    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp != NULL)
    {
        arr.push_back(temp->data);
    }

    temp = head->next;

    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp != NULL)
    {
        arr.push_back(temp->data);
    }

    int i = 0;
    temp = head;
    while (temp != NULL)
    {
        temp->data = arr[i++];
        temp = temp->next;
    }

    return head;
}

Node *odd_even_eff(Node *head) // time complexity-O(n/2)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenhead;

    return head;
}

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    Node *head = converttoll(v);

    head = even_odd(head);

    print(head);
}