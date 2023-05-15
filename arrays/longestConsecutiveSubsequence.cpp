#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(!n) return 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int cnt=1;
        int ans=1;
        for(int i=0; i<n; i++){
            if(mp[nums[i]]){
                cnt=1;
                for(int j=1; ;j++){
                    if(mp[nums[i]-j]!=0){
                        cnt++;
                        mp[nums[i]-j]=0;
                    }
                    else break;
                }
                for(int j=1; ;j++){
                    if(mp[nums[i]+j]!=0){
                        cnt++;
                        mp[nums[i]+j]=0;
                    }
                    else break;
                }
                ans= max(ans, cnt);
            }
        }
        return ans;
    }