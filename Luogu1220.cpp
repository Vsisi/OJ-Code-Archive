#include<bits/stdc++.h>
using namespace std;
const int N = 55;
const int INF = 0x3f3f3f3f;
struct State{
    State(int pos=0, int wRemain=INF, int minVal=INF):pos(pos), wRemain(wRemain), minVal(minVal) {}
    int pos;
    int wRemain;
    int minVal;
};
State dp[N][N][N]; //j - j+i(len)-1, stay in k
int lamp[N];
int pos[N], watt[N];
int main() {
    int n, c;
    cin >> n >> c;
    int totWatt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> pos[i] >> watt[i];
        totWatt += watt[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                dp[i][j][k] = State(0, INF, INF);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[1][i][i] = State(i, totWatt - watt[i], totWatt * abs(pos[c] - pos[i]));
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n + 1 - i; j++) {
            if(dp[i-1][j][j].minVal + dp[i-1][j][j].wRemain * abs(pos[dp[i-1][j][j].pos] - pos[j+i-1]) < dp[i][j][j+i-1].minVal) {
                dp[i][j][j+i-1].pos = j+i-1;
                dp[i][j][j+i-1].wRemain = dp[i-1][j][j].wRemain - watt[i+j-1];
                dp[i][j][j+i-1].minVal = dp[i-1][j][j].minVal + dp[i-1][j][j].wRemain * abs(pos[dp[i-1][j][j].pos] - pos[j+i-1]);
            }
            if(dp[i-1][j][j+i-2].minVal + dp[i-1][j][j+i-2].wRemain * abs(pos[dp[i-1][j][j+i-2].pos] - pos[j+i-1]) < dp[i][j][j+i-1].minVal) {
                dp[i][j][j+i-1].pos = j+i-1;
                dp[i][j][j+i-1].wRemain = dp[i-1][j][j+i-2].wRemain - watt[i+j-1];
                dp[i][j][j+i-1].minVal = dp[i-1][j][j+i-2].minVal + dp[i-1][j][j+i-2].wRemain * abs(pos[dp[i-1][j][j+i-2].pos] - pos[j+i-1]);
            }
            if(dp[i-1][j+1][j+1].minVal + dp[i-1][j+1][j+1].wRemain * abs(pos[dp[i-1][j+1][j+1].pos] - pos[j]) < dp[i][j][j].minVal) {
                dp[i][j][j].pos = j;
                dp[i][j][j].wRemain = dp[i-1][j+1][j+1].wRemain - watt[j];
                dp[i][j][j].minVal = dp[i-1][j+1][j+1].minVal + dp[i-1][j+1][j+1].wRemain * abs(pos[dp[i-1][j+1][j+1].pos] - pos[j]);
            }
            if(dp[i-1][j+1][j+i-1].minVal + dp[i-1][j+1][j+i-1].wRemain * abs(pos[dp[i-1][j+1][j+i-1].pos] - pos[j]) < dp[i][j][j].minVal) {
                dp[i][j][j].pos = j;
                dp[i][j][j].wRemain = dp[i-1][j+1][j+i-1].wRemain - watt[j];
                dp[i][j][j].minVal = dp[i-1][j+1][j+i-1].minVal + dp[i-1][j+1][j+i-1].wRemain * abs(pos[dp[i-1][j+1][j+i-1].pos] - pos[j]);
            }
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n+1-i; j++) {
    //         cout << j << " " << i+j-1 << endl;
    //         cout << pos[j] << " " << watt[i+j-1] << endl;
    //         cout << dp[i][j].pos << " " << dp[i][j].wRemain << " " << dp[i][j].minVal << endl << endl;
    //     }
    //     system("pause");
    // }
    cout << min(dp[n][1][1].minVal, dp[n][1][n].minVal);
    return 0;
}
