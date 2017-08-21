#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int m1swipe,m2swipe,m3swipe;
  cin>>m1swipe>>m2swipe>>m3swipe;
  int res1 = min(m1swipe*10,100);
  int res2 = min(m2swipe*10,100);
  int res3 = min(m3swipe*10,100);
  int res = res1+res2+res3;
  cout<<res<<endl;
  return 0;
}
