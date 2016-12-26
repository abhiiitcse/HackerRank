#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef vector<string> vs;
bool isRearrangePossible(vs inp_vec){
  int len = inp_vec.size();
  FOR(i,0,len-1){
    sort(inp_vec[i].begin(),inp_vec[i].end());
  }
  FOR(i,1,len-1){
    FOR(j,0,len-1){
      if(inp_vec[i][j] < inp_vec[i-1][j]){
	return false;
      }
    }
  }
      
  return true;
}
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int N;
    cin>>N;
    vs input;
    string str;
    FOR(i,1,N){
      cin>>str;
      input.pb(str);
    }
    if(isRearrangePossible(input)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
