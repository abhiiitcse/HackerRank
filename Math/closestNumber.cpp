#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int tt;
  long long a,b,x;
  cout<<pow(1,0)<<endl;
  cin>>tt;
  while(tt--){
    cin>>a>>b>>x;
    double powab = pow(a,b);
    long long result;
    long long val =(long long)( (powab)/x);
    val = val * x;
    if (val == 0){
      if ((powab > 0.5) && (x == 1)){
	result = 1;
      }else{
	result = 0;
      }
    }else{
      result = val;
    }
    cout<<result<<endl;
  }
  return 0;
}
