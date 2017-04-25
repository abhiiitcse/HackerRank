#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int A[1000001][31];
void fill_A(vll &inp){
  //cout<<"inp="<<inp.size()<<endl;
  FOR(i,0,30){
    A[0][i] = 0;
  }
  FOR(i,1,inp.size()-1){
    FOR(j,0,30){
      if(inp[i]&(1<<j)){
	A[i][j] = A[i-1][j] + 1;
      }else{
	A[i][j] = A[i-1][j];
      }
    }
  }   
}

int main(){
  int n;
  cin>>n;
  vll inp(n+1);
  FOR(i,1,n){
    cin>>inp[i];
  }
  fill_A(inp);
  int m;
  cin>>m;
  while(m--){
    ll k,p,q;
    ll result = 0;
    cin>>k>>p>>q;
    FOR(i,0,30){
      ll o = A[q][i] - A[p-1][i];
      ll z = q-p+1-o;
      ll ones = z*o;
      ll zeros = (z*(z-1) + o*(o-1))/2;
      if((k&(1<<i))==0){
	result = (result + (ones*(1<<i)))%MOD;
      }else{
	result = (result + (zeros*(1<<i)))%MOD;
      }
    }
    cout<<result%MOD<<endl;
  }
  return 0;
}
