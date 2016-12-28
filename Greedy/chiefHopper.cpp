#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
typedef vector<int> vi;
int main(){
  int N;
  vi height;
  cin>>N;
  FOR(i,1,N){
    int hi;
    cin>>hi;
    height.pb(hi);
  }
  long int max_val = 0;
  FORI(i,height.size()-1,0){
    max_val = ceil((max_val + height[i])/2.0);
  }
  cout<<max_val<<endl;
  return 0;
}
