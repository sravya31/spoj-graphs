#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>PII;
vector<PII> adj[1000005];
bool visited[1000005]={false};
int result = 0, check_index = 0;

void DFS(int node, int dis)
{
	if(result<dis)
	{
			result = dis; 
            check_index = node;
	}
	visited[node] = 1;
	for(int i=0; i<adj[node].size(); i++)
	{
		if(visited[adj[node][i].second]==0)
			DFS(adj[node][i].second, dis+adj[node][i].first);
	}
	visited[node] = 0;	
}

int main(){
  int t,n,i,x,y,w,j;
   cin>>t;
   int ans=-1;
    while(t--){
      int n;
      cin>>n;
     for(i=0;i<=1000005;i++)
       adj[i].clear();
       for(i=1;i<=n-1;i++){
         cin>>x>>y>>w;
         adj[x].push_back(make_pair(w,y));
         adj[y].push_back(make_pair(w,x));
         }
        result = 0; check_index = 0;
		DFS(1,0);
       // cout<<check_index;
		result = 0;
		DFS(check_index, 0);
		printf("%d\n", result);
   }
return 0;
}

