// 排序(sort)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool mycmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void myqsort(vector<int>& num, int l, int r) {
    if (l >= r) return;
    if (r - l == 1) {
        if (num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = num[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (num[++i] < mid);
        while (num[--j] > mid);
        if (i < j) {
            swap(num[i], num[j]);
        }
    }
    myqsort(num, l, j);
    myqsort(num, i, r);
}

int main() {
    // 快速排序实现
    {
        vector<int> num{1, 5, 2, 3, 4};
        myqsort(num, 0, num.size() - 1);
        for (auto& i : num) {
            cout << i << " ";
        }
        cout << endl;
    }
    // C++STL库sort排序
    {
        // 数组排序
        {
            vector<int> num{1, 5, 2, 6, 8, 2, 1, 54, 6, 3, 30};
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size(); i++) {
                cout << num[i] << " ";
            }
            cout << endl;
        }
        // vector数组排序
        {
            vector<int> num{1, 23, 5, 432, 3, 3, 4, 2, 32, 2, 3, 24, 2};
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size(); i++) {
                cout << num[i] << " ";
            }
            cout << endl;
        }
        // sort默认为升序为less比较算法,改为greater为降序
        {
            vector<int> num{1, 23, 5, 432, 3, 3, 4, 2, 32, 2, 3, 24, 2};
            sort(num.begin(), num.end(), greater<int>());
            for (int i = 0; i < num.size(); i++) {
                cout << num[i] << " ";
            }
            cout << endl;
        }
        // sort也可自定义排序规则
        {
            vector<pair<int, int>> num{{1, 2}, {3, 4}, {2, 5}, {1, 3}};
            // 使用lambada表达式
            sort(num.begin(), num.end(), [](auto a, auto b) -> bool {
                if (a.first == b.first)
                    return a.second < b.second;
                else
                    return a.first < b.first;
            });
            // 使用函数
            sort(num.begin(), num.end(), mycmp);
            for (auto [i, j] : num) {
                cout << "{" << i << "," << j << "} ";
            }
            cout << endl;
        }
    }
    return 0;
}