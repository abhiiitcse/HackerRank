#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <bitset>
#define MAXN 150005
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

vector<int> g[MAXN],gr[MAXN];
vector<pii> edges;
int type[MAXN],from[MAXN],go[MAXN];
bool visited[MAXN];
stack<int> st;
vector<int> ts;
int sz;
bool res[MAXN];
bitset<50005> dp[50005];
int wh[MAXN];

void dfs(int v){
  visited[v] = true;
  for(auto &to : g[v]){
    if(!visited[to]){
      dfs(to);
    }
  }
  ts.pb(v);
  st.push(v);
}

void dfs1(int v){
  visited[v] = true;
  wh[v] = sz;
  for(auto &to : gr[v]){
    if(!visited[to]){
      dfs1(to);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  FOR(i,0,m){
    int src,dest;
    cin>>src>>dest;
    g[src].pb(dest);
    gr[dest].pb(src);
    edges.pb(mp(src,dest));
  }
  int q;
  cin>>q;
  FOR(i,1,q+1){
    cin>>type[i]>>from[i]>>go[i];
    if(type[i]==1){
      n++;
      if(go[i]){
	g[n].pb(from[i]);
	gr[from[i]].pb(n);
	edges.pb(mp(n,from[i]));
      }else{
	g[from[i]].pb(n);
	gr[n].pb(from[i]);
	edges.pb(mp(from[i],n));
      }
    }
  }
  memset(visited,false,sizeof(visited));
  FOR(i,1,n+1){
    if(!visited[i]){
      dfs(i);
    }
  }
  memset(visited,false,sizeof(visited));
  sz=0;
  while(!st.empty()){
    int cnode = st.top();
    st.pop();
    if(!visited[cnode]){
      sz++;
      dfs1(cnode);
    }
  }
  FOR(i,1,n+1){
    g[i].clear();
  }
  for(auto &to : edges){
    if(wh[to.first]!=wh[to.second]){
      g[wh[to.first]].pb(wh[to.second]);
    }
  }
  memset(visited,false,sizeof(visited));
  FOR(i,1,sz+1){
    if(!visited[i]){
      dfs(i);
    }
  }
  for(auto cnode : ts){
    dp[cnode].set(cnode,1);
    for(auto &it : g[cnode]){
      dp[cnode] |= dp[it];
    }
  }

  for(int i=q;i>=1;i--){
    if(type[i]==1){
      n--;
    }else{
      if(go[i]>n || from[i]>n)
	continue;
      res[i] = dp[wh[from[i]]].test(wh[go[i]]);
    }
  }
  FOR(i,1,q+1){
    if(type[i]==1)
      continue;
    if(res[i])
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
    
  return 0;
}
