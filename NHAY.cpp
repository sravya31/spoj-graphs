#include<bits/stdc++.h>
using namespace std;
int main(){
int n,i,j;
string s1,s2;
cin>>n;
//while(scanf("%d",&n)!=EOF){
cin>>s1>>s2;
for(i=0;i<s1.size()-s2.size();i++){
  for(j=0;j<s2.size();j++){
    if(s1[i]!=s2[j])
      break;
    if(j==s2.size())
     cout<<i<<endl;
}
}
//}
return 0;
}
