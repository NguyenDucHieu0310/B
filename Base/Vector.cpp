#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
    // 1. Khởi tạo vector
    vector<int> myVec; // Vector rỗng
    vector<int> vec1(5, 10); // Vector có 5 phần tử, mỗi phần tử là 10
    vector<int> vec2 = {1, 2, 3, 4, 5}; // Khởi tạo bằng initializer list
    vector<int> vec3(vec2.begin(), vec2.end()); // Khởi tạo từ iterator
    cout << "vec2: ";
    for (int x : vec2) cout << x << " ";
    cout << endl;

    // 2. push_back() - Thêm phần tử vào cuối
    myVec.push_back(100);
    myVec.push_back(200);
    cout << "After push_back, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 3. emplace_back() - Thêm phần tử tại chỗ vào cuối
    myVec.emplace_back(300); // Hiệu quả hơn push_back
    cout << "After emplace_back, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 4. pop_back() - Xóa phần tử cuối
    myVec.pop_back();
    cout << "After pop_back, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 5. insert() - Chèn phần tử
    myVec.insert(myVec.begin() + 1, 150); // Chèn 150 vào vị trí thứ 1
    myVec.insert(myVec.end(), 2, 400); // Chèn 2 số 400 vào cuối
    cout << "After insert, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 6. emplace() - Chèn phần tử tại chỗ
    myVec.emplace(myVec.begin(), 50); // Chèn 50 vào đầu
    cout << "After emplace, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 7. erase() - Xóa phần tử
    myVec.erase(myVec.begin() + 2); // Xóa phần tử tại vị trí 2
    myVec.erase(myVec.end() - 2, myVec.end()); // Xóa 2 phần tử cuối
    cout << "After erase, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 8. clear() - Xóa toàn bộ phần tử
    myVec.clear();
    cout << "After clear, size: " << myVec.size() << endl;

    // 9. size() - Kích thước vector
    myVec = {10, 20, 30, 40};
    cout << "Size of myVec: " << myVec.size() << endl;

    // 10. empty() - Kiểm tra vector rỗng
    cout << "Is myVec empty? " << (myVec.empty() ? "Yes" : "No") << endl;

    // 11. capacity() - Dung lượng hiện tại
    cout << "Capacity of myVec: " << myVec.capacity() << endl;

    // 12. reserve() - Dự trữ dung lượng
    myVec.reserve(10);
    cout << "After reserve(10), capacity: " << myVec.capacity() << endl;

    // 13. shrink_to_fit() - Giảm dung lượng về kích thước
    myVec.shrink_to_fit();
    cout << "After shrink_to_fit, capacity: " << myVec.capacity() << endl;

    // 14. resize() - Thay đổi kích thước
    myVec.resize(6, 50); // Mở rộng thành 6 phần tử, thêm 50 nếu cần
    cout << "After resize(6, 50), myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 15. operator[] - Truy cập phần tử
    cout << "Element at index 2: " << myVec[2] << endl;

    // 16. at() - Truy cập phần tử, ném ngoại lệ nếu ngoài phạm vi
    try {
        cout << "Element at index 3: " << myVec.at(3) << endl;
        cout << "Element at index 10: " << myVec.at(10) << endl;
    } catch (const out_of_range& e) {
        cout << "Error: Index out of range" << endl;
    }

    // 17. front(), back() - Truy cập phần tử đầu/cuối
    cout << "Front element: " << myVec.front() << endl;
    cout << "Back element: " << myVec.back() << endl;

    // 18. data() - Con trỏ đến mảng cơ sở
    int* arr = myVec.data();
    cout << "First element via data(): " << arr[0] << endl;

    // 19. begin(), end(), rbegin(), rend() - Iterator
    cout << "Forward iteration: ";
    for (auto it = myVec.begin(); it != myVec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse iteration: ";
    for (auto it = myVec.rbegin(); it != myVec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 20. assign() - Gán lại nội dung
    myVec.assign(3, 100); // Gán 3 phần tử, mỗi phần tử là 100
    cout << "After assign(3, 100), myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 21. swap() - Hoán đổi nội dung hai vector
    vector<int> otherVec = {7, 8, 9};
    myVec.swap(otherVec);
    cout << "After swap, myVec: ";
    for (int x : myVec) cout << x << " ";
    cout << endl;

    // 22. max_size() - Kích thước tối đa có thể
    cout << "Max size of vector: " << myVec.max_size() << endl;

    return 0;
}