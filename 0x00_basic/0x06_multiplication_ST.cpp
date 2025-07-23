// 倍增 (multiplication)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

vector<vector<int>> STcreat(vector<int> &num){
    int ln=log(num.size())/log(2);
    vector<vector<int>> st(num.size(),vector<int> (ln+1));
    for(int i=0;i<num.size();i++){
        st[i][0]=num[i];
    }
    for(int j=1;j<=ln;j++){
        for(int i=0;i+(1<<j)-1<num.size();i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    return st;
}

int STquery(vector<vector<int>> &st,int l,int r){
    int k=log(r-l+1)/log(2);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main() {
    /* 
    经典应用:ST算法
    https://www.luogu.com.cn/problem/P3865
    */
    int n,q;
    n=read();
    q=read();
    vector<int> num(n);
    for(int i=0;i<n;i++){
        num[i]=read();
    }
    
    vector<vector<int>> st=STcreat(num);
    while(q--){
        int l,r;
        l=read();
        r=read();
        printf("%d\n",STquery(st,l-1,r-1));
    }
    return 0;
}