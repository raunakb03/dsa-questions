#include <bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};
void insertSorted(stack<int>& s, int ele){
    if(s.empty() || (!s.empty() && s.top()<ele)){
        s.push(ele);
        return;
    }
    
    int num= s.top();
    s.pop();
    
    insertSorted(s, ele);
    
    s.push(num);
}
void SortedStack :: sort()
{
   if(s.empty()) return;
   
   int ele= s.top();
   s.pop();
   
   SortedStack::sort();
   
   insertSorted(s, ele);
}