/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
Given a number n, the task is to find n’th Ugly number.

https://www.geeksforgeeks.org/ugly-numbers/
*/
#define ll long long int

#include <bits/stdc++.h>

using namespace std;

ll uglyNumber(int n){
    vector<ll> ugly(n,0);
    int idx2 = 0,idx3 = 0,idx5 = 0;
    ll next_multiple_2 = 2, next_multiple_3 = 3, next_multiple_5 = 5;
    ll next_ugly = 1;
    ugly[0] = 1;
    for(int i = 1;i<n;i++){
        next_ugly = min(next_multiple_2,min(next_multiple_3,next_multiple_5));
        ugly[i] = next_ugly;

        if(next_ugly == next_multiple_2){
            idx2++;
            next_multiple_2 = ugly[idx2]*2;
        }

        if(next_ugly == next_multiple_3){
            idx3++;
            next_multiple_3 = ugly[idx3]*3;
        }

        if(next_ugly == next_multiple_5){
            idx5++;
            next_multiple_5 = ugly[idx5]*5;
        }
    }

    return next_ugly;
}

int main(){
    int n;
    cin >> n;

    cout << uglyNumber(n)<< endl;
    return 0;
}

