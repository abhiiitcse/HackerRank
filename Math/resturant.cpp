#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b;
  int tt;
  while(tt--){
    cin>>a>>b;
    int area = a*b;
    int c = min(a,b);
    int retval=0;
    for(int i=c;i>0;i--){
      if((area % (i*i)) == 0){
	retval = area/(i*i);
	break;
      }
    }
    cout<<retval<<endl;
  }
  return 0;
}
