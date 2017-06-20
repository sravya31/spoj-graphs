#include<bits/stdc++.h>

using namespace std;

char a[1005][1005];
vector<int> adj[1000005];
bool visited[1000005]={false};
int total;

int dfs(int s){
  int m,m1=-1,m2=-1,i;
    visited[s]=true;
   for(i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]]==false){
           m=dfs(adj[s][i]);
           if(m>=m1){
            m2=m1;
            m1=m;
           }
           else if(m>m2){
             m2=m;
           }
      }
    }
   total=max(total,m1+m2+2);
return m1+1;
}

int main(){
int t,i,j;
cin>>t;
  while(t--){
   total=0;
    int n,m;
    cin>>n>>m;
    for(i=1;i<=m;i++){
     for(j=1;j<=n;j++){
      cin>>a[i][j];
      //visited[i][j]=false;
     }
    }
  for(int i=0;i<=1000005;i++)
    adj[i].clear();

  for(i=1;i<=m;i++){
   for(j=1;j<=n;j++){
     if(a[i][j]=='.'){
       if(i+1<=m && a[i+1][j]=='.')
         adj[n*(i-1)+j].push_back(n*(i-1+1)+j);
       if(i-1>=1 && a[i-1][j]=='.')
         adj[n*(i-1)+j].push_back(n*(i-1-1)+j);
       if(j+1<=n && a[i][j+1]=='.')
         adj[n*(i-1)+j].push_back(n*(i-1)+j+1);
       if(j-1>=1 && a[i][j-1]=='.')
         adj[n*(i-1)+j].push_back(n*(i-1)+j-1);
        }
      }
    }
   int flag=0;
   for(i=1;i<=(n*m);i++){
   if(adj[i].size()!=0){
   dfs(i);
   flag=1;
   break;
   }
   }
   if(flag==0)
    cout<<"Maximum rope length is 0."<<endl;
   else
    cout<<"Maximum rope length is "<<total<<"."<<endl;
}
return 0;
}
   
 
