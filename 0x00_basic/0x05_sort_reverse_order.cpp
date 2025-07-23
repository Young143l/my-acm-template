// 逆序对(reverse order)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> temp;
long long reverse_order(vector<int> &num, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    long long cnt = reverse_order(num, l, mid)+ reverse_order(num, mid + 1, r);
    int i = l, j = mid + 1, p = l;
    
    while (i <= mid && j <= r) {
        if (num[i] <= num[j]) {
            temp[p++] = num[i++];
        } else {
            cnt+=mid-i+1;
            temp[p++] = num[j++];
        }
    }
    while (i <= mid) {
        temp[p++] = num[i++];
    }
    while (j <= r) {
        temp[p++] = num[j++];
    }
    for (int k = l; k <= r; k++) {
        num[k] = temp[k];
    }
    return cnt;
}

int main() {
    /*
    https://www.luogu.com.cn/problem/P1908
    逆序对:
    数组num,其中所有数字各不相同.如果存在正整数 i,j使得(1≤i<j≤n)并且A[i]>A[j],<[i],A[j]>这个有序对称为A的一个逆序对,也称作逆序数.
    逆序对求法通过归并排序而得.
    */
   int n;
   cin>>n;
   vector<int> num(n);
   temp =vector<int>(n);
   for(auto &i:num) cin>>i;
   cout<<reverse_order(num,0,num.size()-1);    
   return 0;
}