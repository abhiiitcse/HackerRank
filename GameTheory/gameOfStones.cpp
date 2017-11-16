#include <bits/stdc++.h>
using namespace std;
int dp[105];
bool getWinner(int n){
  if(n<0){
    return true;
  }
  if(n==0){
    return false;
  }
  if(dp[n] != -1){
    return dp[n];
  }
  if((!getWinner(n-2)) || (!getWinner(n-3)) || (!getWinner(n-5))){
    return dp[n] = 1;
  }
  return dp[n] = 0;
}

int main(){
  memset(dp,-1,sizeof dp);
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    int winner = getWinner(n);
    if(winner){
      cout<<"First"<<endl;
    }else{
      cout<<"Second"<<endl;
    }
  }
  return 0;
}
