#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> dis;

    void Floydd_Warshall(const vector<vector<int>> &graph) {
        int v = graph.size();
        for (int k = 0; k < v; k++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost) {
            }
};
