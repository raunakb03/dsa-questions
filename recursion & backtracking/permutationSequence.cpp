#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{
    // First, calculate the factorial of n and store it in fact.
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;

    // Next, create a vector to store the numbers from 1 to n.
    vector<int> numbers;
    for (int i = 1; i <= n; i++)
        numbers.push_back(i);

    // Since k is 1-based rather than 0-based, we need to subtract 1 from it.
    k--;
    string ans = "";

    // Now, we will iterate over all the positions in the permutation
    // and fill them in one by one.
    while (n > 0)
    {
        // First, divide fact by n and store the result in fact.
        fact /= n;

        // Next, calculate the index of the number we need to use
        // at the current position.
        int index = k / fact;

        // Append the number at that index to the answer string.
        ans += to_string(numbers[index]);

        // Remove that number from the vector of available numbers.
        numbers.erase(numbers.begin() + index);

        // Update n and k for the next iteration.
        n--;
        k %= fact;
    }

    // Finally, return the answer string.
    return ans;
}