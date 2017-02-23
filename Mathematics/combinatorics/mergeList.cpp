#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll get_factorial(int val){
  ll result = 1;
  FOR(i,1,val){
    result = (result*i)%MOD;
  }
  return result;
}

ll powmod(ll val, ll powval){
  ll result = 1;
  while(powval){
    if((powval%2)!=0){
      result = (result*val)%MOD;
    }
    powval = powval/2;
    val = (val*val)%MOD;
  }
  return result;
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n,m;
    cin>>n>>m;
    ll numerator = get_factorial(n+m);
    ll denominator = (get_factorial(n)*get_factorial(m))%MOD;
    ll denom_to_numer = powmod(denominator,MOD-2);
    ll result = (numerator*denom_to_numer)%MOD;
    cout<<result<<endl;
  }
  return 0;
}
