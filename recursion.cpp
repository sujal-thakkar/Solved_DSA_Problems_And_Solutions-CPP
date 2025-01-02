#include <bits/stdc++.h>
using namespace std;

// Example 1:
// Print factorial of N using recursion;
int factorial(int n)
{

    if (n == 0)
        return 1;

    int partial_ans = factorial(n - 1);
    int ans = partial_ans * n;
    cout << ans;
    return ans;
}

// Example 2:
// print numbers from 1 to N using recursion:
void print_n_numbers(int n, int i)
{
    if (i > n)
        return;

    cout << i << " ";
    print_n_numbers(n, i + 1);
}
// 2nd method:
void print1toN(int n)
{
    if (n == 0)
        return;

    print1toN(n - 1);
    cout << n << ' ';
}

// Example 3:
// Print numbers from N to 1 using recursion:
void print_n_nums(int n)
{
    if (n < 1)
        return;

    cout << n << " ";
    print_n_nums(n - 1);
}

// practice 4:
// Given a number N, find the N-th Fibonacci number (f0 = 0, fl = 1) (Fn = Fn-1 + Fn-2)
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

int main()
{
    // int n = 4;
    // factorial(n);

    // int m = 10, i = 1;
    // print_n_numbers(m, i);

    // int n = 10;
    // print_n_nums(n);

    cout << fibo(8);

    // print1toN(10);

    return 0;
}