#include<bits/stdc++.h>

using namespace std;
typedef pair<long long,int>PII;
vector<PII> adj1[1000005];
vector<PII> adj2[1000005];
int dist1[1000005],dist2[1000005];
 priority_queue< PII,vector<PII>,greater<PII> > q;
 PII p;

int main(){
int t,x,y,w,n,m,i;
cin>>t;
  while(t--){
  long long int ans=0;
   cin>>n>>m;
  for(i=0;i<m;i++){
   adj1[i].clear();
   adj2[i].clear();
   }
   for(i=0;i<m;i++){
    scanf("%d %d %d",&x,&y,&w);
    adj1[x].push_back(make_pair(w,y));
    adj2[y].push_back(make_pair(w,x));
    }
     for(i=1;i<=n;i++)
  dist1[i]=1000005;
  dist1[1]=0;
 q.push(make_pair(0,1));
 while(!q.empty()){
   p=q.top();
   q.pop();
  int x=p.second;
   for(i=0;i<adj1[x].size();i++){
     if(dist1[adj1[x][i].second] > dist1[x]+adj1[x][i].first){
        dist1[adj1[x][i].second] = dist1[x]+adj1[x][i].first;
        q.push(make_pair(dist1[adj1[x][i].second],adj1[x][i].second));
       }
    }
  }
  for(i=1;i<=n;i++)
  dist2[i]=1000005;
  dist2[1]=0;
 q.push(make_pair(0,1));
 while(!q.empty()){
   p=q.top();
   q.pop();
  int x=p.second;
   for(i=0;i<adj2[x].size();i++){
     if(dist2[adj2[x][i].second] > dist2[x]+adj2[x][i].first){
        dist2[adj2[x][i].second] = dist2[x]+adj2[x][i].first;
        q.push(make_pair(dist2[adj2[x][i].second],adj2[x][i].second));
       }
    }
  }
  for(i=1;i<=n;i++){
   ans+=(dist1[i]+dist2[i]);
   }
  printf("%lld\n",ans);
}
return 0;
}
