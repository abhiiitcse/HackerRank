#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAX_N 100005
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
int w[MAX_N];
vector<int> graph[MAX_N];
bool visited[MAX_N];

vector<int> dfs(int src,int n){
  vector<int> result(n+1);
  FOR(i,1,n+1){
    result[i] = -1;
  }
  stack<pii > st;
  st.push(mp(src,0));
  visited[src] = true;
  while(!st.empty()){
    pii node_pair = st.top();
    st.pop();
    int node = node_pair.first;
    int dist = node_pair.second;
    result[node] = dist;
    FOR(i,0,graph[node].size()){
      if(!visited[graph[node][i]]){
	visited[graph[node][i]] = true;
	st.push(mp(graph[node][i],dist+1));
      }
    }
  }
  /*cout<<"distance="<<endl;
    FOR(i,1,n+1){
    cout<<result[i]<<" ";
    }
    cout<<endl;*/
  
  return result;
}

vector<pii> get_all_nodes(pii node,bool *localvisit){
  vector<pii> ret_val;
  while(true){
    int cnt=0;
    FOR(i,0,graph[node.first].size()){
      if(!localvisit[graph[node.first][i]]){
	cnt++;
	localvisit[graph[node.first][i]] = true;
	node = mp(graph[node.first][i],node.second+1);
	ret_val.push_back(node);
	break;
      }
    }
    if(cnt==0){
      break;
    }
  }
  return ret_val;
}

vector<int> dfs_new(int src,int n){
  vector<int> result(n+1);
  FOR(i,1,n+1){
    result[i] = 0;
  }
  bool found = true;
  int curr_node;
  while(found){
    found = false;
    FOR(i,1,n+1){
      if(!visited[i]){
	visited[i] = true;
	curr_node = i;
	found = true;
	break;
      }
    }
    if(!found)
      break;
    bool local_visit[n+1];
    FOR(i,1,n+1){
      if(i<=curr_node){
	local_visit[i] = true;
      }else{
	local_visit[i] = false;
      }
    }
    vector<vector<pii> >vec;
    local_visit[curr_node] = true;
    cout<<"for node="<<curr_node<<endl;
    while(true){
      vector<pii> new_path = get_all_nodes(mp(curr_node,0),local_visit);
      if(new_path.size()==0){
	break;
      }else{
	cout<<"returned val="<<endl;
	FOR(i,0,new_path.size()){
	  cout<<new_path[i].first<<" ";
	}
	cout<<endl;
	FOR(i,0,new_path.size()){
	  result[src] += w[new_path[i].second];
	  result[new_path[i].first] += w[new_path[i].second];
	}
      }
      if(vec.size()>0){
	FOR(k,0,new_path.size()){
	  FOR(i,0,vec.size()){
	    FOR(j,0,vec[i].size()){
	      result[vec[i][j].first] += w[new_path[k].second+vec[i][j].second];
	      result[new_path[k].first] += w[new_path[k].second+vec[i][j].second];
	    }
	  }
	}
	vec.push_back(new_path);
      }
    }
  }

  return result;
}



int main(){
  int a,b;
  FOR(i,0,MAX_N){
    FOR(j,0,MAX_N){
      a=i;
      b=j;
    }
  }
  vector<bool> vec_bool(MAX_N);
  vector<vector<bool> > vec;
  FOR(i,0,1){
    vec.push_back(vec_bool);
  }
  cout<<"completed"<<endl;
  int n;
  cin>>n;
  FOR(i,0,n){
    int wi;
    cin>>wi;
    w[i] = wi;
  }
  
  FOR(i,1,n){
    int src,dest;
    cin>>src>>dest;
    graph[src].push_back(dest);
    graph[dest].push_back(src);
  }
  int curr_src = 1;
  int result[n+1];
  FOR(i,0,n+1){
    result[i] = 0;
    visited[i] = false;
  }
  cout<<"testing started"<<endl;
  vector<int> test = dfs_new(curr_src,n);
  FOR(i,1,n+1){
    cout<<test[i]<<" ";
  }
  cout<<endl;
  int inp;
  cin>>inp;

  if(false)
    while(curr_src<=n){
      FOR(i,1,n+1){
	visited[i] = false;
      }
    
      //cout<<"curr_src = "<<curr_src<<endl;
      vector<int> result_in_dist = dfs(curr_src,n);
    
      FOR(i,curr_src,n+1){
	if(result_in_dist[i]!=-1){
	  result[curr_src] += w[result_in_dist[i]];
	  result[i] += w[result_in_dist[i]];
	}
      }
      /*cout<<"res="<<endl;
	FOR(i,1,n+1){
	cout<<result[i]<<" ";
	}
	cout<<endl;*/
      vector<int> test = dfs_new(curr_src,n);
      FOR(i,1,n+1){
	cout<<test[i]<<" ";
      }
      cout<<endl;
      int inp;
      cin>>inp;
      
      curr_src++;
    }
  FOR(i,1,n+1){
    cout<<result[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}
