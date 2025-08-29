#include <iostream>
#include <string>

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), '0' + (sum % 10));
    }

    return result;
}

int main() {
    std::string num1_str, num2_str;

    // Take input from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1_str;

    std::cout << "Enter the second number: ";
    std::cin >> num2_str;

    std::string result_str = addStrings(num1_str, num2_str);

    std::cout << "Sum: " << result_str << std::endl;

    return 0;
}
