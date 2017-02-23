#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll get_count(vector<int> &vec,int n,int k){
  ll result = 0;
  int cnt[100];
  memset(cnt,0,sizeof(cnt));
  int psum = 0;
  cnt[0] = 1;
  FOR(i,0,n-1){
    psum += vec[i];
    if(psum>=k){
      psum %= k;
    }
    cnt[psum] += 1;
  }
  FOR(i,0,k-1){
    result += ((ll)(cnt[i])*(cnt[i]-1))/2;
  }
  return result;
}
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    FOR(i,1,n){
      cin>>vec[i-1];
    }
    ll result = get_count(vec,n,k);
    cout<<result<<endl;
  } 
  return 0;
}
