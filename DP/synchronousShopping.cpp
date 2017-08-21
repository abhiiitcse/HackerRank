#include <bits/stdc++.h>
#define MAX_MASK 1024
#define MAX_N 1010
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define INF 1000000000
using namespace std;

vector<pair<int,int> > adj[MAX_N];
int mask[MAX_N];
int dp[MAX_N][MAX_MASK];

int main(){
  ios::sync_with_stdio(false);
  int n,m,k;
  cin>>n>>m>>k;
  FOR(i,1,n+1){
    int t;
    cin>>t;
    FOR(j,0,t){
      int msk;
      cin>>msk;
      msk--;
      mask[i] |= (1<<msk);
    }
  }
  FOR(i,0,m){
    int x,y,w;
    cin>>x>>y>>w;
    adj[x].pb(mp(y,w));
    adj[y].pb(mp(x,w));
  }
  FOR(i,1,n+1){
    FOR(j,0,MAX_MASK){
      dp[i][j] = INF;
    }
  }
  dp[1][mask[1]] = 0;
  set<pair<int,pair<int,int> > > s;
  s.insert(mp(0,mp(1,mask[1])));
  while(!s.empty()){
    pair<int,pair<int,int> > node = *s.begin();
    s.erase(*s.begin());
    int currDist = node.first;
    int currNode = node.second.first;
    int currMask = node.second.second;
    FOR(i,0,adj[currNode].size()){
      int destNode = adj[currNode][i].first;
      int destCost = adj[currNode][i].second;
      int destMask = mask[destNode] | currMask;
      if(dp[destNode][destMask] > (currDist + destCost)){
	s.erase(mp(dp[destNode][destMask],mp(destNode,destMask)));
	dp[destNode][destMask] = currDist + destCost;
	s.insert(mp(dp[destNode][destMask],mp(destNode,destMask)));
      }
    }
  }
  int ans = INF;
  FOR(i,0,(1<<k)){
    FOR(j,0,(1<<k)){
      if((i|j)==((1<<k)-1)){
	ans = min(ans,max(dp[n][i],dp[n][j]));
	//cout<<"yes";
      }
    }
  }
  cout<<ans<<endl;

  
  return 0;
}
