#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll powmod(ll val, ll powval){
  ll result = 1;
  while(powval){
    if((powval%2)!=0){
      result = (result*val)%MOD;
    }
    val = (val*val)%MOD;
    powval /= 2;
  }
  return result;
}
      
int main(){
  const int max_index = 100010;
  ll fact[max_index],inv_fact[max_index];
  fact[0] = 1;
  inv_fact[0] = 1;
  FOR(i,1,max_index-1){
    fact[i] = (i*(fact[i-1]))%MOD;
    inv_fact[i] = powmod(fact[i],MOD-2);
  }
  int n,k;
  cin>>n>>k;
  vll vec;
  vec.pb(-1);
  FOR(i,1,n){
    ll val;
    cin>>val;
    vec.pb(val);
  }
  ll result = 0;
  if(k<=1){
    result = 0;
  }else{
    FOR(i,k,n){
      ll denom = (inv_fact[k-1]*inv_fact[i-k])%MOD;
      ll numer = (fact[i-1] * denom)%MOD;
      result += ((numer*vec[i])%MOD);
    }
    FOR(i,1,n-k+1){
      ll denom = (inv_fact[k-1]*inv_fact[n-k-i+1])%MOD;
      ll numer = (fact[n-i] * denom)%MOD;
      result -= ((numer*vec[i])%MOD);
    }
  }
  cout<<result<<endl;
  return 0;
}
