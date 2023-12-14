#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main() {
    ordered_set X;
    X.insert({2, 0});
    X.insert({1, 1});
    X.insert({3, 2});
    
         int order = X.size()-X.order_of_key({1,-1});
        //int order = upper_bound(X.begin(), X.end(), 1) - X.begin();
        cout <<order << endl;
   
    return 0;
}