#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,flag=1,x;
   scanf("%d",&n);
   while(n)
   {
      flag=1;
      stack<int> s;
      vector<int> v;
      for(int i=0;i<n;++i)
      {
         scanf("%d",&x);
  
         while(s.size() && s.top()<x)
         {    
            v.push_back(s.top());
            s.pop();
         }	
         s.push(x);
      }	
      while(s.size())
      {
         v.push_back(s.top());
         s.pop();
      }
      for(int i=0;i<v.size();++i)
      {
         if(v[i]!=i+1)
         {
            flag=0;
            break;
         }
      }
      if(flag)
         printf("yes\n");
      else
         printf("no\n");
      scanf("%d",&n);	
   }
   return 0;
}
