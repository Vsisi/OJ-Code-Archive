#include<bits/stdc++.h>
using namespace std;

const int daysHaab = 365;
const int daysTzolkin = 13 * 20;

map<string, int> haab;
string tzolkin[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

inline void init();
inline int str2Int(string str);
inline void convert(const int nod, const string m, const int year, int& resNum, string& resNod, int& resYear);


int main() {
    init();
    int n;
    cin >> n;
    string nodStr, m, resNod;
    int year, nod;
    int resNum,  resYear;
    vector<int> resNums, resYears;
    vector<string> resNods;
    while(n--) {
        cin >> nodStr >> m >> year;
        nodStr.pop_back();
        nod = str2Int(nodStr);

        convert(nod, m, year, resNum, resNod, resYear);

        resNums.push_back(resNum);
        resNods.push_back(resNod);
        resYears.push_back(resYear);
    }
    cout << resNums.size() << endl;

    if(resNums.size() != 0) {   
        for(int i = 0; i < resNums.size()-1; i++) {
            cout << resNums[i] << " " << resNods[i] << " " << resYears[i] << endl;
        }
            cout << resNums.back() << " " << resNods.back() << " " << resYears.back();
        }
    return 0;
}

void convert(const int nod, const string m, const int year, int& resNum, string& resNod, int& resYear) {
    int daysPassed = year * daysHaab + haab[m] * 20 + nod;
    // cout << daysPassed << endl;

    resNum = daysPassed % 13 + 1;

    resNod = tzolkin[daysPassed % 20];

    resYear = daysPassed / daysTzolkin;
    return;
}
int str2Int(string str) {
    stringstream ss;
    ss.clear();
    int res;
    ss << str;
    ss >> res;
    return res;
}
void init() {
    string haabMonths[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};
    for(int i = 0; i < 18; i++) {
        haab[haabMonths[i]] = i;
    }
    haab["uayet"] = 18;
}
