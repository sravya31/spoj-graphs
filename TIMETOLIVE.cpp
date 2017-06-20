#include<bits/stdc++.h>

using namespace std;
vector<int> adj[1000005];
bool visited[1000005]={false};
int result=0,check_index=0;

void dfs(int node,int dist){
  int i;
	if(result<dist)
	{
		//	cout<<result<<" "<<dist<<endl;
            result = dist; 
            check_index = node;
	}
 visited[node]=1;
  for(i=0;i<adj[node].size();i++){
    if(visited[adj[node][i]]==false)
    dfs(adj[node][i],dist+1);
   }
  visited[node]=0;
}

int main(){
int t,i,n,x,y;
cin>>t;
  while(t--){
    cin>>n;
    for(i=0;i<1000005;i++)
      adj[i].clear();
    for(i=0;i<n-1;i++){
     cin>>x>>y;
     adj[x].push_back(y);
     adj[y].push_back(x);
     }
  result=0;
  check_index=0;
  dfs(0,0);
  result=0;
  //cout<<"->"<<check_index<<endl;
  dfs(check_index,0);
  cout<<(result+1)/2<<endl;
}
return 0;
}
