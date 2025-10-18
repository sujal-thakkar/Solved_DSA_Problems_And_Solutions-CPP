/* 355. Design Twitter (https://leetcode.com/problems/design-twitter/description/):
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, 
    and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. 
Each item in the news feed must be posted by users who the user followed or by the user themself. 
Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId. */

#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int time = 0;
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followList[userId].insert(userId);
        priority_queue<vector<int>> pq;
        for(int followee : followList[userId]) {
            auto &t = tweets[followee];
            if(!t.empty()) {
                int i = t.size()-1;
                pq.push({t[i].first, t[i].second, followee, i});
            }
        }
        vector<int> ans;
        while(!pq.empty() and ans.size() < 10) {
            auto top = pq.top(); pq.pop();
            int t = top[0], tweetId = top[1], uid = top[2], idx = top[3];
            ans.push_back(tweetId);
            if(idx > 0) {
                auto &tw = tweets[uid];
                pq.push({tw[idx-1].first, tw[idx-1].second, uid, idx-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    
 
    return 0;
}