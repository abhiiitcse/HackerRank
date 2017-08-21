#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAXN 100007
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
vll edge[MAXN];
int n,u,v,g,k,indx;
int st[MAXN],parent[MAXN],accum[MAXN];
int all;

void dfs(int node, int par=-1){
  st[node] = indx++;
  parent[node] = par;
  for(auto x:edge[node]){
    if(x==par) continue;
    dfs(x,node);
  }
}

ll gcd(ll a,ll b){
  ll a1,b1,temp;
  if(a>=b){
    a1 = a;
    b1 = b;
  }else{
    a1 = b;
    b1 = a;
  }
  while(b1!=0){
    temp = a1%b1;
    a1 = b1;
    b1 = temp;
  }
  return a1;
}

void dfs1(int node, int cur, int par=-1){
  accum[node] += cur;
  cur = accum[node];
  for(auto x:edge[node]){
    if(x==par) continue;
    dfs1(x,cur,node);
  }
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    memset(accum,0,sizeof accum);
    cin>>n;
    FOR(i,0,n-1){
      cin>>u>>v;
      edge[u].pb(v);
      edge[v].pb(u);
    }
    indx = 1;
    all = 0;
    dfs(1);
    cin>>g>>k;
    FOR(i,0,g){
      cin>>u>>v;
      if(st[v]>st[u]){
	all++;
	accum[v]--;
      }else{
	accum[u]++;
      }
    }
    dfs1(1,0);
    ll cnt = 0 ;
    FOR(i,1,n+1){
      cnt += ((all+accum[i])>=k);
    }
    ll gg = gcd(n,cnt);
    cout<<(cnt/gg)<<"/"<<(n/gg)<<endl;
  }
  return 0;
}
  
