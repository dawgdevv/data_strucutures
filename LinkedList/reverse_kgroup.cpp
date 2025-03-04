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

Node *getkthnode(Node *temp, int k)
{
    while (temp != NULL && k > 1)
    {
        temp = temp->next;
        k--;
    }

    return temp;
}

Node *reverse(Node *head)
{
    Node *curr = head;

    Node *prev = NULL;
    Node *front = NULL;

    while (curr != NULL)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

Node *reverseKgroup(Node *head, int k)
{
    if (head == NULL || k == 1)
    {
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *kthnode = getkthnode(temp, k);

        if (kthnode == NULL)
        {

            if (prev == NULL)
            {
                prev->next = temp;
            }

            break;
        }

        Node *nxtnode = kthnode->next;

        kthnode->next = NULL;

        Node *newhead = reverse(temp);

        if (prev)
        {
            prev->next = newhead;
        }
        else
        {
            head = newhead;
        }

        prev = temp;

        temp = nxtnode;
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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node *head = convertAtoll(v);

    head = reverseKgroup(head, 3);
    print(head);
    return 0;
}