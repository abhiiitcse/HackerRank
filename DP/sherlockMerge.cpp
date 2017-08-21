#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define MAXN 1205

int m[MAXN];
int dp[MAXN][MAXN];
bool dp1[MAXN][MAXN];

using namespace std;

int rec(int i,int j){
  if(j>i+1) return dp[i][j] = 0;
  if(j==i+1) return dp1[0][i];
  int &ret = dp[i][j];
  ret = 0;
  for(int k=j;k<=i-j+1;k++){
    if(dp1[i-j+1][i]){
      ret += 
}

int main(){
  int n;
  cin>>n;
  FOR(i,0,n){
    cin>>m[i];
  }
  FOR(i,0,n){
    FOR(j,0,n){
      dp[i][j] = -1;
      dp1[i][j] = false;
    }
  }
  FOR(i,0,n){
    bool f1=true;
    FOR(j,i,n){
      dp1[i][j] = f1;
      if((j<(n-1))&&(m[j]>m[j+1])){
	f1=false;
      }
    }
  }
  FOR(i,0,n){
    FOR(j,0,n){
      cout<<dp1[i][j]<<" ";
    }
    cout<<endl;
  }
  int ans=0;
  FOR(i,1,n+1){
    ans += rec(n-1,i);
  }
  cout<<ans<<endl;
  
  return 0;
}
