#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void Push(vector<vector<int>>& matrix, vector<int>& result, int m, int n, int num) {
        if (m == 0 || n == 0) {
            return;
        }
        
        if (m == 1) {
            // Tru?ng h?p còn l?i là m?ng 1 chi?u
            if (num % 2) {
                // N?u s? lu?t xo?n ?c là l?, thêm các ph?n t? t? trái sang ph?i
                for (int i = 0; i < n; i++)
                    result.push_back(matrix[0][i]);
            } else {
                // N?u s? lu?t xo?n ?c là ch?n, thêm các ph?n t? t? ph?i sang trái
                for (int i = n - 1; i >= 0; i--)
                    result.push_back(matrix[0][i]);
            }
            return;
        }
        
        if (n == 1) {
            // Tru?ng h?p còn l?i là m?ng 1 c?t
            if (num % 2) {
                // N?u s? lu?t xo?n ?c là l?, thêm các ph?n t? t? trên xu?ng du?i
                for (int i = 0; i < m; i++)
                    result.push_back(matrix[i][0]);
            } else {
                // N?u s? lu?t xo?n ?c là ch?n, thêm các ph?n t? t? du?i lên trên
                for (int i = m - 1; i >= 0; i--)
                    result.push_back(matrix[i][0]);
            }
            return;
        }
        
        if (num % 2) {
            // Thêm các ph?n t? t? trái sang ph?i
            for (int i = 0; i < n; i++)
                result.push_back(matrix[0][i]);
            matrix.erase(matrix.begin());
            
            // Thêm các ph?n t? t? trên xu?ng du?i
            for (int i = 0; i < m - 1; i++) {
                result.push_back(matrix[i][n - 1]);
                matrix[i].erase(matrix[i].begin() + n - 1);
            }
        } else {
            // Thêm các ph?n t? t? ph?i sang trái
            for (int i = n - 1; i >= 0; i--)
                result.push_back(matrix[m - 1][i]);
            matrix.erase(matrix.begin() + m - 1);
            
            // Thêm các ph?n t? t? du?i lên trên
            for (int i = m - 2; i >= 0; i--) {
                result.push_back(matrix[i][0]);
                matrix[i].erase(matrix[i].begin());
            }
        }
        
        Push(matrix, result, m - 1, n - 1, num + 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int number = 1;
        Push(matrix, result, m, n, number);
        return result;
    }
};

int main() {
    Solution solution;
    
    int m, n;
    std::cout << "Enter the number of rows: ";
    std::cin >> m;
    std::cout << "Enter the number of columns: ";
    std::cin >> n;
    
    std::cout << "Enter the matrix elements:" << std::endl;
    std::vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    vector<int> result = solution.spiralOrder(matrix);
    
    std::cout << "The spiral order traversal of the matrix is: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}







