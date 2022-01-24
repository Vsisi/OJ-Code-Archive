#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;

const string EOO = "END OF OUTPUT.";
const double PI = 3.1415926;
const int LOSS_PER_YEAR = 50 * 2;

void formattedPrint(int year);
double disSquare(double x, double y);

int main() {
    int N;
    double x, y;
    cin >> N;
    while(N--) {
        cin >> x >> y;
        double totLoss = disSquare(x, y) * PI;
        formattedPrint(ceil(totLoss / LOSS_PER_YEAR));
    }

    cout << EOO;
    return 0;
}

double disSquare(double x, double y) {
    return x*x + y*y;
}
void formattedPrint(int year) {
    static int count = 1;
    printf("Property %d: This property will begin eroding in year %d.\n", count++, year);
}
