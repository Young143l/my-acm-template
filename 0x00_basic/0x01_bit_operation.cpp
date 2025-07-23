// 位运算(bit operation)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    // 常用位运算:
    {
        int n = 7;
        cout << (1 << n == pow(2, n)) << endl;  // 1<<n==pow(2,n)
        cout << (n << 1 == 2 * n) << endl;      // n<<1==2*n
        cout << (n >> 1 == floor(n / 2.0))
             << endl;  // n>>1==floor(n/2.0) 向下取整
    }
    // 二进制状态压缩
    {
        int n = 143;  // 10001111
        int k = 5;
        cout << ((n >> k) & 1) << endl;  // (n>>k)&1 取出n的二进制的第k-1位数字
        cout << bitset<8>(n & ((1 << k) - 1))
             << endl;  // n&((1<<k)-1) 取出n二进制的0~k-1位数字
        cout << bitset<8>(n ^ (1 << k)) << endl;   // 使n二进制的第k+1位取反
        cout << bitset<8>(n | (1 << k)) << endl;   // 使n二进制的第k+1位赋值为1
        cout << bitset<8>(n & ~(1 << k)) << endl;  // 使n二进制的第k+1位赋值为0
    }
    // 成对变换
    {
        int n = 6, m = 7;
        /*
        n^1==n+1 n为偶数时
        n^1=n-1 n为奇数时
        */
        cout << ((n ^ 1) == (n + 1)) << endl;
        cout << ((m ^ 1) == (n - 1)) << endl;
    }
    // lowbit运算
    {
        /*
        lowbit运算为一个数二进制下最低位的1及其它后面的所有0组成的数字
        */
        auto lowbit = [](int n) -> int { return n & -n; };  // lowbit(n)=n&-n
        int n = 10;                                         // 1010
        cout << bitset<4>(lowbit(n)) << endl;
    }
    return 0;
}