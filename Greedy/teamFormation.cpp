#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <map>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long int li;
typedef vector<li> vli;
typedef vector<int> vi;



int main(){
  int t;
  cin>>t;
  while(t--){
    map<li,priority_queue<li,vli,greater<int> > > val;
    int n;
    cin>>n;
    vli skills;
    FOR(i,1,n){
      li val;
      cin>>val;
      skills.pb(val);
    }
    sort(skills.begin(),skills.end());
    FOR(i,1,n){
      li temp = skills[i-1];
      int now = 0;
      auto it = val.find(temp-1);
      if(it != val.end()){
	if(it->second.size()){
	  now = it->second.top();
	  it->second.pop();
	}
      }
      now++;
      val[temp].push(now);
    }
    li result = INT_MAX;
    for(auto x:val){
      if(x.second.size()){
	result = min(result,x.second.top());
      }
    }
    if(result >= INT_MAX){
      result = 0;
    }
    cout<<result<<endl;
  }
  return 0;
}
