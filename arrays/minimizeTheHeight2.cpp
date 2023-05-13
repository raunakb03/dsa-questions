// !NOTE : REPEAT
#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int mini= arr[0]+k;
        int maxi= arr[n-1]-k;
        int ans= arr[n-1]-arr[0];
        int mi, ml;
        for(int i=0; i<n-1; i++){
            mi= min(mini, arr[i+1]-k);
            ml= max(maxi, arr[i]+k);
            if(mi<0) continue;
            ans= min(ans, ml-mi);
        }
        return ans;
    }