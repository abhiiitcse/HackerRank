#include <bits/stdc++.h>
using namespace std;
int getWinner(int n,int m){
  if((m==1)||(n%2==0)){
    return 2;
  }else{
    return 1;
  }
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n,m;
    cin>>n>>m;
    cout<<getWinner(n,m)<<endl;
  }
  return 0;
}
