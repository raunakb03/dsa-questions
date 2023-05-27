#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
        if(!n) return false;
       if(!(n&(n-1))) return true;
       return false;
        
    }