// ### ĐỀ BÀI: BÀI TOÁN CÁI TÚI 0/1 (KNAPSACK)

// Có **n** đồ vật, đồ vật thứ `i` có:  
// - trọng lượng (hoặc thể tích) là `w[i]`,  
// - giá trị là `v[i]`.  

// Một chiếc ba lô có sức chứa tối đa **V**.  
// Hãy chọn một tập các đồ vật đưa vào ba lô sao cho:  
// - Tổng trọng lượng các đồ vật không vượt quá **V**,  
// - Tổng giá trị là **lớn nhất có thể**.  

// #### Input  
// - Dòng 1: Hai số nguyên `n`, `V` (1 ≤ n ≤ 1000, 1 ≤ V ≤ 1000).  
// - Dòng 2: `n` số nguyên `w[1], w[2], ..., w[n]` — trọng lượng của các đồ vật.  
// - Dòng 3: `n` số nguyên `v[1], v[2], ..., v[n]` — giá trị của các đồ vật.  

// #### Output  
// - Một số nguyên duy nhất — giá trị lớn nhất có thể đạt được.  

// ---

// #### Ví dụ  

// Input  
// 4 7  
// 1 3 4 5  
// 1 4 5 7  

// Output  
// 9  


#include <bits/stdc++.h>
using namespace std;

// Bai toan cai tui (0-1 Knapsack)

int main()
{
    int n, V; // n: so luong do vat, V the tich cai tui
    cin >> n >> V;
    int w[n + 1], v[n + 1]; // w: the tich cac do vat, v: gia tri cua cac do vat
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; // trong luong cac do vat
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; // gia tri cac do vat
    }

    int res[n + 1][V + 1]; // res[n][V] la dap an cua bai toan
    // res[i][j]: gia tri lon nhat cua cai tui co trong luong la j, bằng cách lựa chọn các đồ vật 1 đến đồ vật i;
    memset(res, 0, sizeof(res));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            res[i][j] = res[i - 1][j]; // khong lua chon do vat vao tui
            if (j >= w[i]) { // neu tui con co the dua do vat thu i vao
                res[i][j] = max(res[i][j], res[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << res[n][V] << endl;
    return 0;
}