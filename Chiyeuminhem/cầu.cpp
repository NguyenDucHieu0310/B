#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Chuyển độ sang radian
double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Tính khoảng cách Haversine giữa hai điểm (lat1, lon1) và (lat2, lon2)
double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    // Không cần nhân với bán kính trái đất vì chỉ so sánh tương đối
    return c;
}

int main() {
    int n;
    cin >> n; // Số sân bay
    
    // Lưu danh sách tọa độ sân bay
    vector<pair<double, double>> airports(n);
    for (int i = 0; i < n; ++i) {
        cin >> airports[i].first >> airports[i].second; // Vĩ độ, kinh độ
    }
    
    double minMaxDistance = 1e9; // Khoảng cách tối đa nhỏ nhất
    pair<double, double> bestHub; // Tọa độ sân bay hub tối ưu
    
    // Duyệt qua từng sân bay làm hub
    for (int i = 0; i < n; ++i) {
        double maxDistance = 0.0; // Khoảng cách tối đa từ sân bay i đến sân bay khác
        
        // Tính khoảng cách từ sân bay i đến tất cả sân bay khác
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double dist = haversineDistance(
                    airports[i].first, airports[i].second,
                    airports[j].first, airports[j].second
                );
                maxDistance = max(maxDistance, dist);
            }
        }
        
        // Cập nhật nếu maxDistance nhỏ hơn minMaxDistance hiện tại
        if (maxDistance < minMaxDistance) {
            minMaxDistance = maxDistance;
            bestHub = airports[i];
        }
    }
    
    // In kết quả, làm tròn đến 2 chữ số thập phân
    cout << fixed << setprecision(2);
    cout << bestHub.first << " " << bestHub.second << endl;
    
    return 0;
}