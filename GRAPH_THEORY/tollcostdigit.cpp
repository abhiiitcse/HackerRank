#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#define pb push_back
#define MAX_NODE 100009
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef vector<pair<int,int> > vii;
vii graph[MAX_NODE];
int last_val;
void bfs(int node,long int num[],bool visited[]){
  int dist[MAX_NODE];
  memset(dist,0,sizeof(dist));
  queue<int> q;
  q.push(node);
  dist[node] = 0;
  while(!q.empty()){
    int tv = q.front();
    q.pop();
    visited[tv] = true;
    cout<<"tv="<<tv<<endl;
    FOR(i,0,graph[tv].size()){
      if(!visited[graph[tv][i].first]){
	q.push(graph[tv][i].first);
	num[(graph[tv][i].second+dist[tv])%10]++;
	dist[graph[tv][i].first] = dist[tv] + graph[tv][i].second;
	cout<<"lv = "<<dist[tv]<<"  node = "<<graph[tv][i].first<<endl;
      }
    }
  }
}

int main(){
  long int num[10];
  memset(num,0,sizeof(num));
  int n,e;
  cin>>n>>e;
  int src,dest,weight;
  while(e--){
    cin>>src>>dest>>weight;
    graph[src].push_back(make_pair(dest,weight));
    graph[dest].push_back(make_pair(src,1000-weight));
  }
  bool visited[MAX_NODE];
  FOR(i,1,n+1){
    last_val = 0;
    memset(visited,false,sizeof(visited));
    bfs(i,num,visited);
  }
  FOR(i,0,10){
    cout<<num[i]<<endl;
  }
  
  return 0;
}
