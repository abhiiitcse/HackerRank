#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main(){
  int tt;
  long long mod = 1000000000;
  long long ncr[1000][1000];
  int n;
  FOR(i,0,1000){
    ncr[i][0] = 1;
    ncr[i][i] = 1;
  }
  ncr[0][0] = 1;
  FOR(i,1,1000){
    FOR(j,1,i){
      ncr[i][j] = ((ncr[i-1][j]%mod) + (ncr[i-1][j-1])%mod)%mod;
    }
  }
  cin>>tt;
  while(tt--){
    cin>>n;
    FOR(i,0,n+1){
      cout<<ncr[n][i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
