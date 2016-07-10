#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long find_gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return find_gcd(b,a%b);
}

int main() {
    int tt;
    cin>>tt;
    long long a,b,x,y;
    while(tt--){
        cin>>a>>b>>x>>y;
        if (find_gcd(a,b) == find_gcd(x,y)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

