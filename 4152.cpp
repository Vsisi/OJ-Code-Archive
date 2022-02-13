#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class BigInt{
private:
    string x;
public:
    BigInt() {
        x = "0";
    }
    BigInt(string x) {
        this->x = x;
    }
    int length() {
        return x.length();
    }
    BigInt substr(int start, int len) {
        return BigInt(x.substr(start, len));
    }
    BigInt operator+(const BigInt& otherBI) {
        string other = otherBI.x;
        string a = x.length() > other.length() ? x : other;
        string b = x.length() <= other.length() ? x : other;
        // a.length() > b
        string tempStr = "";
        for(int i = 0; i < a.length()-b.length(); i++) {
            tempStr += "0";
        }
        b = tempStr + b;

        int carry = 0;
        int tempSum;
        string sum = "";
        for(int i = b.length()-1; i >= 0; i--) {
            tempSum = a[i] + b[i] + carry - '0' - '0';
            if(tempSum < 10) {
                carry = 0;
                sum.push_back(tempSum + '0');
            }else {
                carry = 1;
                sum.push_back(tempSum - 10 + '0');
            }
        }
        if(carry) {
            sum.push_back('1');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
    BigInt& operator=(const BigInt& other) {
        x = other.x;
        return *this;
    }
    bool operator>(const BigInt& otherBI) {
        string other = otherBI.x;
        if(x.length() > other.length()) {
            return true;
        }
        if(x.length() < other.length()) {
            return false;
        }
        for(int i = 0; i < other.length(); i++) {
            if(x[i] > other[i]) {
                return true;
            }
            if(x[i] < other[i]) {
                return false;
            }
        }
        return false;
    }
    string getX(){
        return x;
    }
};
int getSublen(int n, int plus) {
    int temp = n/(plus+1);
    return abs(n - temp*(plus+1)) <= abs(n - (plus+1)*(temp+1)) ? temp : temp+1;
}
BigInt dp[60][60];
// #define DEBUG
BigInt solve(BigInt bi, int plus) {
    int len = bi.length();

    for(int i = 1; i <= len; i++) {
        for(int j = 0; j <= plus; j++) {
            dp[i][j] = bi.substr(0, i); //init
        }
    }
    
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= plus; j++) {
            for(int k = 1; k < i; k++) {
                // cout << i << " " << k << " " << j <<  endl;
                // cout << dp[i][j].getX() << " " << dp[k][j-1].getX() << " " << bi.substr(k, i-k).getX() << endl;
                // system("pause");
                if(dp[i][j] > dp[k][j-1] + bi.substr(k, i-k)) {
                    dp[i][j] = dp[k][j-1] + bi.substr(k, i-k);
                }
            }
        }
    }


    return dp[len][plus];
}
int main() {
    int n;
    string str;
    while(1) {
        if(scanf("%d", &n) == EOF) exit(0);
        cin >> str;
        cout << solve(BigInt(str), n).getX() << endl;
    }
    return 0;
}
