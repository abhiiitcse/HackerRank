#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int abcd[100010];
int parent[100010];
typedef long long int lli;
#define mod 1000000007
long long int B[100009],C[100009],D[100009];
#define MOD 1000000007
int find(int node)
{
  int k;
  if(parent[node]==node)
    {
      return node;
    }
  else
    k=  find(parent[node]);
  return k;
     

}

void  merge(int a, int  b)
{
  int x=find(a);
  int y=find(b);
  if(abcd[x]>abcd[y])
    {
    
      parent[y]=x;
      abcd[x]+=abcd[y];
      abcd[y]=0;
      //cout<<" merging "<<a<<" b "<<b<<"  as a common parent "<<x<<" abcd y "<<abcd[y]<<" abcd x "<<abcd[x]<<endl;
   
    }
  else
    {
      parent[x]=y;
   
      abcd[y]+=abcd[x];
      abcd[x]=0;
      //cout<<" merging "<<a<<" b "<<b<<"  as a common parent "<<y<<" abcd y "<<abcd[y]<<" abcd x "<<abcd[x]<<endl;
    }

}


int main()
{
  int n;
  cin>>n;



  for(int i=0;i<=n+1;i++)
    {
      parent[i]=i;
      abcd[i]=1;
    }
  for(int i=0;i<n-1;i++)
    {
      int  a,b;
     
      char c;
      cin>>a>>b>>c;
  
      if(c=='r') continue;
      else
	{
	  if(find(a)!=find(b))
	    {
	      //  cout<<" merging "<<a<<" "<<b<<endl;
	      merge(a,b);
	    }
	}
    }
  
  vector<lli>count1;
  for(int i=0;i<=n;i++) count1.push_back(0);
  for(int i=1;i<=n;i++)
    {
      if(abcd[i]!=0)
	{
        
	  count1[i]=(abcd[i]);// size of all  sets 
	}
    }
    
    
  //k = 1
    //B[n] = count1[n];
    
    int i;
    for(i=n;i>=1;i--){
        B[i]  = (count1[i]);
    }
    for(i=n;i>=1;i--){
        B[i]  = (B[i] + B[i+1]);
    }
    for(i=1;i<=n-1;i++){
        C[i] = (count1[i]*B[i+1]);
    }
    
    for(i=n-1;i>=1;i--){
        C[i] = (C[i] + C[i+1]);
    }
    for(i=1;i<=n-2;i++){
        D[i] = (count1[i]*C[i+1]);
    }
  
  /*B[n-1] = count1[n];
  int i;
  for(i=n-2;i>=0;i--) B[i] = (B[i+1] + count1[i+1])%MOD;
  
  for(i=1;i<n-1;i++) C[i] = (count1[i+1]*B[i+1])%MOD;
  

  D[n-2] = C[n-2];
  for(i=n-3;i>=1;i--) D[i] = (D[i+1] + C[i])%MOD;*/
  /*for(int i=1;i<=n;i++){
    cout<<D[i]<<" ";
  }
  cout<<endl;
  for(int i=1;i<=n;i++){
    cout<<count1[i]<<" ";
  }
  cout<<endl; */
  lli sum=0;
  //for(i=0;i<n-2;i++) sum = (sum + count1[i+1]*D[i+1])%MOD;
    for(i=1;i<=n-2;i++) sum = (sum + D[i])%MOD;
  cout<< ( MOD + sum )%MOD<<endl; 
  /*** jadu end*/////////////
  return 0;
}

