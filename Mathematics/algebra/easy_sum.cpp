#include <iostream>
using namespace std;
typedef long long ll;
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    ll n,m;
    cin>>n>>m;
    ll num = n/m;
    ll sum = num*(m*(m-1))/2;
    ll rest = n - (num*m);
    ll rest_sum = (rest*(rest+1))/2;
    ll result = sum + rest_sum;
    cout<<result<<endl;
  }
  return 0;
}
