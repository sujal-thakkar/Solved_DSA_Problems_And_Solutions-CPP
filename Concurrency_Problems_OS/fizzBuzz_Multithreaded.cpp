// 1195. Fizz Buzz Multithreaded (https://leetcode.com/problems/fizz-buzz-multithreaded/description/):

// You have the four functions:

// printFizz that prints the word "fizz" to the console,
// printBuzz that prints the word "buzz" to the console,
// printFizzBuzz that prints the word "fizzbuzz" to the console, and
// printNumber that prints a given integer to the console.
// You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number.
// The same instance of FizzBuzz will be passed to four different threads:

// Thread A: calls fizz() that should output the word "fizz".
// Thread B: calls buzz() that should output the word "buzz".
// Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
// Thread D: calls number() that should only output the integers.
// Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...]
// where the ith token (1-indexed) of the series is:

// "fizzbuzz" if i is divisible by 3 and 5,
// "fizz" if i is divisible by 3 and not 5,
// "buzz" if i is divisible by 5 and not 3, or
// i if i is not divisible by 3 or 5.
// Implement the FizzBuzz class:

// FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
// void fizz(printFizz) Calls printFizz to output "fizz".
// void buzz(printBuzz) Calls printBuzz to output "buzz".
// void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
// void number(printNumber) Calls printnumber to output the numbers.

#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>
using namespace std;
class FizzBuzz
{
private:
    int n;
    mutex m;
    condition_variable c;
    int i;

public:
    FizzBuzz(int n)
    {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (i <= n)
        {
            unique_lock<mutex> lock(m);
            while (i <= n and (((i % 3) == 0) and ((i % 5) != 0)) == 0)
            {
                c.wait(lock);
            }
            if (i <= n)
            {
                printFizz();
                i++;
            }
            c.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (i <= n)
        {
            unique_lock<mutex> lock(m);
            while (i <= n and (((i % 5) == 0) and ((i % 3) != 0)) == 0)
            {
                c.wait(lock);
            }
            if (i <= n)
            {
                printBuzz();
                i++;
            }
            c.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (i <= n)
        {
            unique_lock<mutex> lock(m);
            while (i <= n and (((i % 3) == 0) and ((i % 5) == 0)) == 0)
            {
                c.wait(lock);
            }
            if (i <= n)
            {
                printFizzBuzz();
                i++;
            }
            c.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (i <= n)
        {
            unique_lock<mutex> lock(m);
            while (i <= n and (((i % 3) != 0) and ((i % 5) != 0)) == 0)
            {
                c.wait(lock);
            }
            if (i <= n)
            {
                printNumber(i++);
            }
            c.notify_all();
        }
    }
};

int main()
{

    return 0;
}