#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
inline char addChar(char a, char b, int& carry);
inline char multiChar(char a, char b, int& carry);
inline void splitString(string src, string& tgt, int startExact, int endExact);
inline void splitIntDec(string x, string& integer, string& decimal);
inline int getDecimalDigit(const string& realNum, int power);

vector<string> mediateRes;
void realNumPower(const string& realNum, int power) {
    int decimalDigit = getDecimalDigit(realNum, power);

    string mInt, mDec;
    splitIntDec(realNum, mInt, mDec);
    string mInteger = mInt + mDec;//get rid of decimal point
    string m1 = mInteger, m2 = mInteger;
    string temp = "";
    int m1Len, m2Len = m2.size();
    int carry = 0;
    string tempMRes = "";
    power--;
    while(power--) {
        m1Len = m1.size();
        mediateRes.clear();
        for(int i = m2Len - 1; i >= 0; i--) {
            tempMRes = "";
            carry = 0;
            for(int j = m1Len - 1; j >=0; j--) {
                tempMRes += multiChar(m2[i], m1[j], carry);
            }
            if(carry != 0) {
                tempMRes += carry + '0';
            }
            mediateRes.push_back(tempMRes);
        }
        int offset = 0;
        int alignedPos;
        for(auto mRes:mediateRes) {
            carry = 0;
            for(int i = 0; i < mRes.length(); i++) {
                alignedPos = offset + i;
                if(alignedPos < temp.length()) {
                    temp[alignedPos] = addChar(mRes[i], temp[alignedPos], carry);
                }else {
                    temp += addChar(mRes[i], '0', carry);
                }
            }
            if(carry != 0) {
                temp += carry + '0';
            }
            offset++;
        }

        reverse(temp.begin(), temp.end());
        m1 = temp;
        temp = "";
    }
    bool backZero = true;
    string res = "";
    for(int i = m1.length() - 1; i >= 0; i--) {
        if(backZero && m1[i] == '0' && decimalDigit >= m1.length() - i) {
            continue;
        }
        backZero = false;
        res += m1[i];
        if(i == m1.length() - decimalDigit) {
            res += '.' ;
        }
    }
    reverse(res.begin(), res.end());
    if(res[0] == '0') {
        for(int i = 0; i < res.length()-1; i++) {
            res[i] = res[i+1];
        }
        res.pop_back();
    }
    cout << res << endl;
}
inline void process() {
    string realNum;
    int power;
    while(cin >> realNum >> power) {
        realNumPower(realNum, power);
    }
}
int main() {
    process();
    return 0;
}


char addChar(char a, char b, int& carry) {
    int res = a + b + carry - '0' - '0';
    carry = 0;
    while(res >= 10) {
        res -= 10;
        carry++;
    }
    return res + '0';
}
char multiChar(char a, char b, int& carry) {
    int temp = (a - '0') * (b - '0') + carry;
    carry = 0;
    while(temp >= 10) {
        temp -= 10;
        carry ++;
    }
    return temp + '0';
}
void splitString(string src, string& tgt, int startExact, int endExact) {
    tgt.clear();
    for(int i = startExact; i < endExact; i++) {
        tgt += src[i];
    }
    return;
}
void splitIntDec(string x, string& integer, string& decimal) {
    integer = "";
    decimal = "";
    int len = x.size();
    int dpPos = len;
    for(int i = 0; i < len; i++) {
        if(x[i] == '.') {
            dpPos = i;
            break;
        }
    }
    splitString(x, integer, 0, dpPos);
    splitString(x, decimal, dpPos + 1, len);
    return;
}
int getDecimalDigit(const string& realNum, int power) {
    int len = realNum.size();
    int dpPos = len-1;
    for(int i = 0; i < len; i++) {
        if(realNum[i] == '.') {
            dpPos = i;
            break;
        }
    }
    return (len -1 - dpPos) * power;
}
