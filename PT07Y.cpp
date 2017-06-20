#include<bits/stdc++.h>

using namespace std;

vector<int> adj[200001];
bool visited[200001];

void dfs(int s){
 int i;
 
   visited[s]=true;
   for(i=0;i<adj[s].size();++i){
    if(visited[adj[s][i]]==false)
     dfs(adj[s][i]);
   }
}


int main(){
int t,x,y;
  int n,e,i,components=0;
   cin>>n>>e;

   for(i=0;i<e;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    }

  for(i=0;i<=n;i++)
   visited[i]=false;

  for(i=1;i<=n;i++){
   if(visited[i] == false){
       dfs(i);
       components++;
     }
   }
//cout<<components;
if(components!=1 || e!=n-1)
 cout<<"NO"<<endl;
else
 cout<<"YES"<<endl;
return 0;
}
