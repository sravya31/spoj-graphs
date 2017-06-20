#include<bits/stdc++.h>

using namespace std;
char a[51][51];
int t=0,x,y,z=0,d=0,i,j,result=0,ans=0;
bool visited[51][51];

int dfs(int i,int j,int d){
   if(result<d){
    result=d;
   }
   visited[i][j]=1;
   if(i>=0 && i<x && j>=0 && j<y && visited[i][j]!=0){
    if(a[i][j]+1==a[i+1][j])
      dfs(i+1,j,d+1);
    if(a[i][j]+1==a[i+1][j+1])
      dfs(i+1,j+1,d+1);
    if(a[i][j]+1==a[i+1][j-1])
      dfs(i+1,j-1,d+1);
    if(a[i][j]+1==a[i-1][j+1])
      dfs(i-1,j+1,d+1);
    if(a[i][j]+1==a[i-1][j])
      dfs(i-1,j,d+1);
    if(a[i][j]+1==a[i-1][j-1])
      dfs(i-1,j-1,d+1);
    if(a[i][j]+1==a[i][j+1])
      dfs(i,j+1,d+1);
    if(a[i][j]+1==a[i][j-1])
      dfs(i,j-1,d+1);
    } 
 // visited[i][j]=0;
 return result;
}

int main(){
 while(1){
  t++;
  cin>>x>>y;
  if(x==0 && y==0)
   return 0;
  for(i=0;i<x;i++){
   for(j=0;j<y;j++){
    cin>>a[i][j];
   }
  }
  for(i=0;i<x;i++){
   for(j=0;j<y;j++){
    if(a[i][j]=='A'){
      result=0;
      ans=result;
      result=max(ans,dfs(i,j,1));
      }
    }
  }
cout<<"case "<<t<<":"<<result<<endl;
}
return 0;
}
