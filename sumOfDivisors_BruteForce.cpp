/* Sum of all divisors from 1 to n (https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1):

Given a positive integer N., The task is to find the value of Σi from 1 to N F(i)
where function F(i) for the number i is defined as the sum of all divisors of i. */

// Time Complexity - O(N^2); Although the output is correct but the efficiency for larger N values is not compatible with exponential T.C.
#include <bits/stdc++.h>
using namespace std;

long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum = 1;
        
        for(long long i=2; i<=N; i++) {
            
            long long j=i;
            
            while(j>=1) {
                if(i % j == 0)
                    sum += j;
                j--;
            }
        }
        
        return sum;
    }

int main()
{
    int n = 7;
    long long ans = sumOfDivisors(7);
    cout << ans;
    
    return 0;
}