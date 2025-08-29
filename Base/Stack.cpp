#include <iostream>
#include <stack> // cho std::stack

using namespace std;

int main() {
    // 1. std::stack - Một container LIFO (Last In, First Out)
    cout << "=== Thao tác với std::stack ===\n";
    
    // Khởi tạo stack
    stack<int> myStack;
    
    // push() - Thêm phần tử vào đỉnh
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Phần tử đỉnh sau khi push: " << myStack.top() << "\n";
    
    // pop() - Xóa phần tử đỉnh
    myStack.pop();
    cout << "Sau khi pop, phần tử đỉnh: " << myStack.top() << "\n";
    
    // size() - Số lượng phần tử
    cout << "Kích thước của myStack: " << myStack.size() << "\n";
    
    // empty() - Kiểm tra stack có rỗng không
    cout << "myStack có rỗng không? " << (myStack.empty() ? "Có" : "Không") << "\n";
    
    // In tất cả phần tử (cần sao chép sang stack tạm)
    stack<int> tempStack = myStack;
    cout << "Các phần tử trong stack (từ đỉnh đến đáy): ";
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << "\n";
    
    // emplace() - Thêm phần tử tại chỗ vào đỉnh
    myStack.emplace(40);
    cout << "Sau khi emplace(40), phần tử đỉnh: " << myStack.top() << "\n";
    
    // swap() - Hoán đổi nội dung với stack khác
    stack<int> otherStack;
    otherStack.push(100);
    otherStack.push(200);
    myStack.swap(otherStack);
    cout << "Sau khi swap, myStack đỉnh: " << myStack.top() << "\n";
    cout << "Sau khi swap, otherStack đỉnh: " << otherStack.top() << "\n";
    
    return 0;
}