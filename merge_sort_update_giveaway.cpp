#include<vector>
#include <iostream>
#include <map>
#include<algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


struct SegmentTree {
public:
    SegmentTree (int _n, const vector<int>& arr) : n (_n) {
        tree.resize(4*n);
        build (0, n-1, 0, arr);
    }
    
    int query (int x, int y, int k) {
        return query (x, y, k, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }

private:
    void build (int l, int r, int i, const vector<int>& arr) {
        if (l == r) {
            tree[i] .insert( {arr[l],l});
            return;
        }
        
        int m = (l+r) >> 1;
        build (l, m, i*2+1, arr);
        build (m+1, r, i*2+2, arr);
        
        tree[i] = Merge (tree[i*2+1], tree[i*2+2]);
    }

    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i].clear();

            tree[i] .insert( {val,l});
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = Merge (tree[i*2+1], tree[i*2+2]);
    }
    
    ordered_set Merge (const ordered_set& lft, const ordered_set& rgt) {
        ordered_set result=lft;
        for(auto& elem: rgt)result.insert(elem);

        
        return result;
    }
    
    int query (int x, int y, int k, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) {

            int ind = tree[i].order_of_key({k+1,-1});
        
            return (tree[i].size() - ind);
        }
        
        int m = (l+r) >> 1;
        return (
            query (x, y, k, l, m, i*2+1) + 
            query (x, y, k, m+1, r, i*2+2)
        );
    }
    
    vector<ordered_set> tree;
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
        tree.update(2,4);
        cout << tree.query (x-1, y-1, k) << "\n";
    }
    return 0;
}