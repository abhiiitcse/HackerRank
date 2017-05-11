#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
using namespace std;

const int INF = 1000000000;
const int MAX_NODES = 1000+10;
const int MAX_MASK = 1024 + 10;

int dist[MAX_NODES][MAX_MASK],n,m,k,a[MAX_NODES],cti,x,y,z;
set<pair<int, pair<int,int> > > s;
vector<pair<int,int> >adj[MAX_NODES];
bool occurs[MAX_NODES];

inline void push(int vn,int vm,int vv){
  if(dist[vn][vm] <= vv){
    return;
  }
  pair<int, pair<int,int> > mpi = mp(dist[vn][vm],mp(vn,vm));
  if(s.find(mpi)!=s.end()){
    s.erase(s.find(mpi));
    dist[vn][vm] = vv;
    mpi.first = vv;
    s.insert(mpi);
  }
}
    
int main(){
  cin>>n>>m>>k;
  FOR(i,1,n){
    a[i] = 0;
    cin>>cti;
    FOR(j,1,cti){
      cin>>x;
      a[i] = (a[i] | (1<<(x-1)));
    }
  }
  set<pair<int,int> >edges;
  FOR(i,1,m){
    cin>>x>>y>>z;
    edges.insert(mp(min(x,y),max(x,y)));
    adj[x].pb(mp(y,z));
    adj[y].pb(mp(x,z));
  }
  FOR(i,1,n){
    FOR(j,0,(1<<k)-1){
      dist[i][j] = INF;
    }
  }
  push(1,a[1],0);
  while(!s.empty()){
    int vn = s.begin()->second.first;
    int vm = s.begin()->second.second;
    int vv = s.begin()->first;
    occurs[vn] = true;
    s.erase(s.begin());
    FOR(i,0,adj[vn].size()-1){
      push(adj[vn][i].first, vm | a[adj[vn][i].first], dist[vn][vm] + adj[vn][i].second);
    }
  }
  int ret = INF;
  FOR(i,0,(1<<k)-1){
    FOR(j,i,(1<<k)-1){
      if((i|j)==(1<<k)-1){
	ret = min(ret,max(dist[n][i],dist[n][j]));
      }
    }
  }
  cout<<ret<<endl;
  
  return 0;
}
