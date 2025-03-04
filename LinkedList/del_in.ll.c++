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

Node *deletehead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deletekth(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    int cnt = 1;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
    }

    return head;
}
Node *deletevalue(Node *head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {

        prev = temp;
        temp = temp->next;
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
    }

    return head;
}

Node *insertathead(Node *head, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    temp->next = head;
    head = temp;

    return head;
}

Node *insertatend(Node *head, int data)
{
    Node *temp = new Node(data);
    Node *iter = head;

    if (iter == NULL)
    {
        return temp;
    }

    if (iter->next == NULL)
    {
        iter->next = temp;
        return head;
    }

    while (iter->next->next != nullptr)
    {
        iter = iter->next;
    }

    iter->next->next = temp;

    return head;
}

Node *insertatkth(Node *head, int k, int data)
{
    Node *aux = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = aux;
        return head;
    }

    if (k == 1)
    {
        aux->next = temp;
        head = aux;
        return head;
    }

    int cnt = 1;
    Node *prev = NULL;

    while (temp->next != NULL)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
        if (cnt == k)
        {
            prev->next = aux;
            aux->next = temp->next;
            break;
        }
    }
    return head;
}
Node *insertatvalue(Node *head, int k, int data)
{
    Node *aux = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = aux;
        return head;
    }

    if (k == 1)
    {
        aux->next = temp;
        head = aux;
        return head;
    }

    int cnt = 1;
    Node *prev = NULL;

    while (temp->next != NULL)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
        if (cnt == k)
        {
            prev->next = aux;
            aux->next = temp->next;
            break;
        }
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convertAtoll(v);
    // head = deletehead(head);
    head = insertatkth(head, 4, 67);
    print(head);
}
