#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<int>adj[MAX];
int c;
 
int bfss(int start,int n,int m)
{
 
    int visited[MAX]={0};
    int level[MAX]={0};
    queue<int>q;
    q.push(start);
    visited[start]=1;
    level[start]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
 
        for(int i=0;i<adj[v].size();i++)
        {
 
            if(visited[adj[v][i]]==0)
            {
                visited[adj[v][i]]=1;
                q.push(adj[v][i]);
                level[adj[v][i]]=level[v]+1;
            }
 
        }
       c++;
    }
   // cout<<endl;
    int index=0;
    for(int k=1;k<=(n*m);k++)
    {
    	if(level[k]>index)
    	index=level[k];
    }
    return (index-1);
}
 
int bfs(int start,int n,int m)
{
    int visited[MAX]={0};
    int level[MAX]={0};
    queue<int>q;
    q.push(start);
    visited[start]=1;
    level[start]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        //cout<<v<<"->";
        for(int i=0;i<adj[v].size();i++)
        {
 
            if(visited[adj[v][i]]==0)
            {
                visited[adj[v][i]]=1;
                q.push(adj[v][i]);
                level[adj[v][i]]=level[v]+1;
            }
 
        }
 
    }
    int index=1;
    for(int k=2;k<=(n*m);k++)
    {
    	if(level[k]>level[index])
    	index=k;
    }
    return index;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,m,k;
    cin>>m>>n;
    char mat[n+1][m+1];
    char x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            mat[i][j]=x;
        }
    }
    for(int i=1;i<=MAX;i++)
    adj[i].clear();
 
  /*  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }*/
   k=1;
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
     {
         if(mat[i][j]=='.')
         {
                    if((i+1)<=n && mat[i+1][j]=='.')
	                adj[k].push_back(k+m);
 
	                if((i-1)>=1 && mat[i-1][j]=='.')
	                adj[k].push_back(k-m);
 
	                if((j+1)<=m && mat[i][j+1]=='.')
	                adj[k].push_back(k+1);
 
	                if((j-1)>=1 && mat[i][j-1]=='.')
	                adj[k].push_back(k-1);
         }
         k++;
     }
   }
   for(int i=1;i<=(n*m);i++)
   {
       cout<<"adjacency of "<<i<<" ";
       for(int j=0;j<adj[i].size();j++)
       {
           cout<<adj[i][j]<<" ";
       }
       cout<<endl;
   }
   int l;
   int flag=0;
   for(int i=1;i<=(n*m);i++)
   {
       if(adj[i].size()!=0)
       {
           l=bfs(i,n,m);
           flag=1;
           break;
       }
   }
   if(flag==0)
   cout<<"Maximum rope length is 0."<<endl;
   else{
   int p=bfss(l,n,m);
   cout<<"Maximum rope length is "<<p<<"."<<endl;
   }
    }
   return 0;
}
