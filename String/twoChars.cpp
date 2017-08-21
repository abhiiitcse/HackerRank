#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  int len;
  string inp;
  cin>>len;
  cin>>inp;
  map<char,int> count;
  vector<char> dis;
  FOR(i,0,len){
    if(count.find(inp[i])!=count.end()){
      count[inp[i]] += 1;
    }else{
      count[inp[i]] = 1;
      dis.push_back(inp[i]);
    }
  }
  int result = 0;
  FOR(i,0,dis.size()-1){
    FOR(j,i+1,dis.size()){
      string new_str = "";
      FOR(k,0,len){
	if((inp[k]==dis[i])||(inp[k]==dis[j])){
	  new_str += inp[k];
	}
      }
      bool found  = false;
      stack<char> st;
      st.push(new_str[0]);
      int l=1;
      while(l<new_str.length()){
	if(st.top()==new_str[l]){
	  found = true;
	  break;
	}else{
	  st.push(new_str[l]);
	  l++;
	}
      }
      if(!found){
	result = max(result, count[dis[i]]+count[dis[j]]);
      }
    }
  }
  cout<<result<<endl;
  return 0;
}
