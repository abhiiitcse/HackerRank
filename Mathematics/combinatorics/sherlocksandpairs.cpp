#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef map<int,ll> mpill;
int main(){
  mpill numCount;
  mpill::iterator it;
  int tt;
  cin>>tt;
  while(tt--){
    numCount.clear();
    int n;
    cin>>n;
    FOR(i,0,n-1){
      int val;
      cin>>val;
      if(numCount.find(val)!=numCount.end()){
	numCount[val] += 1;
      }else{
	numCount.insert(make_pair(val,1));
      }
    }
    ll result = 0;
    for(it=numCount.begin();it!=numCount.end();++it){
      if(it->second > 1){
	result += ((it->second)*(it->second-1));
      }
    }
    cout<<result<<endl;
  }
  return  0;
}
  
