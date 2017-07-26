#include <iostream>
#include <list>
 
using namespace std;
 
class Graph
{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isReachable(int s, int d);
};
 
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int> [V];
}
 
void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}
bool Graph::isReachable(int s, int d)
{
  if (s == d)
    return true;
 
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
 
  list<int> queue;
 
  visited[s] = true;
  queue.push_back(s);
 
  list<int>::iterator i;
 
  while (!queue.empty()){
    s = queue.front();
    queue.pop_front();
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
      {
	if (*i == d)
	  return true;
 
	if (!visited[*i])
	  {
	    visited[*i] = true;
	    queue.push_back(*i);
	  }
      }
  }
 
  return false;
}
 
int main()
{
  Graph g(1000005);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int src,dest;
    cin>>src>>dest;
    g.addEdge(src,dest);
  }
  int q;
  cin>>q;
  while(q--){
    int eventno,a,b;
    cin>>eventno>>a>>b;
    if(eventno==1){
      n = n+1;
      if(b==0){
	g.addEdge(a,n);
      }else{
	g.addEdge(n,a);
      }
    }else{
      if(g.isReachable(a,b)){
	cout<<"Yes"<<endl;
      }else{
	cout<<"No"<<endl;
      }
    }
  } 
  return 0;
}
