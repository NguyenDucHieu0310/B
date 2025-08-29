#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>

using namespace std;

int main() {
    // 1. Khởi tạo unordered_map
    unordered_map<int, string> m; // Lưu cặp key (int) - value (string)

    // 2. insert() - Chèn phần tử
    m.insert({1, "One"}); // Chèn cặp {1, "One"}
    m.insert(make_pair(2, "Two")); // Cách khác để chèn
    pair<unordered_map<int, string>::iterator, bool> result = m.insert({3, "Three"});
    cout << "Inserted key 3: " << (result.second ? "Success" : "Failed") << endl;

    // Thử chèn key đã tồn tại
    result = m.insert({1, "NewOne"}); // Sẽ thất bại vì key 1 đã có
    cout << "Inserted key 1 again: " << (result.second ? "Success" : "Failed") << endl;

    // 3. emplace() - Chèn phần tử tại chỗ
    m.emplace(4, "Four"); // Chèn cặp {4, "Four"}
    m.emplace_hint(m.begin(), 5, "Five"); // Chèn với gợi ý (ít hiệu quả với unordered_map)

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

    // 6. size() - Kích thước unordered_map
    cout << "Size of unordered_map: " << m.size() << endl;

    // 7. empty() - Kiểm tra unordered_map rỗng
    cout << "Is unordered_map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 8. find() - Tìm phần tử theo key
    auto it = m.find(3);
    if (it != m.end()) {
        cout << "Found key 3 with value: " << it->second << endl;
    } else {
        cout << "Key 3 not found" << endl;
    }

    // 9. count() - Đếm số lần xuất hiện của key (0 hoặc 1)
    cout << "Count of key 2: " << m.count(2) << endl;
    cout << "Count of key 7: " << m.count(7) << endl;

    // 10. erase() - Xóa phần tử
    m.erase(2); // Xóa key 2
    cout << "After erasing key 2, size: " << m.size() << endl;

    // Xóa bằng iterator
    it = m.find(5);
    if (it != m.end()) {
        m.erase(it);
        cout << "Erased key 5" << endl;
    }

    // 11. clear() - Xóa toàn bộ unordered_map
    m.clear();
    cout << "After clear, size: " << m.size() << endl;
    cout << "Is unordered_map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 12. swap() - Hoán đổi nội dung hai unordered_map
    unordered_map<int, string> otherMap = {{10, "Ten"}, {11, "Eleven"}};
    m.swap(otherMap);
    cout << "After swap, m size: " << m.size() << endl;
    cout << "m content: ";
    for (const auto& p : m) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    // 13. begin(), end(), cbegin(), cend() - Iterator
    cout << "Forward iteration: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;

    // 14. bucket_count() - Số bucket trong bảng băm
    cout << "Bucket count: " << m.bucket_count() << endl;

    // 15. bucket() - Bucket chứa key
    cout << "Bucket for key 10: " << m.bucket(10) << endl;

    // 16. load_factor() - Tỷ lệ tải (size / bucket_count)
    cout << "Load factor: " << m.load_factor() << endl;

    // 17. max_load_factor() - Tỷ lệ tải tối đa
    cout << "Max load factor: " << m.max_load_factor() << endl;
    m.max_load_factor(0.5); // Đặt lại max_load_factor
    cout << "New max load factor: " << m.max_load_factor() << endl;

    // 18. rehash() - Đặt lại số bucket
    m.rehash(20);
    cout << "After rehash, bucket count: " << m.bucket_count() << endl;

    // 19. reserve() - Dự trữ số phần tử
    m.reserve(100);
    cout << "After reserve, bucket count: " << m.bucket_count() << endl;

    // 20. hash_function() - Hàm băm
    auto hasher = m.hash_function();
    cout << "Hash of key 10: " << hasher(10) << endl;

    // 21. key_eq() - Hàm so sánh key
    auto keyEqual = m.key_eq();
    cout << "Key equality (10 == 10): " << keyEqual(10, 10) << endl;

    return 0;
}