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

Node *convertatoll(vector<int> v)
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

bool detectcyclewithmap(Node *head)
{
    map<Node *, int> node_map;
    Node *temp = head;

    while (temp != NULL)
    {
        if (node_map.find(temp) != node_map.end())
        {
            return true; // Cycle detected
        }
        node_map[temp] = 1;
        temp = temp->next;
    }
    return false; // No cycle detected
}

int lengthofcycle(Node *head)
{
    map<Node *, int> node_map;
    Node *temp = head;
    int ct = 1;

    while (temp != NULL)
    {
        if (node_map.find(temp) != node_map.end())
        {
            return ct - node_map[temp]; // Length of the cycle
        }

        node_map[temp] = ct;
        ct++;
        temp = temp->next;
    }

    return 0; // No cycle detected
}

int lengthiofcyclewithpointers(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int count = 1;
            Node *current = slow->next;
            while (current != slow)
            {
                current = current->next;
                count++;
            }

            return count;
        }
    }

    return 0;
}

bool detectcyclewithpointers(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

void createCycle(Node *head, int pos)
{
    if (pos == -1)
        return;

    Node *cycleNode = nullptr;
    Node *temp = head;
    int count = 0;

    while (temp->next != nullptr)
    {
        if (count == pos)
        {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = cycleNode;
}

Node *findthenode_where_cycle_started(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    Node *head = convertatoll(v);

    // Create a cycle for testing
    createCycle(head, 2); // Creates a cycle linking the last node to the node at index 2

    if (detectcyclewithpointers(head))
    {
        cout << "Cycle detected and length is:" << endl;
        int len = lengthiofcyclewithpointers(head);

        cout << len << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    Node *start = findthenode_where_cycle_started(head);

    cout << start->data << endl;

    return 0;
}
