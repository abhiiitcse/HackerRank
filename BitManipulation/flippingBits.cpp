#include <iostream>
#include <vector>
using namespace std;
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    unsigned int n;
    cin>>n;
    unsigned int result = (~n);
    cout<<result<<endl;
  }
  return 0;
}
