#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<ll, ll>, 
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        ll mod= 1e9+7;
        vector<ll> dist(n, LONG_MAX), ways(n, 0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            ll dis= it.first;
            ll node= it.second;
            for(auto it : adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]= dis+it.second;
                    ways[it.first]= ways[node];
                    pq.push({dis+it.second, it.first});
                }
                else if(dis+it.second==dist[it.first]){
                    ways[it.first]=((ways[it.first])%mod+(ways[node])%mod)%mod;
                }
            }
        }
        return ways[n-1];
    }