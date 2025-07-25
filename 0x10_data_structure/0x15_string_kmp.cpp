// 字符串kmp算法(string kmp)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> buildnext(string s) {
    vector<int> next(s.length(), 0);
    int k = 0;
    for (int i = 1; i < s.length(); i++) {
        while (k > 0 && s[i] != s[k]) {
            k = next[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        next[i] = k;
    }
    return next;
}

int mykmp(string &s, string &a) {
    auto next = buildnext(a);
    int i = 0, j = 0;
    while (i < s.length()) {
        if (s[i] == a[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            i++;
        }
        if (j == a.length()) {
            return i - j;
            // cout<<i-j+1<<endl;
            // j=next[j-1];
        }
    }
    // for(auto &i:next){
    //     cout<<i<<" ";
    // }
    return -1;
}

int main() {
    // https://www.luogu.com.cn/problem/P3375
    string s, a;
    cin >> s >> a;
    cout << mykmp(s, a);
    // mykmp(s,a);
    return 0;
}