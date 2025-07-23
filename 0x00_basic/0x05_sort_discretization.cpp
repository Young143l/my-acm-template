// 离散化(discretization)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void discreat(vector<int> &num,vector<int> &dis){
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        if(!i||num[i]!=num[i-1]){
            dis.emplace_back(num[i]);
        }
    }
}

int query(int n,vector<int> &dis){
    return lower_bound(dis.begin(),dis.end(),n)-dis.begin();
}

int main() {
    // 离散化是一种数据处理的技巧,本质上可以看成是一种哈希,其保证数据在哈希以后仍然保持原来的全/偏序关系.
    vector<int> num{12313,42342,123,5435434,1321,33543,123132,34234,123124,432};
    vector<int> dis;
    discreat(num,dis);
    cout<<query(432,dis);
    return 0;
}