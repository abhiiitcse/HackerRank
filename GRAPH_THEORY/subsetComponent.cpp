#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#define FOR(i,a,b) for(unsigned long int i=a;i<=b;i++)
using namespace std;
long int find(unsigned long int a,unsigned long int par[]){
  if(par[a]!=a){
    par[a] = find(par[a],par);
  }
  return par[a];
}

void union1(int a,int b,unsigned long int par[]){
  int c = find(a,par);
  int d = find(b,par);
  if(c==d){
    return;
  }
  if(c<d){
    par[d] = c;
  }else{
    par[c] = d;
  }
}

int get_num_class(unsigned long int par[],int len){
  map<unsigned long int,bool> mp;
  int count = 0;
  FOR(i,0,len-1){
    if(mp.find(par[i])!=mp.end()){
      mp[par[i]] = true;
    }
    else{
      mp[par[i]] = true;
      count++;
    }
  }
  return count;
}
    
  
int main(){
  int n;
  cin>>n;
  unsigned long int d[n];
  FOR(i,0,n-1){
    cin>>d[i];
  }
  unsigned long int max_element = pow(2,n);
  unsigned long int result = 0;
  //cout<<"max_element = "<<max_element<<endl;
  FOR(i,0,max_element-1){
    bool found = false;
    unsigned long int parent[64];
    FOR(k,0,63){
      parent[k] = k;
    }
    unsigned long int a,b;
    FOR(j,0,19){
      unsigned long int shifted_j = 1;
      shifted_j = (shifted_j<<j);
      if(i&shifted_j){
	unsigned long int val = d[j];
	found = false;
	FOR(k,0,63){
	  unsigned long int shifted_k = 1;
	  shifted_k = (shifted_k<<k);
	  if(shifted_k>val){
	    break;
	  }
	  if(val&shifted_k){
	    if(!found){
	      a = k;
	      found = true;
	    }else{
	      b = k;
	      union1(a,b,parent);
	    }
	  }
	}
      }
    }
    result += get_num_class(parent,64);
  }
  cout<<result<<endl;
  return 0;
}
