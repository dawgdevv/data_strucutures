#include <bits/stdc++.h>

using namespace std;

int printsubarray(vector<int> arr, int fk)
{

    int n = arr.size();

    int maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum = sum + arr[j];
            if (sum <= fk)
            {
                maxlen = max(maxlen, j - i + 1);
            }

            else
            {
                break;
            }
        }
    }

    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << printsubarray(arr, 9) << endl;
}