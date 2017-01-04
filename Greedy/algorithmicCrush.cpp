#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long int li;
int main(){
  li N,M;
  cin>>N>>M;
  vector<li> vec(N+1,0);
  FOR(i,1,M){
    li a,b,k;
    cin>>a>>b>>k;
    vec[a] += k;
    if(b<N){
      vec[b] -= k;
    }
  }
  li result = vec[1];
  FOR(i,2,N){
    vec[i] += vec[i-1];
    if (vec[i] > result){
      result = vec[i];
    }
  }
  cout<<result<<endl;
  return 0;
}
