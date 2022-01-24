#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;

const int MONTH = 12;

int main() {
    double leftover;
    double sum = 0;
    for(int i = 0; i < MONTH; i++) {
        cin >> leftover;
        sum += leftover;
    }
    printf("$%.2lf", sum / MONTH);
    return 0;
}
