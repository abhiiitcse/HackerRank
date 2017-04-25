#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
vector<int> graph[100001];
void dfs(int node,bool *visited, int &count){
  visited[node] =true;
  count++;
  if(graph[node].size()>0){
    FOR(i,0,graph[node].size()-1){
      if(!visited[graph[node][i]]){
	dfs(graph[node][i],visited,count);
      }
    }
  }
    
}
int main(){
  int N,P;
  map<int,int> freq;
  cin>>N>>P;
  FOR(i,0,P-1){
    int src,dest;
    cin>>src>>dest;
    graph[src].pb(dest);
    graph[dest].pb(src);
  }
  bool visited[N+1];
  FOR(i,0,N){
    visited[i] = false;
  }
  int count=0;
  vector<int> numppl;

  FOR(i,0,N-1){
    if(!visited[i]){
      count = 0;
      dfs(i,visited,count);
      numppl.pb(count);
      if(freq.find(count)!=freq.end()){
	freq[count] += 1;
      }else{
	freq[count] = 1;
      }
    }
  }
  vector<pair<int,int> > map_vec;
  for(map<int,int>::iterator it=freq.begin();it!=freq.end();++it){
    map_vec.pb(make_pair(it->first,it->second));
  }
  long int map_result = 0;
  FOR(i,0,map_vec.size()-1){
    if(map_vec[i].second>1){
      long int x = map_vec[i].first;
      long int y = map_vec[i].second;
      long int yc2 = ((y*(y-1))/2);
      map_result += (x*x*yc2);
    }
    if(i!=(map_vec.size()-1)){
      FOR(j,i+1,map_vec.size()-1){
	map_result += (map_vec[i].first*map_vec[j].first*map_vec[i].second*map_vec[j].second);
      }
    }
  }
  
  cout<<map_result<<endl;
  return 0;
}
