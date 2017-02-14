#include <iostream>
#include <vector>
#include <cassert>
#define NDEBUG
#define MOD 1000000000
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int max_index = 1000;
int main(){
  ll ncrtable[max_index][max_index];
  FOR(i,0,max_index-1){
    FOR(j,0,max_index-1){
      ncrtable[i][j] = 0;
    }
  }
  ncrtable[1][0] = 1;
  ncrtable[1][1] = 1;
  FOR(i,2,max_index-1){
    FOR(j,0,i){
      if(j==0){
	ncrtable[i][j] = 1;
      }else if(j==i){
	ncrtable[i][j] = 1;
      }else{
	ncrtable[i][j] = (ncrtable[i-1][j] + ncrtable[i-1][j-1])%MOD;
      }
    }
  }
  int t;
  cin>>t;
  while(t--){
    int val ;
    cin>>val;
    assert((val>=1) && (val < 1000));
    FOR(i,0,val-1){
      cout<<ncrtable[val][i]<<" ";
    }
    cout<<ncrtable[val][val]<<endl;
  }
  return 0;
}
    
