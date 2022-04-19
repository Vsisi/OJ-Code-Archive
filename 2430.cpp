//correct algorithm(state compression dp) in general, but don't know why it was TLE
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int MAXB = 15000000 + 100;
const int MAXN = 1100;
int dp[2][MAXN][5] = {0};
bool hasCow[3][MAXB];
bool p = 0;
const int INF = 0x3fffffff;
int read() {
    int s = 0, w = 1;
    char ch = getchar(); //getchar() 一次从键盘读入一个字符
    while (ch <='0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}
int main() {
    int n = read(), k = read(), b=read();
    int x, y;
    int maxY = 0;
    for(int i = 0; i < n; i++) {
        x = read();
        y = read();
        hasCow[x][y] = true;
        maxY = max(maxY, y);
    }
    dp[!p][0][0] = 0; dp[!p][0][1] = INF;
    dp[!p][0][2] = INF; dp[!p][0][3] = INF; dp[!p][0][4] = INF;
    dp[!p][1][0] = INF; dp[!p][1][1] = INF; 
    dp[!p][1][2] = INF; dp[!p][1][3] = INF; dp[!p][1][4] = INF;
    dp[!p][2][0] = INF; dp[!p][2][1] = INF;
    dp[!p][2][2] = INF; dp[!p][2][3] = INF; dp[!p][2][4] = INF;
    for(int i = 0; i < 2; i++) {
        dp[i][0][1] = dp[i][0][2] = dp[i][0][3] = dp[i][0][4] = INF;
    }
    for(int i = 1; i <= maxY + 1; i++) {
        for(int j = 1; j <= min(k, 2 * i); j++) {
            if(!hasCow[1][i] && !hasCow[2][i]) {   
                //0
                //0
                dp[p][j][0] = min(
                    min(
                        min(dp[!p][j][0], dp[!p][j][1]), 
                        min(dp[!p][j][2], dp[!p][j][3])
                    ),
                    dp[!p][j][4]
                );
                dp[p][j][1] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j][1]),
                        min(dp[!p][j-1][2], dp[!p][j-1][3])
                    ),
                    min(dp[!p][j][4], dp[!p][j-1][1])
                ) + 1;
                dp[p][j][2] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j][2], dp[!p][j-1][3])
                    ),
                    min(dp[!p][j][4], dp[!p][j-1][2])
                ) + 1;
                dp[p][j][3] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j-1][2], dp[!p][j][3])
                    ),
                    min(dp[!p][j-1][4], dp[!p][j-1][3])
                ) + 2;
                dp[p][j][4] = min(
                    min(dp[!p][j-1][1], dp[!p][j-1][2]),
                    min(
                        dp[!p][j][4],
                        j-2 >=0 ? min(
                            min(dp[!p][j-2][0], dp[!p][j-2][3]),
                            min(
                                min(dp[!p][j-2][1], dp[!p][j-2][2]),
                                dp[!p][j-2][4])) : INF
                    )
                ) + 2;
            }else if(!hasCow[1][i] && hasCow[2][i]) {
                //0
                //1
                dp[p][j][0] = INF;
                dp[p][j][1] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j][1]),
                        min(dp[!p][j-1][2], dp[!p][j-1][3])
                    ),
                    min(dp[!p][j][4], dp[!p][j-1][1])
                );
                dp[p][j][2] = INF;
                dp[p][j][3] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j-1][2], dp[!p][j][3])
                    ),
                    min(dp[!p][j-1][4], dp[!p][j-1][3])
                ) + 1;
                dp[p][j][4] = min(
                    min(dp[!p][j-1][1], dp[!p][j-1][2]),
                    min(
                        dp[!p][j][4],
                        j-2 >=0 ? min(
                            min(dp[!p][j-2][0], dp[!p][j-2][3]),
                            min(
                                min(dp[!p][j-2][1], dp[!p][j-2][2]),
                                dp[!p][j-2][4])) : INF
                    )
                ) + 1;
            }else if(hasCow[1][i] && !hasCow[2][i]) {
                //1
                //0
                dp[p][j][0] = INF;
                dp[p][j][1] = INF;
                dp[p][j][2] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j][2], dp[!p][j-1][3])
                    ),
                    min(dp[!p][j][4], dp[!p][j-1][2])
                );
                dp[p][j][3] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j-1][2], dp[!p][j][3])
                    ),
                    min(dp[!p][j-1][4], dp[!p][j-1][3])
                ) + 1;
                dp[p][j][4] = min(
                    min(dp[!p][j-1][1], dp[!p][j-1][2]),
                    min(
                        dp[!p][j][4],
                        j-2 >=0 ? min(
                            min(dp[!p][j-2][0], dp[!p][j-2][3]),
                            min(
                                min(dp[!p][j-2][1], dp[!p][j-2][2]),
                                dp[!p][j-2][4])) : INF
                    )
                ) + 1;
            }else {//state == 3
                //1
                //1
                dp[p][j][0] = INF;
                dp[p][j][1] = INF;
                dp[p][j][2] = INF;
                dp[p][j][3] = min(
                    min(
                        min(dp[!p][j-1][0], dp[!p][j-1][1]),
                        min(dp[!p][j-1][2], dp[!p][j][3])
                    ),
                    min(dp[!p][j-1][4], dp[!p][j-1][3])
                );
                dp[p][j][4] = min(
                    min(dp[!p][j-1][1], dp[!p][j-1][2]),
                    min(
                        dp[!p][j][4],
                        j-2 >=0 ? min(
                            min(dp[!p][j-2][0], dp[!p][j-2][3]),
                            min(
                                min(dp[!p][j-2][1], dp[!p][j-2][2]),
                                dp[!p][j-2][4])) : INF
                    )
                );
            }
        }
        if(hasCow[1][i] || hasCow[2][i]) {
            dp[0][0][0] = INF;
            dp[1][0][0] = INF;
        }
        p = !p;
    }
    cout << dp[!p][k][0] + n;
    return 0;
}
