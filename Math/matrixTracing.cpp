#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000000
using namespace std;

long long getFermant(long long a,long long b){
  long long retval = 1;
  while(b){
    if (b&1){
      retval = (retval * a)%mod;
    }
    a = ((a%mod)*(a%mod))%mod;
    b =  b>>2;
  }
  return retval;
}

int main(){
  int tt;
  int m,n;
  cin>>tt;
  long long retval = 1;
  while(tt--){
    cin>>m>>n;
    int max_val = max(m,n);
    int min_val = min(m,n);
    FOR(i,max_val,m+n-1){
      retval = (retval*i)%mod;
    }
    long long denominator = 1;
    FOR(i,1,min_val){
      denominator = (denominator*i)%mod;
    }
    retval = (retval * getFermant(denominator,mod-2))%mod;
    cout<<retval<<endl;
  }
  return 0;
}
