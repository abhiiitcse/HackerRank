#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll f(ll a, ll b){
  ll res = 1;
  for(int i=1;i<=(a+b);i++){
    res *= i;
  }
  for(int i=a;i>0;i--){
    res /= i;
  }
  for(int i=b;i>0;i--){
    res /= i;
  }
  return res;
}

void solve(ll x, ll y, ll k){
  if((x==0)&&(y==0)){
    return;
  }else if(x==0){
    y--;
    cout<<"V";
    solve(x,y,k);
  }else if(y==0){
    x--;
    cout<<"H";
    solve(x,y,k);
  }else{
    if(f(x-1,y)>k){
      cout<<"H";
      solve(x-1,y,k);
    }else{
      cout<<"V";
      solve(x,y-1,k-f(x-1,y));
    }
  }
    
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    ll x,y,k;
    cin>>x>>y>>k;
    solve(x,y,k);
    cout<<endl;
  }
  return 0;
}
    
