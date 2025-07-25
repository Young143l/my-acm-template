// 单调栈(monotone stack)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    /*
    单调栈
    https://www.luogu.com.cn/problem/P5788
    */
    int n;
    cin>>n;
    vector<int> num(n),f(n,0);
    stack<int> stk;
    for(auto &i:num) cin>>i;
    for(int i=0;i<n;i++){
        if(stk.empty()){
            stk.push(i);
        }
        while(stk.size()&&num[stk.top()]<num[i]){
            f[stk.top()]=i+1;
            stk.pop();
        }
        stk.push(i);
    }
    for(const auto &i:f){
        cout<<i<<" ";
    }

    return 0;
}