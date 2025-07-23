// 第k大数(top k)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int topk(vector<int> &num,int l,int r,int k){
    if(l==r) return num[l];
    int mid=num[(l+r)>>1];
    int i=l-1,j=r+1;
    while(i<j){
        while(num[++i]<mid);
        while(num[--j]>mid);
        if(i<j){
            swap(num[i],num[j]);
        }
    }
    int cnt=j-l+1;
    if(cnt>=k){
        return topk(num,l,j,k);
    }else{
        return topk(num,j+1,r,k-cnt);
    }

}

int main() {
    // 通过快速排序算法的拓展,实现O(n)复杂度的第k大数字算法.
    vector<int> num{1,2,3,4,8,2,56,23,6,76,345,345,564,345,3,34,54,5};
    int k=14;
    cout<<topk(num,0,num.size()-1,k)<<endl;
    sort(num.begin(),num.end());
    for(auto &i:num){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<num[k-1];
    return 0;
}