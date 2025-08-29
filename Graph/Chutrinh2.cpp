#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Xây dựng danh sách kề
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Cạnh từ b_i đến a_i
        }
        
        // Mảng đánh dấu và kết quả
        vector<bool> visited(numCourses, false); // Đã duyệt xong
        vector<bool> recStack(numCourses, false); // Trong ngăn xếp đệ quy
        vector<int> result; // Lưu thứ tự topological
        
        // Duyệt DFS từ mỗi đỉnh chưa thăm
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && hasCycle(i, adj, visited, recStack, result)) {
                return {}; // Nếu có chu trình, trả về mảng rỗng
            }
        }
        
        // Đảo ngược kết quả để có thứ tự topological
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<bool>& visited,
                  vector<bool>& recStack, vector<int>& result) {
        // Đánh dấu nút đang được duyệt
        visited[node] = true;
        recStack[node] = true;
        
        // Duyệt các đỉnh kề
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // Nếu chưa thăm và phát hiện chu trình từ neighbor
                if (hasCycle(neighbor, adj, visited, recStack, result)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                // Nếu neighbor trong ngăn xếp đệ quy, có chu trình
                return true;
            }
        }
        
        // Hoàn thành duyệt node, thêm vào kết quả
        recStack[node] = false;
        result.push_back(node);
        return false;
    }
};