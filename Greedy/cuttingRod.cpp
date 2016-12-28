#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007
using namespace std;
typedef long int li;
typedef pair<li,char> plic;
typedef vector<plic > vplic;
bool compare(plic &a,plic &b){
  return a.first > b.first;
}

int main(){
  int q;
  cin>>q;
  while(q--){
    int m,n;
    cin>>m>>n;
    vplic mnvec;
    FOR(i,1,m-1){
      li inp;
      cin>>inp;
      mnvec.pb(make_pair(inp,'H'));
    }
    FOR(i,1,n-1){
      li inp;
      cin>>inp;
      mnvec.pb(make_pair(inp,'V'));
    }
    sort(mnvec.begin(),mnvec.end(),compare);
    // FOR(i,0,mnvec.size()-1){
    //cout<<mnvec[i].first<<" ";
    //}
    //cout<<endl;
    li H=0,V=0;
    li cost = 0;
    FOR(i,0,mnvec.size()-1){
      if(mnvec[i].second=='H'){
	cost = (cost + (mnvec[i].first*(V+1))%MOD)%MOD;
	H++;
      }else{
	cost = (cost + (mnvec[i].first*(H+1))%MOD)%MOD;
	V++;
      }
    }
    cout<<cost<<endl;
  }
  return 0;
}
