#include <bits/stdc++.h>

using namespace std;
bool isPerfectSquare(long x){
  long s = sqrt(x);
  return (s*s == x);
}

// Returns true if n is a Fibinacci Number, else false
bool isFibonacci(long n){
  return isPerfectSquare(5*n*n + 4) ||
    isPerfectSquare(5*n*n - 4);
}

bool isOkay(long n){
  long count[10];
  for(int i=0;i<10;i++){
    count[i] = 0;
  }
  while(n){
    count[n%10]++;
    n /= 10;
  }
  bool okay = true;
  for(int i=0;i<10;i++){
    if(!isFibonacci(count[i])){
      okay = false;
      break;
    }
  }
  return okay;
}

long solve(long n){
    // Complete this function
  long result = n;
  while(true){
    if(isOkay(result)){
      break;
    }
    result++;
  }
  return result;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long n;
        cin >> n;
        long result = solve(n);
        cout << result << endl;
    }
    return 0;
}

