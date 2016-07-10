#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){
  long long L,s1,s2,qi;
  int Q;
  long double ans;
  long double roottwo = (long double)(sqrt(2));
  cin>>L>>s1>>s2;
  long double s2minuss1;
  if(s2 > s1){
    s2minuss1 = s2 - s1;
  }else{
    s2minuss1 = s1 - s2;
  }
  cin>>Q;
  cout<<fixed<<setprecision(8);
  while(Q--){
    cin>>qi;
    if (((L*L) - qi) < 0.0001){
      ans = 0.0;
    }
    else{
      long double sqrtqi = sqrt(qi);
      ans = (long double)((roottwo * (L - sqrtqi))/s2minuss1);
    }
    cout<<ans<<endl;
  }
  return 0;
}
