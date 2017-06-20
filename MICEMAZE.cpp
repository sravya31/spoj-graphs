#include<bits/stdc++.h>

using namespace std;

typedef pair<long long,int>PII;
vector<PII> adj[1000000];
int dist[1000000];

int dijkstra(int n,int i,int e,int t){
  priority_queue< PII,vector<PII>,greater<PII> >q;
   int j;
   PII p;
   for(j=1;j<=n;j++){
    dist[j]=1000000;
    }
   dist[i]=0;
   q.push(make_pair(0,i));
   while(!q.empty()){
     p=q.top();
     q.pop();
     int x=p.second;
     for(j=0;j<adj[x].size();j++){
       if(dist[adj[x][j].second] > dist[x]+adj[x][j].first){
          dist[adj[x][j].second] = dist[x]+adj[x][j].first;
          q.push(make_pair(dist[adj[x][j].second],adj[x][j].second));
          }
         }
       }
   int l=0;
   
     if(dist[e] <= t)
      l++;
return l;
}
int main(){
  int n,e,t,m,i,x,y,w,cont=0,l;
  cin>>n>>e>>t>>m;
   for(i=0;i<m;i++){
    cin>>x>>y>>w;
    adj[x].push_back(make_pair(w,y));
   }
  for(i=1;i<=n;i++){
   l=dijkstra(n,i,e,t);
   cont+=l;
   }
cout<<cont<<endl;
return 0;
}



