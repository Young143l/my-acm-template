// 最小栈(minimum stack)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct mstack{
    stack<int> stk,min,max;
};

void push(mstack mstk,int x){
    mstk.stk.push(x);
    if(mstk.max.empty()||x>=mstk.max.top()){
        mstk.max.push(x);
    }
    if(mstk.min.empty()||x<=mstk.min.top()){
        mstk.min.push(x);
    }
}

void pop(mstack mstk){
    if(mstk.stk.top()==mstk.min.top()){
        mstk.min.pop();
    }
    if(mstk.stk.top()==mstk.max.top()){
        mstk.max.pop();
    }
    mstk.stk.pop();
}

int main() {
    /*
    最小栈:
    即随时可以得出栈内最小(最大)值的一个栈
    */
    
    return 0;
}