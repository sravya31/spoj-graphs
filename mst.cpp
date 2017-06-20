#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, int> PII;
vector <PII> adj[1000005];
long long  minimumcost;
bool visited[1000005];

long long  prim(int x){
  priority_queue<PII, vector<PII>, greater<PII> > q;
  int y;
  long long minimumcost=0;
    q.push(make_pair(0,x));
    PII p;
      while(!q.empty()){
         p=q.top();
         q.pop();
         x=p.second;
         if(visited[x]==true)
          continue;
         else{
          visited[x]=true;
          minimumcost+=p.first;
          for(int i=0;i<adj[x].size();i++){
                 y=adj[x][i].second;
                 if(visited[y] == false)
                   q.push(adj[x][i]);
                }
           }
       }
return minimumcost;
}
int main(){
int n,i,e,x,y,w;
long long l;
cin>>n>>e;
 for(i=0;i<e;i++){
   cin>>x>>y>>w;
   adj[x].push_back(make_pair(w,y));
   adj[y].push_back(make_pair(w,x));
  }
  l=prim(1);
  cout<<l<<endl;
return 0;
}
