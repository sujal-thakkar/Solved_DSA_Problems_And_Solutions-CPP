/* Sum of all divisors from 1 to n (https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1):

Given a positive integer N., The task is to find the value of Σi from 1 to N F(i)
where function F(i) for the number i is defined as the sum of all divisors of i. */

// Time Complexity - O(N log N); most intuitive and efficient for larger N values and smaller values as well.
#include <bits/stdc++.h>
using namespace std;

 long long sumOfDivisors(int N)
    {
        // Write Your Code here
        vector<long long> divisorSum(N + 1, 0);
        
        // Using the "SIEVE METHOD" to calculate sum of the divisors -->
        for(int i=1; i<=N; i++) 
        {
            for(int j=i; j<=N; j += i) 
            {
                divisorSum[j] += i;
            }
        }
        
        // summing up the finalSum -->
        long long finalSum = 0;
        
        for(int i=1; i<=N; i++) 
        {
            finalSum += divisorSum[i];
        }
        
        return finalSum;
    }

int main()
{
    
    return 0;
}