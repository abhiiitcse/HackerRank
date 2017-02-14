#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll pownk(int n,int k){
  ll result = 0;
  if(k==0){
    result = 1;
  }else if(k==1){
    result = n;
  }else{
    result = 1;
    FOR(i,1,k){
      result = (n * result)%MOD;
    }
  }
  return result;
}

int main(){
  int n;
  int e=0,o=0;
  int val;
  //freopen("input09.txt","r",stdin);
  cin>>n;
  while(n--){
    cin>>val;
    if((val%2)==0){
      e++;
    }else{
      o++;
    }
  }
  ll result = 0;
  if(o==0){
    result = pownk(2,e);
    result -= 1;
  }else if(e==0){
    if(o>1){
      result = pownk(2,o-1);
      result -= 1;
    }
  }else{
    ll s1 = pownk(2,o-1);
    ll s2 = pownk(2,e);
    s2 -= 1;
    result = (s2*s1)%MOD;
    result = (result+s1)%MOD;
    result -= 1;
  }
  cout<<result<<endl;
  return 0;
}
