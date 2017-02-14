#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int getDayNum(ll day_num){
  int result = 0;
  return result;
}
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    ll day_num;
    cin>>day_num;
    string result = getDayNum(day_num)==1?"even":"odd";
    cout<<result<<endl;
  }
  return 0;
}
