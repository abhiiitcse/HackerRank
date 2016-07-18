#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

string convert_to_binary(int x){
  string retval;
  while(x){
    retval+=to_string(x%2);
    x =  x>>1;
  }
  reverse(retval.begin(),retval.end());
  return retval;
}

int main(){
  int tt;
  int N;
  map<int,string> found;
  cin>>tt;
  
  while(tt--){
    cin>>N;
    int x = 1;
    cout<<N<<endl;
    bool fi = false;
    while(!fi){
      if(found.find(N) != found.end()){
	cout<<found[N]<<endl;
	fi = true;
      }else{
	string retval = convert_to_binary(x);
	FOR(i,0,retval.length()){
	  if(retval[i] == '1'){
	    retval[i] = '9';
	  }
	}
	int remainder;
	
	if(((stol(retval.c_str())) % N) == 0){
	  cout<<retval<<endl;
	  fi = true;
	}
	x += 1;
      }
    }
  }
  
  return 0;
}
