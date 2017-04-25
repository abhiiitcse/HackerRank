#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll ncr[1002][1002];
void fill_ncr(void){
  FOR(i,0,1001){
    FOR(j,0,i){
      if(i==j){
	ncr[i][j] = 1;
      }else if(j==0){
	ncr[i][j] = 1;
      }else{
	ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%MOD;
      }
    }
  }
}

ll get_pow(ll a,ll b){
  ll result = 1;
  while(b){
    if((b%2)!=0){
      result = (result*a)%MOD;
    }
    b = b/2;
    a = (a*a)%MOD;
  }
  return (result%MOD);
}

int main(){
  fill_ncr();
  ll t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    n = (n%MOD);
    ll result;
    ll s[1001];
    FOR(i,0,k){
      ll first_term = get_pow(n+1,i+1);
      ll second_term = 0;
      if(i>0){
	FOR(j,0,i-1){
	  second_term = (second_term + (ncr[i+1][j]*s[j])%MOD)%MOD;
	}
      }
      result = ((first_term - second_term - 1)/(i+1));
      s[i] = result;
    }
    cout<<result<<endl;
  }
  return 0;
}
      
