#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define max_val 2000
using namespace std;
unsigned int ncr[max_val][max_val];
int main(){
  int tt;
  unsigned int mod = 1000000000;
  int n,k;
  FOR(i,0,max_val){
    ncr[i][0] = 1;
    ncr[i][i] = 1;
  }
  ncr[0][0] = 1;
  FOR(i,1,max_val){
    FOR(j,1,i){
      ncr[i][j] = ((ncr[i-1][j]%mod) + (ncr[i-1][j-1])%mod)%mod;
    }
  }
  cin>>tt;
  while(tt--){
    cin>>n>>k;
    cout<<ncr[n+k-1][k]<<endl;
  }
  return 0;
}
