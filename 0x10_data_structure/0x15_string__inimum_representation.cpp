// 最小表示(minimum representation)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string minrep(string s) {
    int n = s.length();
    s += s;
    int i = 0, j = 1;
    while (i < n && j < n) {
        int k = 0;
        while (k < n && s[i + k] == s[j + k]) k++;
        if (k >= n) break;
        if (s[i + k] < s[j + k]) {
            j = j + k + 1;
            if (j <= i) j = i + 1;
        } else {
            i = i + k + 1;
            if (i <= j) i = j + 1;
        }
    }
    return s.substr(min(i, j), n);
}

int main() {
    //https://www.luogu.com.cn/problem/P13270
    int n;
    string s;
    cin >> n >> s;
    cout << minrep(s);
    return 0;
}