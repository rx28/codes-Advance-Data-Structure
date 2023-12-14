#include<vector>
#include <iostream>
#include <map>
#include<algorithm>


using namespace std;

struct SegmentTree {
public:
    SegmentTree (int _n, const vector<int>& arr) : n (_n) {
        tree.resize(4*n);
        build (0, n-1, 0, arr);
    }
    
    int query (int x, int y, int k) {
        return query (x, y, k, 0, n-1, 0);
    }
    
private:
    void build (int l, int r, int i, const vector<int>& arr) {
        if (l == r) {
            tree[i] = {arr[l]};
            return;
        }
        
        int m = (l+r) >> 1;
        build (l, m, i*2+1, arr);
        build (m+1, r, i*2+2, arr);
        
        tree[i] = Merge (tree[i*2+1], tree[i*2+2]);
    }
    
    vector<int> Merge (const vector<int>& lft, const vector<int>& rgt) {
        vector<int> result;
        int n1 = lft.size(), n2 = rgt.size();
        int l1 = 0, l2 = 0;
        
        while (l1 < n1 && l2 < n2) {
            if (lft[l1] <= rgt[l2]) {
                result.push_back(lft[l1]);
                l1 ++;
            }
            else {
                result.push_back(rgt[l2]);
                l2 ++;
            }
        }
        while (l1 < n1) result.push_back(lft[l1 ++]);
        while (l2 < n2) result.push_back(rgt[l2 ++]);
        
        return result;
    }
    
    int query (int x, int y, int k, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) {
            int ind = upper_bound(tree[i].begin(), tree[i].end(), k) - tree[i].begin();
            return (tree[i].size() - ind);
        }
        
        int m = (l+r) >> 1;
        return (
            query (x, y, k, l, m, i*2+1) + 
            query (x, y, k, m+1, r, i*2+2)
        );
    }
    
    vector<vector<int>> tree;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    n=4;
    vector<int> v{8,2,1,3};
    
    SegmentTree tree(n, v);
    
    int q;
    q=1;
    while (q --) {
        int x=1, y=3, k=2;
        cout << tree.query (x-1, y-1, k) << "\n";
    }
    return 0;
}