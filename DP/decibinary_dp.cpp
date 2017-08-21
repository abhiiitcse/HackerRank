#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long int ll;
ll dp[25][300005];
ll nm[300005];

ll cnt(int d, int s){
  if(d==-1 && s==0){
    return 1;
  }else if(d==-1){
    return 0;
  }else if(s<0){
    return 0;
  }else if(dp[d][s]==-1){
    dp[d][s] = 0;
    for(int i=0;i<=9 && (1<<d)*i<=s;i++){
      dp[d][s] += cnt(d-1,s-((1<<d)*i));
    }
  }
  return dp[d][s];
}

int main(){
  FOR(i,0,25){
    FOR(j,0,300005){
      dp[i][j] = -1;
    }
  }
  FOR(i,0,300005){
    nm[i] = cnt(24,i);
  }
  FOR(i,1,300005){
    nm[i] += nm[i-1];
  }
  int q,l0,hi,ans;
  ll x;
  cin>>q;
  while(q--){
    cin>>x;
    if(x==1)
      cout<<0<<endl;
    else{
      l0 = 0;
      hi = 300004;
      while(l0<=hi){
	int mid = (l0+hi)/2;
	if(nm[mid] >= x){
	  ans=mid;
	  hi = mid-1;
	}else{
	  l0 = mid+1;
	}
      }
      ll g = x-nm[ans-1];
      ll s = ans;
      ll val;
      int d;
      for(int i=-1;cnt(i,s)<g;i++){
	d = i;
      }
      d++;
      while(d>=0){
	val = 0;
	for(int i=0;i<=9;i++){
	  if((s-(1<<d)*i)>=0){
	    val += cnt(d-1,s-(1<<d)*i);
	  }
	  if(val >=g){
	    cout<<i;
	    g -= val-cnt(d-1,s-(1<<d)*i);
	    s -= (1 << d)*i;
	    break;
	  }
	}
	d--;
      }
      cout<<endl;
    }
  }
  return 0;
}
