#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll numWays(vi vec){
  int sz = vec.size();
  sort(vec.begin(),vec.end());
  ll result = 1;
  FOR(i,1,sz){
    int diff = i - vec[i-1];
    if(diff<0){
      diff = 0;
    }
    result = (result*diff)%MOD;
  }
  return result;
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    vi cost(n);
    FOR(i,0,n-1){
      cin>>cost[i];
    }
    ll output = numWays(cost);
    cout<<output<<endl;
  }
  return 0;
}
