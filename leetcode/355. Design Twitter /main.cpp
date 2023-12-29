#include <vector>
#include <set>
using namespace std;

#define MAXFEED 10

class User{
public:
    int id;
    set<int> follow;
    explicit User(int i):id(i){
        follow.insert(i);
    }
};

class Tweet{
public:
    int id;
    int timeSlot;
    int postBy;
    Tweet(int id, int timeSlot, int postBy) : id(id), timeSlot(timeSlot), postBy(postBy) {}
};



class Twitter {

    int time;
    vector<Tweet> tweets;
    vector<User> users;
public:
    Twitter():time(0) {
        users.reserve(510);
        for(int i=0; i<=500; ++i){
            users.emplace_back(i);
        }
    }

    void postTweet(int userId, int tweetId) {
        tweets.emplace_back(tweetId, time, userId);
        ++time;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> followerPost;
        for(int i=(int)tweets.size()-1; i>=0; --i){
            if(users[userId].follow.find(tweets[i].postBy)!=users[userId].follow.end()){
                followerPost.push_back(tweets[i].id);
            }
            if(followerPost.size()>=MAXFEED){
                break;
            }
        }
        return followerPost;
    }

    void follow(int followerId, int followeeId) {
        users[followerId].follow.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        users[followerId].follow.erase(followeeId);
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