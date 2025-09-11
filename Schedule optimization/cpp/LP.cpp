#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

double MIN = -1e18;
double MAX = 1e18;

class table {
public:
    int n, m;
    vector<vector<double>> A;
    vector<double> b, c;
    vector<int> B;

    table(
        vector<vector<double>> A, 
        vector<double> b, 
        vector<double> c, 
        vector<int> B): A(A), b(b), c(c), B(B) {

        n = c.size();
        m = b.size();
    };

    vector<double> get_delta() {
        vector<double> z(n, 0), delta(n, 0);
        // caculate z
        for (int j = 0; j < n; j++) {
            z[j] = 0;
            for (int i = 0; i < m; i++) {
                z[j] += c[B[i]]*A[i][j];
            }
        }

        // caculate delta
        for (int j = 0; j < n; j++) {
            delta[j] = c[j] - z[j];
        }

        return delta;
    }

    int get_pivot_col(vector<double> delta) {
        double res = MIN;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (delta[j] > 0 && delta[j] > res) {
                res = delta[j];
                index = j;
            }
        }

        return index; 
    }

    int get_pivot_row(int pivot_col) {
        double E = MAX;
        int row = -1;

        for (int i = 0; i < m; i++) {
            if (A[i][pivot_col] > 0 && b[i] / A[i][pivot_col] < E) {
                E = b[i] / A[i][pivot_col];
                row = i;
            }
        }

        return row;
    }

    void changeBase(int prow, int pcol) {
        B[prow] = pcol;
        double pivot = A[prow][pcol];

        // chuyen toa do ve 1
        for (int j = 0; j < n; j++) {
            A[prow][j] = A[prow][j] / pivot;
        }
        b[prow] = b[prow] / pivot;

        // tru cac hang di
        for (int i = 0; i < m; i++) {
            double ratio = A[i][pcol];
            if (i == prow || ratio == 0) continue;

            for (int j = 0; j < n; j++) {
                A[i][j] = A[i][j] - A[prow][j]*ratio;
            }

            b[i] = b[i] - b[prow]*ratio;
        }
    }

    int roll() {
        vector<double> delta = get_delta();

        int pcol = get_pivot_col(delta);
        if (pcol == -1) {
            return 1;
        }
        
        int prow = get_pivot_row(pcol);
        if (prow == -1) {
            return -1;
        }
        
        changeBase(prow, pcol);

        return 0;
    }

    vector<double> solve() {
        int flag = 0;

        while (flag == 0) {
            flag = roll();
        }
        
        if (flag == -1) {
            return vector<double>();
        }

        vector<double> solution(n, 0);
        for (int i = 0; i < m; i++) {
                solution[B[i]] = b[i];
        }

        return solution;
    }
};

int main() {
    int n, m;
    vector<vector<double>> A;
    vector<double> c, low, up, DL, DU;

    cin >> n >> m;
    A.assign(m, vector<double>(n, 0));
    c.assign(n, 0);

    for (int j = 0; j < n; j++) {
        cin >> DL[j] >> DU[j];
    }

    for (int j = 0; j < n; j++) {
        cin >> c[j];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> low[i] >> up[i];
    }

    // Phase 1
    vector<vector<double>> A1;
    vector<double> b1, c1;
    vector<int> B1;

    // TODO: create matrix and vector

    table T = table(A1, b1, c1, B1);

    vector<double> solution1 = T.solve();  

    // Phase 2
    vector<vector<double>> A2;
    vector<double> b2, c2;
    vector<int> B2;

    // TODO: create matrix and vector

    table T = table(A2, b2, c2, B2);

    vector<double> solution2 = T.solve();  

    if (solution2.size() == 0) {
        cout << "NOT_OPTIMAL";
    }  
    else {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << solution2[i] << ' ';
        }
    }


    return 0;
}