#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        string tar = "ADVITIYA";

        int permutation = 0;

        for (int i = 0; i < 8; i++)
        {
            char input = s[i];
            char target = tar[i];

            cout << "------input and target-------" << endl;

            cout << input << endl;

            cout << target << endl;

            cout << "---------------" << endl;

            if (input == target)
            {
                continue;
            }

            int diff = (target - input + 26) % 26;

            cout << "---------" << endl;

            cout << diff << endl;

            cout << "------------" << endl;

            permutation = permutation + diff;
        }

        cout << permutation << endl;
    }

    return 0;
}
