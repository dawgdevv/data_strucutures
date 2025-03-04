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

Node *addll(Node *head_1, Node *head_2)
{
    Node *t1 = head_1;
    Node *t2 = head_2;
    Node *dummy = new Node(0);
    Node *curr = dummy;

    int carry = 0;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;

        if (t1 != NULL)
        {
            sum = sum + t1->data;
            t1 = t1->next;
        }

        if (t2 != NULL)
        {
            sum = sum + t2->data;
            t2 = t2->next;
        }

        Node *newnode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newnode;
        curr = curr->next;
    }

    if (carry != 0)
    {
        Node *newnode = new Node(carry);
        curr->next = newnode;
    }

    return dummy->next;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";

        head = head->next;
    }

    cout << endl;
}

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

int main()
{
    vector<int> v1 = {3, 5};
    vector<int> v2 = {4, 5, 9, 9};

    Node *head_1 = convertoll(v1);
    Node *head_2 = convertoll(v2);

    Node *add_head = addll(head_1, head_2);

    print(head_1);
    print(head_2);
    print(add_head);
}