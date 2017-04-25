#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> arra(n);
  vector<ll> arrb(m);
  vector<ll> arrc(m);
  for(int i=0;i<n;i++){
    cin>>arra[i];
  }
  for(int i=0;i<m;i++){
    cin>>arrb[i];
  }
  for(int i=0;i<m;i++){
    cin>>arrc[i];
  }

  for(int i=1;i<=m;i++){
    for(int j=arrb[i-1];j<=n;j+=arrb[i-1]){
      arra[j-1] = (arra[j-1]*arrc[i-1])%MOD;
    }
  }
  for(int i=1;i<=n;i++){
    cout<<arra[i-1]<<" ";
  }
  cout<<endl;
      
      
  
  return 0;
}
