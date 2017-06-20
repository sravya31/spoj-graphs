#include<bits/stdc++.h>

using namespace std;
int dist[1000000];
typedef pair<long long,int>PII;
vector<PII> adj[1000000];

void dijkstra(int first,int second,int n){
 priority_queue< PII,vector<PII>,greater<PII> >q;
  int i;
  PII k;
  for(i=1;i<=n;i++){
   dist[i]=1000000;
  }
  dist[first]=0;
  q.push(make_pair(0,first));
  while(!q.empty()){
    k=q.top();
    q.pop();
   for(i=0;i<adj[k.second].size();i++){
     if(dist[adj[k.second][i].second] > dist[k.second]+adj[k.second][i].first){
       dist[adj[k.second][i].second] = dist[k.second]+adj[k.second][i].first;
       q.push(make_pair(dist[adj[k.second][i].second],adj[k.second][i].second));
       }
     }
  }
 cout<<dist[second]<<endl;
}



int main(){
  int s,i,j,first,second;
 while(s--){
  int n;
  string s[n];
  int p;
  for(i=1;i<=n;i++){
   cin>>s[i];
   cin>>p;
   for(j=1;j<=p;j++){
   int x,y;
   cin>>x>>y;
   adj[i].push_back(make_pair(y,x));
   }
   }
   int a;
   cin>>a;
   pair<string,string> b[a];
   for(i=0;i<a;i++){
   cin>>b[i].first>>b[i].second;
   for(j=1;j<n;j++){
    if(b[i].first == s[j]){
      first=j;
      }
    if(b[i].second == s[j]){
       second=j;
      }
    }
   cout<<first<<second;
   dijkstra(first,second,n);
   }
 }
return 0;
}
   
