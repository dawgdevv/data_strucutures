#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node *convertAtoDLL(vector<int> v)
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

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }

    cout << endl;
}

Node *reversedll_stack(Node *head) // This will have a time complexity of O(2N) and space complexity is O(N) because we are using a extra stack space.
{
    if (!head || !head->next)
    {
        return head;
    }

    stack<int> st;

    Node *curr = head;

    while (curr)
    {
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (!st.empty())
    {
        curr->data = st.top();
        st.pop();
        curr = curr->next;
    }

    return head;
}

Node *reversedll_links(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *temp = NULL;
    Node *curr = head;
    Node *last = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        last = curr;

        curr = temp;
    }

    head = last;

    return head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    Node *head = convertAtoDLL(v);

    print(head);

    head = reversedll_links(head);

    print(head);
}