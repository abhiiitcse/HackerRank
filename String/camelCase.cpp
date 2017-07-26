#include <iostream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  string inp;
  cin>>inp;
  int result=0;
  int i=0;
  while(i<inp.length()){
    while((i<inp.length())&&(inp[i]>='a')&&(inp[i]<='z')){
      i++;
    }
    result++;
    if(i<inp.length()){
      i++;
    }
  }
  cout<<result<<endl;
  return 0;
}
