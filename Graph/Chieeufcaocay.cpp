// // Cây là một đồ thị vô hướng trong đó bất kỳ hai đỉnh nào cũng được nối với nhau bởi đúng một đường đi. Nói cách khác, bất kỳ đồ thị liên thông nào không chứa chu trình đơn (simple cycles) đều là một cây.

// // Cho một cây có n đỉnh được đánh nhãn từ 0 đến n - 1 và một mảng edges gồm n - 1 cạnh, trong đó edges[i] = [ai, bi] biểu thị rằng có một cạnh vô hướng giữa hai đỉnh ai và bi trong cây, 
// bạn có thể chọn bất kỳ đỉnh nào của cây làm gốc. Khi bạn chọn một đỉnh x làm gốc, cây kết quả sẽ có chiều cao h. 
// Trong số tất cả các cây có thể có khi chọn gốc, những cây có chiều cao nhỏ nhất (tức là min(h)) được gọi là cây chiều cao tối thiểu (Minimum Height Trees - MHTs).

// // Hãy trả về một danh sách chứa tất cả các nhãn của các đỉnh làm gốc của các MHTs. Bạn có thể trả về kết quả theo bất kỳ thứ tự nào.

// // Chiều cao của một cây có gốc là số lượng cạnh trên đường đi xuống dài nhất từ gốc đến một lá.
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) leaves.push(i);
        }
        
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int size = leaves.size();
            remainingNodes -= size;
            for (int i = 0; i < size; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }
        
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};