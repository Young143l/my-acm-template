// 前缀与差分(prefix and difference)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    // 前缀和
    {
        /*
        给定一个数列num通过前缀数组S[i]记录前i+1个元素的和.
        可以做到快速求一段区间的和: sum(i+1,j)=S[j]-S[i].
        */
        vector<int> num {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};
        vector<int>  S(num.size());
        for (int i = 0; i < num.size(); i++) {
            if (!i)
                S[i] = num[i];
            else
                S[i] = S[i - 1] + num[i];
        }
        cout << "sum(1,5) = " << S[5] - S[0] << endl;
    }
    // 前缀异或
    {
        /*
        注意:因为异或的性质:x^x=0,x^0=x,所以可以用前缀和的方法实现前缀差分数组.
        给定数组num通过前缀异或数组X[i]记录前i+1个数的异或值,则有:
        num[i+1]^...^num[j]=X[i]^X[j].
        */
        vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};
        vector<int> X(num.size());
        for (int i = 0; i < num.size(); i++) {
            if (!i)
                X[i] = num[i];
            else
                X[i] = X[i - 1] ^ num[i];
        }
        cout << "num[1]^...^num[5] = " << (X[5] ^ X[0]) << endl;
    }
    // 同理也可以做到前缀积,这里不多赘述...

    // 差分
    {
        /*
        给定一个数组num,它的差分数组D为:
        D[0]=num[0],D[i]=num[i]-num[i-1] (0<i<n).
        可以通过差分数组快速记录区间的加减操作.
        区间i~j加x:D[i]+=x,D[j+1]-=x.
        */
        vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int>  D(num.size() + 1,0);
        for (int i = 0; i < num.size(); i++) {
            if (!i)
                D[i] = num[i];
            else
                D[i] = num[i] - num[i - 1];
        }
        D[num.size()] = 0;
        // 区间1~3加4
        int x = 0;
        for (int i = 0; i < num.size(); i++) {
            x += D[i];
            cout << x << " ";
        }
        cout << endl;
        D[1] += 4;
        D[5] -= 4;
        x = 0;
        for (int i = 0; i < num.size(); i++) {
            x += D[i];
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}