#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;

int find(vi &gf, int node){
  if (node == gf[node]){
    return node;
  }else{
    return gf[node] = find(gf,gf[node]);
  }
}

void union1(vi &gf, vi &gfsize, int src, int dest){
  int par_src = find(gf,src);
  int par_dest = find(gf,dest);
  if(par_src != par_dest){
    gf[par_src] = par_dest;
    gfsize[par_dest] += gfsize[par_src];
  }
}

vi getminmax(vi &gf, vi &gfsize){
  int minval,maxval;
  assert(gf.size()>0);
  vi retval;
  FOR(i,0,gf.size()-1){
    retval.pb(gfsize[find(gf,gf[i])]);
  }
  sort(retval.begin(),retval.end());
  FOR(i,0,retval.size()-1){
    if(retval[i]>1){
      minval = retval[i];
      break;
    }
  }
  maxval = retval[retval.size()-1];
  vi ret_val;
  ret_val.pb(minval);
  ret_val.pb(maxval);
  return ret_val;
}
  
  
int main(){
  int n;
  cin>>n;
  vi graph(2*n);
  vi gsize(2*n);
  FOR(i,0,2*n-1){
    graph[i] = i;
    gsize[i] = 1;
  }
  FOR(i,0,n-1){
    int gi,bi;
    cin>>gi>>bi;
    union1(graph,gsize,gi-1,bi-1);
  }
  vi ret_val = getminmax(graph,gsize);
  assert(ret_val.size()==2);
  cout<<ret_val[0]<<" "<<ret_val[1]<<endl;
  return 0;
}
  
