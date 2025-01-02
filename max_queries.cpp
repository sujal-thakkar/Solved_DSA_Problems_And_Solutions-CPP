#include <bits/stdc++.h>
using namespace std;
void answerQueries(vector<int>&nums, vector<int>queries){
    int n = nums.size();
    int m = queries.size();

    for(int i=0; i<n; i++){
        int pre[i] = i == 0? nums[i] : max(pre[i-1], nums[i]);
    }
}

int main()
{
    
    return 0;
}