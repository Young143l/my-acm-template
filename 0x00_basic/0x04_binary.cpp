// 二分搜索(binary)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool check(double x) {
    // code...
    return true;
}

int main() {
    // 整数集合上二分
    {
        vector<int>  num{-1, -2, -3, -4, 1, 3, 5, 8, 9, 10};
        int l, r, x = 5;

        // 找>=x中最小的一个
        l = 0, r = 9;
        while (l < r) {
            int mid =
                (l + r) >>
                1;  // 使用移位做到向下取整,使用/2的话为向零取证,使其在负数域生效.
            if (num[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;

        l = 0, r = 9;
        while (l < r) {
            int mid = (l + r + 1) >> 1;  //+1的话防止陷入类似l=1,r=2的死循环
            if (num[mid] <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
    // 实数域上二分
    {
        double l, r;

        // 指定精度二分
        l = 0, r = 100;
        double eps = 1e-5;
        while (l + eps < r) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        // 固定次数二分
        l = 0, r = 100;
        for (int i = 1; i <= 100; i++) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }

    return 0;
}