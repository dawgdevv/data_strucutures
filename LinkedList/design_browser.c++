#include <bits/stdc++.h>

using namespace std;

class BrowserHistory
{
private:
    class Node
    {
    public:
        string url;
        Node *prev;
        Node *next;

        Node(string url)
        {
            this->url = url;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    Node *current;

public:
    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newpage = new Node(url);
        current->next = newpage;
        newpage->prev = current;
        current = newpage;
    }

    string back(int steps)
    {
        while (steps > 0 && current->prev != nullptr)
        {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    string forward(int steps)
    {
        while (steps > 0 && current->next != nullptr)
        {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    string getcurrentpage()
    {
        return current->url;
    }
};

int main()
{
    BrowserHistory *browser = new BrowserHistory("leetcode.com");
    cout << "start: " << browser->getcurrentpage() << endl;

    browser->visit("google.com");
    cout << "visit: " << browser->getcurrentpage() << endl;

    browser->visit("facebook.com");
    cout << "visit: " << browser->getcurrentpage() << endl;

    browser->visit("youtube.com");
    cout << "visit: " << browser->getcurrentpage() << endl;

    cout << "going back 1 step: " << browser->back(1) << endl;

    browser->visit("lol.com");
    cout << "visit: " << browser->getcurrentpage() << endl;

    cout << "going forward 1 step: " << browser->forward(1) << endl;

    cout << "going back 2 steps: " << browser->back(2) << endl;

    return 0;
}
