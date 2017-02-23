#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
  int t;
  cin>>t;
  while(t--){
    ll n;
    ll k;
    cin>>n;
    cin>>k;
    vll inp(n);
    FOR(i,0,n-1){
      cin>>inp[i];
    }
    int last_biggest = -1;
    ll result = 0;
    FOR(idx,0,n-1){
      if(inp[idx]>k){
	result += (idx-last_biggest)*(n-idx);
	last_biggest = idx;
      }
    }
    cout<<result<<endl;
  }
  return 0;
}
    
