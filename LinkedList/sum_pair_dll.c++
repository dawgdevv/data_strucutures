#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node *converttodll(vector<int> v)
{
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

vector<pair<int, int>> findpairs(Node *head, int k)
{

    Node *temp1 = head;
    vector<pair<int, int>> v;

    while (temp1 != NULL)
    {
        Node *temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data + temp2->data == k)
            {
                v.push_back({temp1->data, temp2->data});
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return v;
}
Node *findtail(Node *head)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

vector<pair<int, int>> findpairswithpointers(Node *head, int k)
{
    Node *left = head;
    Node *right = findtail(head);
    vector<pair<int, int>> v;

    while (right->next != left && left != right)
    {

        if (left->data + right->data == k)
        {
            v.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }

        else if (left->data + right->data < k)
        {
            left = left->next;
        }

        else
        {
            right = right->prev;
        }
    }

    return v;
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

    Node *head = converttodll(v);

    vector<pair<int, int>> pairs = findpairswithpointers(head, 7);

    cout << "Pairs with sum 7 are: " << endl;

    for (int i = 0; i < pairs.size(); i++)
    {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }

    cout << pairs.size() << endl;

    // print(head);
}