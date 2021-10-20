class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n <= 2) {
      vector<int> nodes;
      for (int i = 0; i < n; i++) {
        nodes.push_back(i);
      }

      return nodes;
    }

    vector<int> degrees(n);
    vector<vector<int>> neighbors(n);
    for (const auto& e : edges) {
      neighbors[e[0]].push_back(e[1]);
      neighbors[e[1]].push_back(e[0]);
      degrees[e[0]]++;
      degrees[e[1]]++;
    }

    vector<int> leaves;
    for (int i = 0; i < n; i++) {
      if (degrees[i] == 1) {
        leaves.push_back(i);
      }
    }

    int remain = n;
    while (leaves.size() > 0) {
      remain -= leaves.size();

      vector<int> newLeaves;
      for (int leaf : leaves) {
        for (int neighbor : neighbors[leaf]) {
          degrees[neighbor]--;
          if (degrees[neighbor] == 1) {
            newLeaves.push_back(neighbor);
          }
        }
      }
      
      leaves = newLeaves;
      if (remain <= 2) {
        break;
      }
    }

    return leaves;
  }
};