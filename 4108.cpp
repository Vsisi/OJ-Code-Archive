#include<bits/stdc++.h>
using namespace std;
long long year3[100], year0[100], year1[100], year2[100];
void init() {
    year0[0] = 1;
    int tempY0, tempY1, tempY2, tempY3;
    for(int i = 1; i <= 50; i++) {
        tempY0 = year0[i-1];
        tempY1 = year1[i-1];
        tempY2 = year2[i-1];
        tempY3 = year3[i-1];
        year3[i] = tempY3 + tempY2;
        year0[i] = year3[i];
        year1[i] = tempY0;
        year2[i] = tempY1;
    }
}
int main() {
    int m;
    cin >> m;
    int year;
    init();
    while(m--) {
        cin >> year;
        cout << year3[year] + year1[year] + year2[year] + year0[year] << endl;
    }
    return 0;
}
