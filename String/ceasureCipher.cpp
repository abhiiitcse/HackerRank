#include <iostream>
#include <cstring>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  cout<<char('a'+25)<<endl;
  int len,k;
  string inp;
  cin>>len;
  cin>>inp;
  cin>>k;
  string new_str = "";
  k = (k%26);
  FOR(i,0,len){
    if((inp[i]>='a')&&(inp[i]<='z')){
      int val = ((inp[i]-'a')+k)%26;
      new_str += 'a'+val;
    }else if((inp[i]>='A')&&(inp[i]<='Z')){
      int val = ((inp[i]-'A')+k)%26;
      new_str += 'A'+val;
    }else{
      new_str += inp[i];
    }
  }
  cout<<new_str<<endl;
  return 0;
}
