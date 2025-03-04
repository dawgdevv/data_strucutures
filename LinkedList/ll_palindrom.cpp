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

bool checkpalindrome(Node *head) // brute force with extra stack space
{
    stack<int> s;
    Node *temp = head;

    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {

        if (temp->data != s.top())
        {
            return false;
        }

        s.pop();
        temp = temp->next;
    }

    return true;
}

bool checkpalindrome_better(Node *head) // without using stack
{
    if (head == NULL && head->next == NULL)
    {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = NULL;
    Node *curr = slow->next;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *first = head;
    Node *second = prev;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            return false;
        }

        second = second->next;
        first = first->next;
    }

    return true;
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
    vector<int> v = {1, 2, 3, 4, 3, 2, 1};

    Node *head = converttoll(v);

    if (checkpalindrome_better(head) == 1)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}