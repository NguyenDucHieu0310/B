#include <iostream>
#include <chrono>
#include <thread>

// Hàm để xóa màn hình (chỉ hoạt động trên một số hệ thống hỗ trợ escape sequence)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";  // Escape sequence để xóa màn hình
}

// Hàm để in ra từng ký tự với hiệu ứng dần dần
void printWithDelay(const std::string& text, int delay_ms) {
    for (char c : text) {
        std::cout << c; // In từng ký tự
        std::cout.flush(); // Đảm bảo in ra ngay lập tức
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms)); // Tạo độ trễ
    }
}

// Hàm in hình hoa và lời chúc
void printFlowerAndGreeting() {
    clearScreen();

    // In phần hoa với màu đỏ
    std::cout << "\033[1;31m"; // Màu đỏ cho hoa
    printWithDelay("            -=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-\n", 30);
    printWithDelay("\n", 30);
    printWithDelay("              __        __        __        __\n", 30);
    printWithDelay(" .*.        /~ .~\\    /~  ~\\    /~ .~\\    /~  ~\\\n", 30);
    printWithDelay(" ***       '      `\\/ '     *  '      `\\/ '     *\n", 30);
    printWithDelay("  V       (                .*)(               . *)\n", 30);
    printWithDelay("/\\|/\\      \\     \033[1;35mQuang\033[1;31m  . *./  \\       \033[1;35mTam\033[1;31m   . *./ \n", 30);
    printWithDelay("  |         `\\ .      . .*/'    `\\ .      . .*/'       .*.\n", 30);
    printWithDelay("  |           `\\ * .*. */' _    _ `\\ * .*. */'         ***\n", 30);
    printWithDelay("                `\\ * */'  ( `\\/'*)   `\\ * */'         /\\V\n", 30);
    printWithDelay("                  `\\/ '    \\   */'     `\\/ '            |/\\\n", 30);
    printWithDelay("                            `\\/ '                       |\n", 30);
    printWithDelay("\n", 30);

    // In lời chúc với màu sắc
    std::cout << "\033[1;37m"; // Thiết lập màu trắng cho chữ
    printWithDelay("  Chuc \033[1;35mBe iu\033[1;37m ngay 20-10 that vui ve, iu be nhiuuuu\033[1;35m moa moa moa \n", 50);
    std::cout << "\033[1;33m"; // Thiết lập màu vàng cho hình trái tim
    printWithDelay("                         moa moa moa \n", 50);
    std::cout << "\033[0m"; // Quay lại màu mặc định
}

int main() {
    // In ra hình hoa và lời chúc
    printFlowerAndGreeting();

    return 0;
}
