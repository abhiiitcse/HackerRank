#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAX_N 100005
using namespace std;
typedef long long ll;
ll a[MAX_N];
int main(){
  int n,k;
  cin>>n>>k;
  FOR(i,0,n){
    cin>>a[i];
  }
  sort(a,a+n);
  ll sum[n];
  sum[0] = a[0];
  FOR(i,1,n){
    sum[i] = sum[i-1] + a[i];
  }
  ll t0 = 0;
  ll m = 1-k;
  ll max_err;
  ll res = 0;
  for(int i=0,t=(i+k-1); t<n; i++,t++){
    if(i){
      res += (a[i-1]*(k-1) + a[t]*(k-1));
      res -= ((sum[t-1]-sum[i-1])*2);
      max_err = min(max_err,res);
    }else{
      for(int j=i;j<=t;j++,m+=2){
	res += ((ll)a[j]*m);
      }
      max_err = res;
    }
  }
  cout<<max_err<<endl;
  
  return 0;
}
