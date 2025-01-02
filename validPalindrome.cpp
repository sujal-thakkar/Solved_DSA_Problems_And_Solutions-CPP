#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
            left++;
        right--;

        return true;
    }
}
int main()
{

    string s;
    cin >> s;
    bool check = checkPalindrome(s);
    if (!check)
        cout << "FALSE! not palindrome";
    else
        cout << "TRUE! is palindrome";

    return 0;
}