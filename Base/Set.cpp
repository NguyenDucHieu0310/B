#include <iostream>
#include <set> // cho std::set

using namespace std;

int main() {
    // 1. std::set - Một container lưu trữ các phần tử duy nhất, được sắp xếp
    cout << "=== Thao tác với std::set ===\n";
    
    // Khởi tạo set
    set<int> mySet = {3, 1, 4, 1, 5}; // Các phần tử trùng lặp sẽ bị loại bỏ
    cout << "mySet ban đầu: ";
    for (int x : mySet) cout << x << " ";
    cout << "\n";
    
    // insert() - Thêm phần tử
    mySet.insert(2);
    mySet.insert(1); // Phần tử trùng lặp, không được thêm
    cout << "Sau khi insert(2), mySet: ";
    for (int x : mySet) cout << x << " ";
    cout << "\n";
    
    // erase() - Xóa phần tử
    mySet.erase(3); // Xóa theo giá trị
    cout << "Sau khi erase(3), mySet: ";
    for (int x : mySet) cout << x << " ";
    cout << "\n";
    
    // find() - Tìm kiếm phần tử
    auto it = mySet.find(4);
    cout << "Tìm 4: " << (it != mySet.end() ? "Tìm thấy" : "Không tìm thấy") << "\n";
    
    // count() - Kiểm tra sự tồn tại của phần tử
    cout << "Số lần xuất hiện của 5: " << mySet.count(5) << "\n";
    
    // size() - Số lượng phần tử
    cout << "Kích thước của mySet: " << mySet.size() << "\n";
    
    // empty() - Kiểm tra set có rỗng không
    cout << "mySet có rỗng không? " << (mySet.empty() ? "Có" : "Không") << "\n";
    
    // clear() - Xóa toàn bộ phần tử
    mySet.clear();
    cout << "Sau khi clear, kích thước: " << mySet.size() << "\n";
    
    return 0;
}