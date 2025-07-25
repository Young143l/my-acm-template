// 堆(heap)
#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

void insert(vector<int> &heap, int x) {
    heap.emplace_back(x);
    int i = heap.size() - 1;
    while (i > 1) {
        int fa = i >> 1;
        if (heap[i] < heap[fa]) {
            swap(heap[i], heap[fa]);
            i = fa;
        } else {
            break;
        }
    }
}

int getmin(vector<int> &heap) {
    if (heap.size() > 1)
        return heap[1];
    else
        return INT_MIN;
}

void deletop(vector<int> &heap) {
    int x = heap[heap.size() - 1];
    heap.pop_back();
    if (heap.size() > 1) {
        heap[1] = x;
        int i = 1;
        while (2 * i < heap.size()) {
            if (2 * i == heap.size() - 1) {
                if (heap[i] > heap[2 * i]) {
                    swap(heap[i], heap[2 * i]);
                    i *= 2;
                } else {
                    break;
                }

            } else if (heap[i] > min(heap[2 * i], heap[2 * i + 1])) {
                int *max;
                if (heap[2 * i] < heap[2 * i + 1]) {
                    swap(heap[i], heap[2 * i]);
                    i = 2 * i;
                } else {
                    swap(heap[i], heap[2 * i + 1]);
                    i = 2 * i + 1;
                }
            } else {
                break;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    // 示例为小根堆
    //https://www.luogu.com.cn/problem/P3378
    vector<int> heap(1, 0);
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            insert(heap,x);
        }else if(op==2){
            cout<<getmin(heap)<<endl;
        }else{
            deletop(heap);
        }
    }
    return 0;
}