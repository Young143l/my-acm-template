// 字典树(trie)
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct trie{
    string val;
    int cnt=0;
    unordered_map<char,struct trie> next;
};

void insert(struct trie &root,string s){
    struct trie *pos=&root;
    for(const auto &c:s){
        if(pos->next.count(c)){
            pos=&pos->next[c];
            pos->cnt++;
        }else{
            struct trie temp;
            temp.val=c;
            temp.cnt++;
            pos->next[c]=temp;
            pos=&pos->next[c];
        }
    }
}

int find(struct trie &root,string s){
    if(root.next.count(s[0])){
        if(s.size()==1) return root.next[s[0]].cnt;
        return find(root.next[s[0]],s.substr(1,s.size()-1));
    }else{
        return 0;
    }
}

int main() {
    //https://www.luogu.com.cn/problem/P8306
    int t;
    cin>>t;
    while(t--){
        struct trie root;
        root.val="root";
        int n,q;
        cin>>n>>q;
        while(n--){
            string s;
            cin>>s;
            insert(root,s);
        }
        while(q--){
            string s;
            cin>>s;
            cout<<find(root,s)<<endl;
        }
    }
    return 0;
}