
/*Nguyen Duc Hieu-5370-732833
Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].
*/
#include <bits/stdc++.h>
void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;
//Nguyen Duc Hieu-5370-732833
    while (l < r) {
        // Hoán đổi giá trị của arr[l] và arr[r]
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        // Di chuyển chỉ số l về phía trước và chỉ số r về phía sau
        l++;
        r--;
    }
}
void ptr_reversearray(int *arr, int size){
//Nguyen Duc Hieu-5370-732833
    int l = 0, r = size - 1, tmp;
    while(l < r){
        tmp = *(arr + l);
        *(arr + l) = *(arr + r);
        *(arr + r) = tmp;
        l++;
        r--;
    }
}