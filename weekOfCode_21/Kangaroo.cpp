#include <iostream>
using namespace std;
bool ispossible(int x1,int v1, int x2, int v2){
  int a1,a2,d1,d2;
  if(x1>=x2){
    a1 = x1;
    d1 = v1;
    a2 = x2;
    d2 = v2;
  }else{
    a1 = x2;
    d1 = v2;
    a2 = x1;
    d2 = v1;
  }
  int a_diff = a1 - a2;
  int d_diff = d2 - d1;
  if (a_diff == d_diff){
    return true;
  }else if (d_diff <= 0){
    return false;
  }else if ((a_diff % d_diff) == 0){
    return true;
  }else{
    return false;
  }
}

int main(){
  int x1;
  int v1;
  int x2;
  int v2;
  cin >> x1 >> v1 >> x2 >> v2;
  if (ispossible(x1,v1,x2,v2)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
