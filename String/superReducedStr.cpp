#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
string get_result(string str){
  string res1,res2="";
  res1.append(str);
  while(true){
    bool found = false;
    int i=0;
    while(i<res1.length()){
      if(i<(res1.length()-1)){
	if(res1[i]!=res1[i+1]){
	  res2+=res1[i];
	  i++;
	}else{
	  found=true;
	  i+=2;
	}
      }else if(i==(res1.length()-1)){
	res2 += res1[i];
	i++;
      }
    }
    res1 = res2;
    res2.clear();
    if(!found){
      break;
    }
  }
  return res1;
}
int main(){
  string inp;
  cin>>inp;
  string result=get_result(inp);
  if(result.length()==0){
    cout<<"Empty String"<<endl;
  }else{
    cout<<result<<endl;
  }
  return 0;
}
