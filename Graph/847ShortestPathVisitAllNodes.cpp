#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q; // (node, mask, dist)
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false)); // Trạng thái (node, mask)
        int target = (1 << n) - 1; // Mục tiêu: tất cả bit đều là 1
        
        // Khởi tạo BFS từ mọi đỉnh
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0); // Bắt đầu từ node i, mask có bit i = 1
            visited[i][1 << i] = true;
        }
        
        // BFS
        while (!q.empty()) {
            auto [node, mask, dist] = q.front();
            q.pop();
            
            // Nếu đã thăm hết các đỉnh
            if (mask == target) {
                return dist;
            }
            
            // Duyệt các đỉnh kề
            for (int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor); // Thêm neighbor vào mask
                if (!visited[neighbor][newMask]) {
                    visited[neighbor][newMask] = true;
                    q.emplace(neighbor, newMask, dist + 1);
                }
            }
        }
        
        return 0; // Trường hợp đặc biệt (n = 1)
    }
};