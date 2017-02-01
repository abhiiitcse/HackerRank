#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef vector<int> vi;
int gcd(int a,int b){
  int res;
  int c,d;
  if(a>b){
    c = a;
    d = b;
  }else{
    c = b;
    d = a;
  }
  while(d!=0){
    int temp = c%d;
    c = d;
    d = temp;
  }
  res = c;
  return res;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    bool found =false;
    cin>>n;
    vi v(n);
    cin>>v[0];
    FOR(i,1,n-1){
      cin>>v[i];
      v[i] = gcd(v[i-1],v[i]);
      if (v[i]==1){
	found = true;
      }
    }
    if(found){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
