#include <iostream>
#include <string>

// Hàm nhân hai số nguyên lớn biểu diễn dưới dạng chuỗi
std::string multiplyLargeNumbers(const std::string& num1, const std::string& num2) {
    int m = num1.size();
    int n = num2.size();
    std::string result(m + n, '0');

    for (int i = m - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = n - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }

    // Loại bỏ các số 0 đầu tiên nếu có
    size_t pos = result.find_first_not_of('0');
    if (pos != std::string::npos) {
        return result.substr(pos);
    }

    return "0";
}

int main() {
    // Biểu diễn số nguyên lớn dưới dạng chuỗi
    std::string num1 = "1234";
    std::string num2 = "9876";

    // Nhân hai số nguyên lớn
    std::string result = multiplyLargeNumbers(num1, num2);

    // In kết quả
    std::cout << "Result: " << result << std::endl;

    return 0;
}
