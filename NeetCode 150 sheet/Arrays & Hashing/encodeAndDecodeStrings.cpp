/* Encode and Decode Strings(https://neetcode.io/problems/string-encode-and-decode):

Design an algorithm to encode a list of strings to a single string.
The encoded string is then decoded back to the original list of strings. */

//t.c.- O(m), s.c.- O(1), where m is the sum of lengths of all the strings. 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string encode(vector<string> &strs) {
        string s = "";
        for (int i = 0; i < strs.size(); i++) {
            string str = to_string(strs[i].size()) + '#' + strs[i];
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            string len = "";
            while (s[j] != '#') {
                len += s[j];
                j++;
            }
            int length = stoi(len);
            string str = "";
            j += 1;
            for (int k = 0; k < length; k++) {
                str += s[j];
                j++;
            }
            ans.push_back(str);
            i = j;
        }
        return ans;
    }
};

int main() {

    return 0;
}