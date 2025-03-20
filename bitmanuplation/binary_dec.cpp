#include <bits/stdc++.h>

using namespace std;

string dectobinary(int n)
{
    string res = "";

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = res + '1';
        }
        else
        {
            res = res + '0';
        }

        n = n / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int bintodec(string bin)
{
    int len = bin.length();
    int final = 0;

    for (int i = 0; i < len; i++)
    {

        if (bin[len - i - 1] == '1')
        {
            final += pow(2, i);
        }
    }

    return final;
}

int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;
    cout << "binary representation: " << dectobinary(n) << endl;
    string bin = dectobinary(n);
    cout << "dec represtation:  " << bintodec(bin) << endl;
    return 0;
}