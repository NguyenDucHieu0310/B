/* HO VA TEN: TRUONG VAN HIEN
MSSV: 20194276
Lop thuc hanh: 710817 */

#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x){
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input(){
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i)
    {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

const double UP = 15.0;
const double DOWN = -15.0;
const long delta = 400000;
double a[delta + 5];
double dist = (UP - DOWN) / delta;
double k, ratioo;
inline double exponent(double x){
    double result = 1.0;
    double eps = 5e-7;
    double extra = x;
    double n = 1;
    while (fabs(extra) > eps){
        result += extra;
        n += 1;
        extra *= x;
        extra /= n;
    }
    return result;
}

void precalc(){
    a[0] = DOWN;

    for (long i = 1; i <= delta; i++){
        a[i] = a[i - 1] + dist;
    }
    for (long i = 0; i <= delta; i++){
        a[i] = 1 / (1 + exponent(-a[i]));
    }
}

inline double sigmoid_fast(double x){
    if (x > UP)
        return 1.0;
    else if (x < DOWN)
        return 0.0;
    else{
        k = floor((x - DOWN) / dist);
        ratioo = (x - DOWN) / dist - k;
        long p = (long)k;
        return a[p] + (a[p + 1] - a[p]) * ratioo;
    }
}

double benchmark(double (*calc)(double), vector<double> &result){
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t){
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i){
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0)
                result.push_back(v);
            if ((++input_id) == NUM_INPUTS)
                input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b){
    const double EPS = 1e-6;

    if (a.size() != b.size())
        return false;
    for (unsigned int i = 0; i < a.size(); ++i){
        if (fabs(a[i] - b[i]) > EPS){
            return false;
        }
    }
    return true;
}

int main(){
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    bool isCorrect = is_correct(a, b);

    if (isCorrect && (slow / fast > 1.3)){
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    else{
        printf("Wrong answer or your code is not fast enough!\n");
    }
    return 0;
}