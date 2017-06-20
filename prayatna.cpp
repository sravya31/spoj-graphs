#include<bits/stdc++.h>

using namespace std;

 bool visited[100005];
 vector<int> adj[100005];

void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

int main(){
int t,i;
cin>>t;
while(t--){
 int n,answer=0,e;
scanf("%d %d",&n,&e);
  if(e==0 ){
   cout<<n<<endl;
   }
   else{
    for(i=0;i<e;i++){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
     }
  for(i=0;i<n;i++)
   visited[i]=false;
  for(i=0;i<n;i++){
    if(visited[i]==false){
      dfs(i);
      answer++;
     }
   }
cout<<answer<<endl;
}
}
}
