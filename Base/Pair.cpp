#include <iostream>
#include <utility> // cho std::pair

using namespace std;

int main() {
    // 1. std::pair - Một container đơn giản chứa hai giá trị khác loại
    cout << "=== Thao tác với std::pair ===\n";
    
    // Khởi tạo pair
    pair<int, string> p1 = {1, "An"};
    pair<int, string> p2 = make_pair(2, "Bình");
    
    // Truy cập phần tử
    cout << "p1: (" << p1.first << ", " << p1.second << ")\n";
    cout << "p2: (" << p2.first << ", " << p2.second << ")\n";
    
    // Sửa đổi phần tử của pair
    p1.first = 10;
    p1.second = "Cường";
    cout << "Sau khi sửa, p1: (" << p1.first << ", " << p1.second << ")\n";
    
    // So sánh các pair
    pair<int, int> p3 = {1, 2};
    pair<int, int> p4 = {1, 3};
    cout << "p3 < p4: " << (p3 < p4 ? "Có" : "Không") << "\n";
    
    // Hoán đổi hai pair
    p1.swap(p2);
    cout << "Sau khi hoán đổi, p1: (" << p1.first << ", " << p1.second << ")\n";
    cout << "Sau khi hoán đổi, p2: (" << p2.first << ", " << p2.second << ")\n";
    
    return 0;
}