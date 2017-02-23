#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
pair<ll,int> lcm[200000];
ll get_gcd(ll a,ll b){
  ll a1 = max(a,b);
  ll b1 = min(a,b);
  while(b1){
    ll temp = b1;
    b1 = (a1%b1);
    a1 = temp;
  }
  return a1;
}

ll find_lcm(ll a,ll b){
  ll gcd_val = get_gcd(a,b);
  ll result = (a*b)/gcd_val;
  return result;
}
  
void precompute(ll *a,int n){
  ll limit = (1<<n);
  limit--;
  FOR(i,1,limit){
    lcm[i].second = __builtin_popcount(i);
    ll k = 1;
    ll val = 1;
    for(int j=n-1;j>=0;j--){
      if(k&i){
	val = find_lcm(val,a[j]);
      }
      k <<= 1;
    }
    lcm[i].first = val;
  }
}
int main(){
  int n;
  cin>>n;
  ll a[n];
  FOR(i,0,n-1){
    cin>>a[i];
  }
  ll limit = (1<<n);
  limit--;
  precompute(a,n);
  int d;
  cin>>d;
  while(d--){
    ll L,R,result=0;
    cin>>L>>R;
    L--;
    FOR(i,1,limit){
      if((lcm[i].second%2)==0){
	result -= ((R/lcm[i].first)-(L/lcm[i].first));
      }else{
	result += ((R/lcm[i].first)-(L/lcm[i].first));
      }
    }
    cout<<result<<endl;
  }
    
  return 0;
}
