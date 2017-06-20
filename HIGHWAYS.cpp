#include<bits/stdc++.h>
#define INF 10000000

using namespace std;

typedef pair<long long,int>PII;
vector<PII> adj[1000005];
int dist[1000005];

int dijkstra(int n,int s,int d){
  priority_queue< PII,vector<PII>, greater<PII> > q;
  PII p;
  int i;
  for(i=1;i<=n;i++){
   dist[i]=INF;
  }
  dist[s]=0;
  q.push(make_pair(0,s));
   while(!q.empty()){
     p=q.top();
     q.pop();
     int x=p.second;
     for(i=0;i<adj[x].size();i++){
        if(dist[adj[x][i].second] > dist[x]+adj[x][i].first){
           dist[adj[x][i].second] = dist[x]+adj[x][i].first;
           //cout<<dist[adj[x][i].second]<<endl;
           q.push(make_pair(dist[adj[x][i].second],adj[x][i].second));
          }
         }
       }
   if(dist[d]!=INF){
    cout<<dist[d]<<endl;
   }
  else
   cout<<"NONE"<<endl;
} 
          
int main(){
  int t,n,e,s,d,i,x,y,w;
  cin>>t;
   while(t--){
     cin>>n>>e>>s>>d;
     for(i=0;i<e;i++){
       cin>>x>>y>>w;
       adj[x].push_back(make_pair(w,y));
       adj[y].push_back(make_pair(w,x));
      }
      dijkstra(n,s,d);
  }
return 0;
}
