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

Node *make_intersection(Node *head1, Node *head2, int pos)
{

    if (head1 == NULL || head2 == NULL)
    {
        return head1;
    }
    Node *temp1 = head1;
    Node *temp2 = head2;

    for (int i = 0; i < pos; i++)
    {
        temp1 = temp1->next;
    }

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;

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

Node *collision_point(Node *lower, Node *greater, int diff)
{

    while (diff > 0)
    {
        greater = greater->next;
        diff--;
    }

    while (lower && greater)
    {
        if (lower == greater)
        {

            return lower;
        }

        lower = lower->next;
        greater = greater->next;
    }
    return NULL;
}

Node *find_intersection(Node *head1, Node *head2)
{
    Node *t1 = head1;
    int n1 = 0;
    Node *t2 = head2;
    int n2 = 0;

    while (t1 != NULL)
    {
        n1++;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        n2++;
        t2 = t2->next;
    }

    if (n1 < n2)
    {
        return collision_point(head1, head2, n2 - n1);
    }
    else
    {
        return collision_point(head2, head1, n1 - n2);
    }
}

int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2 = {4, 5, 6, 7, 8, 9};

    Node *head1 = converttoll(v1);
    Node *head2 = converttoll(v2);

    make_intersection(head1, head2, 5);

    Node *inter = find_intersection(head1, head2);

    cout << inter->data << endl;
}
