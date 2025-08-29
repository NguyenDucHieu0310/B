#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Xây dựng danh sách kề
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Cạnh từ b_i đến a_i
        }
        
        // Mảng đánh dấu
        vector<bool> visited(numCourses, false); // Đã duyệt xong
        vector<bool> recStack(numCourses, false); // Trong ngăn xếp đệ quy
        
        // Duyệt DFS từ mỗi đỉnh chưa thăm
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && hasCycle(i, adj, visited, recStack)) {
                return false; // Nếu có chu trình, không thể hoàn thành
            }
        }
        
        return true; // Không có chu trình, có thể hoàn thành
    }
    
private:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        // Đánh dấu nút đang được duyệt
        visited[node] = true;
        recStack[node] = true;
        
        // Duyệt các đỉnh kề
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // Nếu chưa thăm và phát hiện chu trình từ neighbor
                if (hasCycle(neighbor, adj, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                // Nếu neighbor đã trong ngăn xếp đệ quy, có chu trình
                return true;
            }
        }
        
        // Hoàn thành duyệt node, xóa khỏi ngăn xếp đệ quy
        recStack[node] = false;
        return false; // Không tìm thấy chu trình
    }
};