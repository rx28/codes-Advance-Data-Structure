#include<vector>
#include <iostream>
#include <map>
#include<algorithm>
using namespace std;

typedef long long int ll;
#define pii pair<int, int>
#define F first
#define S second

struct SegTree {
public:

    SegTree (int _n) : n (_n) {
        tree.resize(4*n, 0);
    }
    
    int query (int x, int y) {
        return query (x, y, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }

private:
    
    vector<int> tree;
    int n;
    
    int query (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return (
            query (x, y, l, m, i*2+1) +
            query (x, y, m+1, r, i*2+2)
        );
    }
    
    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] += val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = tree[i*2+1] + tree[i*2+2];
    }
};

int main() {
    
	int n=7;
	vector<int> arr(n);
	vector<pii> element_and_ind; 
	for (int j = 0; j < n; j ++) {
	    cin >> arr[j];
	    element_and_ind.push_back({arr[j], j});
	}
	
	sort (element_and_ind.begin(), element_and_ind.end());
	map<int, int> position;
	for (int j = 0; j < n; j ++) {
	    position[element_and_ind[j].F] = j;
	}
	
	SegTree tree(n);
	ll result = 0;
	
	for (int j = 0; j < n; j ++) {
	    int pos = position[arr[j]];

	    ll greater_in_left = tree.query (pos+1, n-1);
	    ll smaller_in_left = j - greater_in_left;

	    ll smaller_in_right = pos - smaller_in_left;
	    ll greater_in_right = (n - pos - 1) - greater_in_left;

        result += greater_in_left * smaller_in_right;

	    tree.update(pos, 1);
	}

    cout << result;
	return 0;
}