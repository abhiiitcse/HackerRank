#include <bits/stdc++.h>
#define MAXN 50001
#define MOD 1009
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

vector<int> adj[1000000];
vector<int> a(1000000,0);
vector<int> adj1[1000000];
int dp[MAXN][MOD];
int n;

bool over[MAXN][MOD];

bool isLeafNode(int n,int k){
  FOR(i,0,adj1[n].size()){
    //if(!over[adj1[i][k]){
      return false;
      //}
  }
  return true;
}

int dfs(int n, int k){
  if(over[n][k]){
    return dp[n][k];
  }else{
    over[n][k] = true;
    int maxval = a[n]^k;
    FOR(i,0,adj1[n].size()){
      if(!over[adj1[n][i]][k]){
	maxval = max(maxval,dfs(adj1[n][i], k));
      }
    }
    return (dp[n][k] = maxval);
  }
}

void precompute(){
  FOR(i
  memset(over,false,sizeof over);
  /*int max_val = INT_MIN;
  bool visited[n+1];
  memset(visited,false,sizeof visited);
  queue<int> q;
  q.push(k);
  visited[k] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    int curr_val = (a[node]^w);
    if(curr_val > max_val){
      max_val = curr_val;
    }
    FOR(i,0,adj1[node].size()){
      if(!visited[adj1[node][i]]){
	visited[adj1[node][i]] = true;
	q.push(adj1[node][i]);
      }
    }
  }
  
  return max_val;*/
}

void divide(int u,int v,int w){
  bool visited[n+1];
  memset(visited,false,sizeof visited);
  int parent[n+1];
  FOR(i,0,n+1)
    parent[i] = -1;
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    if(node==v){
      break;
    }
    FOR(i,0,adj[node].size()){
      if(!visited[adj[node][i]]){
	q.push(adj[node][i]);
	parent[adj[node][i]] = node;
	visited[adj[node][i]] = true;
      }
    }
  }
  int dest = v;
  while(parent[dest]!=-1){
    a[dest] = ceil(((double)(a[dest]))/w);
    dest = parent[dest];
  }
  a[dest] = ceil(((double)(a[dest]))/w);
}

void multiply(int k,int w){
  a[k] = (a[k]*w)%MOD;
  if(a[k]<0){
    a[k] += MOD;
  }
}

int query(int k,int w){
  int max_val = INT_MIN;
  bool visited[n+1];
  memset(visited,false,sizeof visited);
  queue<int> q;
  q.push(k);
  visited[k] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    int curr_val = (a[node]^w);
    if(curr_val > max_val){
      max_val = curr_val;
    }
    FOR(i,0,adj1[node].size()){
      if(!visited[adj1[node][i]]){
	visited[adj1[node][i]] = true;
	q.push(adj1[node][i]);
      }
    }
  }
  
  return max_val;
}


int main(){
  int q;
  cin>>n>>q;
  FOR(i,1,n+1){
    cin>>a[i];
  }
  
  FOR(i,1,n){
    int s,t;
    cin>>s>>t;
    adj[s].push_back(t);
    adj[t].push_back(s);
    adj1[s].push_back(t);
  }
  FOR(i,0,q){
    string s;
    cin>>s;
    if(s[0]=='D'){
      int u,v,w;
      cin>>u>>v>>w;
      divide(u,v,w);
    }else if(s[0] == 'M'){
      int k,w;
      cin>>k>>w;
      multiply(k,w);
    }else if(s[0]=='Q'){
      int k,w;
      cin>>k>>w;
      cout<<query(k,w)<<endl;
    }
  }
  return 0;
  
}

