#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int graph[101][101];
int min_move;
int find_node(int dist[],bool visited[]){
  int max_dist = 10000;
  int ret_val = -1;
  FOR(i,1,100){
    if(!visited[i]){
      if(dist[i]<max_dist){
	ret_val = i;
	max_dist = dist[i];
      }
    }
  }
  return ret_val;
}
	
      
int dijk(int dest,int dist[],bool visited[]){
  dist[1] = 0;
  while(true){
    int node = find_node(dist,visited);
    if(node==dest){
      return dist[node];
    }
    if(node==-1){
      break;
    }
    visited[node] = true;
    FOR(i,1,100){
      if((!visited[i])&&(graph[node][i])){
	if(graph[node][i]>1){
	  if(dist[i]>dist[node]){
	    dist[i] = dist[node];
	  }
	}else{
	  if(dist[i]>(dist[node]+1)){
	    dist[i] = dist[node]+1;
	  }
	}
      }
    }
  }
  return -1;
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    min_move = 0;
    int dist[101];
    bool visited[101];
    FOR(i,1,100){
      dist[i] = 10000;
      visited[i] = false;
    }
    FOR(i,0,100){
      FOR(j,0,100){
	graph[i][j] = 0;
      }
    }
    FOR(i,1,100){
      FOR(j,1,6){
	if((i+j)<=100)
	  graph[i][i+j] = 1;
      }
    }
    int n;
    cin>>n;
    FOR(i,1,n){
      int src,dest;
      cin>>src>>dest;
      graph[src][dest] = 2;
    }
    int m;
    cin>>m;
    FOR(i,1,m){
      int src,dest;
      cin>>src>>dest;
      graph[src][dest] = 3;
    }
    cout<<dijk(100,dist,visited)<<endl;
    
  }
  return 0;
}
