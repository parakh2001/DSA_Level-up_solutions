#include <bits/stdc++.h>
using namespace std;
int helper(int n,vector<int> &values,int left,int right){
    //base case
    if(left==right || left==right-1){
        return max(values[left],values[right]);
    }
    int op1 = values[left] + min(helper(n,values,left+2,right),helper(n,values,left+1,right-1));
    int op2 = values[right] + min(helper(n,values,left+1,right-1),helper(n,values,left,right-2));
    return max(op1,op2);
}
int MaxValue(int n, vector<int> values){
//Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    int left = 0;
    int right = n-1;
    return helper(n,values,left,right);
}
