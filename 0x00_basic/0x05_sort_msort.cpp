// 归并排序(merge sort)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void msort(vector<int> &num,int l,int r){
    if(l>=r) return;
    int mid=(l+r)>>1;
    msort(num,l,mid);
    msort(num,mid+1,r);
    int i=l,j=mid+1,p=l;
    vector<int> temp(r+1,0);
    while(i<=mid&&j<=r){
        if(num[i]<=num[j]){
            temp[p++]=num[i++];
        }else{
            temp[p++]=num[j++];
        }
    }
    while(i<=mid){
        temp[p++]=num[i++];
    }
    while(j<=r){
        temp[p++]=num[j++];
    }
    for(int k=l;k<=r;k++){
        num[k]=temp[k];
    }
}

int main() {
    vector<int> num{1,4,3,2,45,2,34};
    msort(num,0,num.size()-1);
    for(auto &i:num){
        cout<<i<<" ";
    }
    return 0;
}