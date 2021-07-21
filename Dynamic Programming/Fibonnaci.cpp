#include <bits/stdc++.h>

using namespace std;

long long int fib(int n){
    vector<long long int> f(n+2,0);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2;i<=n;i++){
        f[i] = f[i-2] + f[i-1];
    }

    return f[n];

}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}