#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long int powerModulo(int base, int exponent){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed
    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    long long temp = powerModulo(base, exponent / 2);
    if (exponent & 1) {
        return (base * temp * temp)%MOD;
    } else {
        return (temp * temp)%MOD;
    }
}
