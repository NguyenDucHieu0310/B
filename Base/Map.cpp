#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main() {
    // 1. Khởi tạo map
    map<int, string> m; // Map lưu cặp key (int) - value (string)

    // 2. insert() - Chèn phần tử
    m.insert({1, "One"}); // Chèn cặp {1, "One"}
    m.insert(make_pair(2, "Two")); // Cách khác để chèn
    pair<map<int, string>::iterator, bool> result = m.insert({3, "Three"}); // Lưu kết quả chèn
    cout << "Inserted key 3: " << (result.second ? "Success" : "Failed") << endl;

    // Thử chèn key đã tồn tại
    result = m.insert({1, "NewOne"}); // Sẽ thất bại vì key 1 đã có
    cout << "Inserted key 1 again: " << (result.second ? "Success" : "Failed") << endl;

    // 3. emplace() - Chèn phần tử tại chỗ (hiệu quả hơn insert)
    m.emplace(4, "Four"); // Chèn cặp {4, "Four"}
    m.emplace_hint(m.begin(), 5, "Five"); // Chèn với gợi ý vị trí

    // 4. operator[] - Truy cập hoặc chèn
    m[6] = "Six"; // Chèn hoặc cập nhật value cho key 6
    cout << "Value of key 6: " << m[6] << endl;

    // 5. at() - Truy cập value, ném ngoại lệ nếu key không tồn tại
    try {
        cout << "Value of key 4: " << m.at(4) << endl;
        cout << "Value of key 7: " << m.at(7) << endl; // Sẽ ném ngoại lệ
    } catch (const out_of_range& e) {
        cout << "Error: Key not found" << endl;
    }

    // 6. size() - Kích thước map
    cout << "Size of map: " << m.size() << endl;

    // 7. empty() - Kiểm tra map rỗng
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 8. find() - Tìm phần tử theo key
    auto it = m.find(3);
    if (it != m.end()) {
        cout << "Found key 3 with value: " << it->second << endl;
    } else {
        cout << "Key 3 not found" << endl;
    }

    // 9. count() - Đếm số lần xuất hiện của key (0 hoặc 1 trong map)
    cout << "Count of key 2: " << m.count(2) << endl;
    cout << "Count of key 7: " << m.count(7) << endl;

    // 10. lower_bound() - Iterator đến phần tử có key >= k
    it = m.lower_bound(3);
    if (it != m.end()) {
        cout << "Lower bound of key 3: " << it->first << " -> " << it->second << endl;
    }

    // 11. upper_bound() - Iterator đến phần tử có key > k
    it = m.upper_bound(3);
    if (it != m.end()) {
        cout << "Upper bound of key 3: " << it->first << " -> " << it->second << endl;
    }

    // 12. equal_range() - Trả về cặp iterator cho phạm vi [lower_bound, upper_bound)
    auto range = m.equal_range(3);
    if (range.first != m.end()) {
        cout << "Equal range of key 3: " << range.first->first << " -> " << range.first->second << endl;
    }

    // 13. erase() - Xóa phần tử
    m.erase(2); // Xóa key 2
    cout << "After erasing key 2, size: " << m.size() << endl;

    // Xóa bằng iterator
    it = m.find(5);
    if (it != m.end()) {
        m.erase(it);
        cout << "Erased key 5" << endl;
    }

    // Xóa phạm vi
    m.erase(m.begin(), m.find(4)); // Xóa từ đầu đến trước key 4
    cout << "After erasing range, size: " << m.size() << endl;

    // 14. clear() - Xóa toàn bộ map
    m.clear();
    cout << "After clear, size: " << m.size() << endl;
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 15. swap() - Hoán đổi nội dung hai map
    map<int, string> otherMap = {{10, "Ten"}, {11, "Eleven"}};
    m.swap(otherMap);
    cout << "After swap, m size: " << m.size() << endl;
    cout << "m content: ";
    for (const auto& p : m) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    // 16. begin(), end(), rbegin(), rend() - Iterator
    cout << "Forward iteration: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;

    cout << "Reverse iteration: ";
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;

    // 17. key_comp() và value_comp() - So sánh key hoặc value
    auto keyComp = m.key_comp();
    cout << "Key comparison (10 < 11): " << keyComp(10, 11) << endl;

    return 0;
}