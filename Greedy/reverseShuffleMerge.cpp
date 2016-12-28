#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
typedef vector<int> vi;
string findA(string str){
  string retstr;
  reverse(str.begin(),str.end());
  //cout<<str<<endl;
  int freq[26];
  vi position[26];
  memset(freq,0,26);
  FOR(i,0,str.length()-1){
    freq[str[i]-'a']++;
    position[str[i]-'a'].pb(i);
  }
  //FOR(i,0,position[0].size()-1){
  //cout<<position[0][i]<<",";
  //}
  //cout<<endl;
  int next_to_use[26];
  FOR(i,0,25){
    freq[i] /= 2;
    next_to_use[i] = 0;
  }
  vi needs(str.size());
  int freq_seen[26];
  memset(freq_seen,0,26);
  FORI(i,str.length()-1,0){
    needs[i] = freq[str[i]-'a'] - freq_seen[str[i]-'a'];
    needs[i] = max(0,needs[i]);
    freq_seen[str[i]-'a']++;
  }
  //FOR(i,0,needs.size()-1){
  //cout<<needs[i]<<",";
  //}
  //cout<<endl;
  int next_bottleneck = 0;
  int last_pos = 0;
  int written[26];
  memset(written,0,26);
  while(retstr.size() != (str.size()/2)){
    while(!(written[str[next_bottleneck]-'a'] < needs[next_bottleneck])){
      next_bottleneck++;
    }
    //cout<<next_bottleneck<<endl;
    int next_char = 0;
    while((written[next_char]==freq[next_char])||
	  (position[next_char][next_to_use[next_char]] > next_bottleneck)){
      next_char++;
    }
    int str_pos = position[next_char][next_to_use[next_char]];
    //cout<<"str_pos = "<<str_pos<<endl;
    while(last_pos!=str_pos){
      next_to_use[str[last_pos]-'a']++;
      last_pos++;
    }
    do{
      retstr.pb(next_char+'a');
      written[next_char]++;
      next_to_use[next_char]++;
    }while(written[next_char]<needs[str_pos]);
    last_pos = str_pos + 1;
    

    
    if(true){
      //  break;
    }
    //getchar();
      
  }
  
  
  return retstr;
}
int main(){
  string inp;
  cin>>inp;
  string str = findA(inp);
  cout<<str<<endl;
  return 0;
}
