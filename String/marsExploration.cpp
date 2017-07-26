#include <iostream>
using namespace std;
int main(){
  string inp;
  cin>>inp;
  int num_msg = inp.length()/3;
  int missmsg = 0;
  for(int i=0;i<num_msg;i++){
    if(inp[(3*i+0)]!='S'){
      missmsg++;
    }
    if(inp[(3*i+1)]!='O'){
      missmsg++;
    }
    if(inp[(3*i+2)]!='S'){
      missmsg++;
    }
  }
  cout<<missmsg<<endl;
  return 0;
}
    
