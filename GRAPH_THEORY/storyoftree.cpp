#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAXN 100007
using namespace std;
typedef vector<int> vi;
vi edge[MAXN];
int parent[MAXN],indx;
int st[MAXN],ed[MAXN];
int csum[MAXN];

void dfs(int node,int par=-1){
  parent[node] = par;
  indx++;
  st[node] = indx;
  for(auto x: edge[node]){
    if(x==par)
      continue;
    dfs(x,node);
  }
  ed[node] = indx;
}
  

int main(){
  int tt;
  int u,v,q,k;
  cin>>tt;
  while(tt--){
    memset(csum,0,sizeof csum);
    indx=0;
    int n;
    cin>>n;
    FOR(i,0,n-1){
      cin>>u>>v;
      edge[u].pb(v);
      edge[v].pb(u);
    }
    int root = 1;
    dfs(root);
    FOR(i,1,n+1){
      cout<<st[i]<<" ";
    }
    cout<<endl;
    FOR(i,1,n+1){
      cout<<ed[i]<<" ";
    }
    cout<<endl;
    
    cin>>q>>k;
    FOR(i,0,q){
      cin>>u>>v;
    }
  }
  return 0;
}
