// Given an array arr of N integers, write a function that returns true if there is a triplet(a, b, c)
// that satisfies a2 + b2 = c2, otherwise false.

#include <bits/stdc++.h>
using namespace std;

bool f(int arr[], int n)
{
    int maximum = 0;
    for (int i = 0; i < n; i++)
        maximum = max(maximum, arr[i]);

    int hash[maximum + 1] = {0};

    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    for (int i = 1; i < maximum + 1; i++)
    {
        if (hash[i] == 0)
            continue;

        for (int j = 1; j < maximum + 1; j++)
        {
            if ((i == j && hash[i] == 1) || hash[j] == 0)
                continue;

            int val = sqrt(i * i + j * j);

            if ((val * val) != (i * i + j * j))
                continue;

            if (val > maximum)
                continue;

            if (hash[val])
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << f(arr, n);
}