// 单调队列(monotonic queue)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void pushmaxn(deque<int> &maxn, int x) {
    if (x <= maxn.back()) {
        maxn.push_back(x);
    } else {
        while (maxn.size() && maxn.back() < x) maxn.pop_back();
        maxn.push_back(x);
    }
}

void pushminn(deque<int> &minn, int x) {
    if (x >= minn.back()) {
        minn.push_back(x);
    } else {
        while (minn.size() && minn.back() > x) minn.pop_back();
        minn.push_back(x);
    }
}

int main() {
    // https://www.luogu.com.cn/problem/P1886
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    deque<int> minn, maxn;
    minn.push_back(num[0]);
    maxn.push_back(num[0]);
    for (int i = 1; i < k; i++) {
        pushmaxn(maxn,num[i]);
        pushminn(minn,num[i]);
    }
    vector<int> ama(n-k+1), ami(n-k+1);
    ama[0] = maxn.front(), ami[0] = minn.front();
    for (int i = 0; i < n - k; i++) {
        if(maxn.front()==num[i]) maxn.pop_front();
        if(minn.front()==num[i]) minn.pop_front();
        pushmaxn(maxn,num[i+k]);
        pushminn(minn,num[i+k]);
        ama[i+1]=maxn.front();
        ami[i+1]=minn.front();
    }
    for(const auto &i:ami){
        cout<<i<<" ";
    }
    cout<<endl;
    for(const auto &i:ama){
        cout<<i<<" ";
    }
    return 0;
}