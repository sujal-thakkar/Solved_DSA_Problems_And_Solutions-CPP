/* Sum of all divisors from 1 to n (https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1):

Given a positive integer N., The task is to find the value of Σi from 1 to N F(i)
where function F(i) for the number i is defined as the sum of all divisors of i. */

// Time Complexity - O(N); Although the T.C. is linear, with best can possible, but high computing and complex, not very efficient for smaller N values.
#include <bits/stdc++.h>
using namespace std;

long long sumOfDivisors(int N)
{
    // Write Your Code here
    long long totalSum = 0;

    for (int i = 1; i <= N; i++)
    {
        totalSum += i * (N / i);
    }

    return totalSum;
}

int main()
{
    int t;
    cout << "enter test-cases: ";
    cin >> t;
    cout << endl;

    while (t--)
    {
        int n;
        cout << "enter 'N': ";
        cin >> n;
        long long ans = sumOfDivisors(n);
        cout << "Sum of all divisors from 1 to n is: " << ans;
        cout << endl;
        cout << endl;
    }

    return 0;
}