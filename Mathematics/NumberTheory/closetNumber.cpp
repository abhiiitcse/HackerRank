#include <iostream>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long int li;
li get_closest_num(li a,li b,li x){
  li pow_val = pow(a,b);
  li divisor = pow_val/x;
  li result = ((pow_val - (divisor*x))>((divisor+1)*x - pow_val))?(divisor+1)*x:(divisor*x);
  return result;
}
  
int main(){
  int t;
  li a,b,x;
  cin>>t;
  FOR(i,1,t){
    cin>>a>>b>>x;
    li result = get_closest_num(a,b,x);
    cout<<result<<endl;
  }
  return 0;
}
  
  
  
