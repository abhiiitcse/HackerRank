#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    long int val;
    cin>>val;
    long int count=0;
    int pos = 0;
    while(val){
      if((val%2)==0){
	count += pow(2,pos);
      }
      val = val>>1;
      pos++;
    }
    cout<<count<<endl;
  }
  return 0;
}
