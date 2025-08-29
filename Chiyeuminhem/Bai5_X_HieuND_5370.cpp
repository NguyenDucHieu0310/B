/*//Nguyen Duc Hieu-5370-732833
Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả về NULL.
*/
#include<bits/stdc++.h>
using namespace std;
double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    //Nguyen Duc Hieu-5370-732833
     for (int i = 1; i < size; i++) {
        if (a[i] > *max) {
            max = &a[i]; // Cập nhật con trỏ tới phần tử lớn nhất
        }
    }
    return max;
}