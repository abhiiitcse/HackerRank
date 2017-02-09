#include <iostream>
#include <vector>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
int find(vi &ppl, int id){
  if(id == ppl[id]){
    return id;
  }
  else{
    ppl[id] = find(ppl,ppl[id]);
  }
  return ppl[id];
}

void union1(vi &ppl, vi &pplsize, vi &pplrank, int src, int dest){
  int first_parent = find(ppl,src);
  int second_parent = find(ppl,dest);
  if(first_parent!=second_parent){
    if(pplrank[first_parent] > pplrank[second_parent]){
      ppl[second_parent] = first_parent;
      pplsize[first_parent] += pplsize[second_parent];
    }else{
      ppl[first_parent] = second_parent;
      pplsize[second_parent] += pplsize[first_parent];
      if(pplrank[first_parent] == pplrank[second_parent]){
          pplrank[second_parent] += 1;
      }
    }
  }
}

int get_size(vi &ppl, vi &pplsize, int person){
  int sz;
  int parent = find(ppl,person);
  return pplsize[parent];
}

int main(){
  int n,q;
  cin>>n>>q;
  vi people(n);
  vi ppsize(n);
  vi pplrank(n);
  FOR(i,0,n-1){
    people[i] = i;
    ppsize[i] = 1;
    pplrank[i] = 0;
  }
  //FOR(i,0,n-1){
  //cout<<people[i]<<" ";
  //  }
  //  cout<<endl;
  
  cin.clear();
  FOR(i,0,q-1){
    char oper;
    cin>>oper;
    if(oper=='Q'){
      int val;
      cin>>val;
      int ret_val = get_size(people,ppsize,val-1);
      cout<<ret_val<<endl;
    }else{
      int src,dest;
      cin>>src>>dest;
      union1(people,ppsize,pplrank,src-1,dest-1);
      //      FOR(j,0,n-1){
      //	cout<<people[j]<<" ";
      //      }
      //      cout<<endl;
    }
  }
  return 0;
}

