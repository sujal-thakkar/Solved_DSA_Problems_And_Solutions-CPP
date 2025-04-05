/* 981. Time Based Key-Value Store (https://leetcode.com/problems/time-based-key-value-store/description/):

    Design a time-based key-value data structure that can store multiple values 
    for the same key at different time stamps and retrieve the key's value at a certain timestamp.

    Implement the TimeMap class:
    
    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key with the value 
    at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that 
    set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, 
    it returns the value associated with the largest timestamp_prev. If there are no values, it returns "". */

// t.c.= O(log n), s.c.= O(m * n) where m = number of keys, n = number of values associated with a key.
#include <bits/stdc++.h>
using namespace std;

// Solution using Hash-Map 
class TimeMap {
private:
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin()? "" : prev(it)->second;
    }
};

// Solution using array and Binary Search
class TimeMap2 {
    private:
        unordered_map<string, vector<pair<int, string>>> keyStore;
    public:
        TimeMap2() {}
        
        void set(string key, string value, int timestamp) {
            keyStore[key].emplace_back(timestamp, value);
        }
        
        string get(string key, int timestamp) {
            auto& v = keyStore[key];
            int l=0, r=v.size()-1;
            string ans = "";
            while(l <= r) {
                int m = l + (r-l)/2;
                if(v[m].first <= timestamp) {
                    ans = v[m].second;
                    l = m + 1;
                }
                else r = m - 1;
            }
            return ans;
        }
    };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main() {
    TimeMap2* obj = new TimeMap2();
    obj->set("tasks", "dsa", 2);
    obj->set("tasks", "dev", 3);
    string getVal1 = obj->get("tasks", 3);
    cout << "value for key: tasks, ts: 3 is: " << getVal1 << endl;
    obj->set("sports", "cricket", 1);
    obj->set("sports", "tennis", 5);
    string getVal2 = obj->get("sports", 6);
    cout << "value for key: sports, ts: 6 is: " << getVal2<< endl;
    string getVal3 = obj->get("sports", 3);
    cout << "value for key: sports, ts: 3 is: " << getVal3 << endl;


    return 0;
}