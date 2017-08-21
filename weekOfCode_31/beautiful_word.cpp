#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
bool isInVowel(char ch){
  char vowelSet[] = {'a','e','i','o','u','y'};
  for(int i=0;i<6;i++){
    if(ch==vowelSet[i]){
      return true;
    }
  }
  return false;
}

bool isBeautiful(string str){
  int len = str.length();
  for(int i=0;i<len-1;i++){
    if ((str[i]==str[i+1])||((isInVowel(str[i]))&&(isInVowel(str[i+1])))){
      return false;
    }
  }
  return true;
}

int main(){
  string str;
  cin>>str;
  if(isBeautiful(str)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
