#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
ll get_power(ll a,ll b){
  ll result = 1;
  while(b){
    if((b%2)!=0){
      result = (result*a)%100;
    }
    b = b/2;
    a = (a*a)%100;
  }
  return result;
}
      
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    vector<ll> powa(101);
    powa[0] = 0;
    powa[1] = 1;
    ll k,n;
    cin>>k>>n;
    for(ll i = 2;i<101;i++){
      powa[i] = (powa[i-1]+ get_power(i,n))%100;
    }
    ll tot_100_mul = k/100;
    ll result = ((powa[100]*tot_100_mul)%100 + (powa[k%100])%100)%100;
    cout<<setfill('0')<<setw(2);
    cout<<result<<endl;
    
  }
  return 0;
}
    
