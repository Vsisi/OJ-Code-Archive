#include<bits/stdc++.h>
using namespace std;
void removeDashs(string& str);
void initTable(unordered_map<char, char>&);
bool isNewTel(string tel, map<string, int>& count);
void toPureNumber(string& tel, unordered_map<char, char>& tbl);
string toStdTel(const string& tel);

int main()
{
    unordered_map<char, char> * table = new unordered_map<char, char>();
    map<string, int> * count = new map<string, int>();
    initTable(*table);
    int n;
    cin >> n;
    string inputString;
    while(n--)
    {
        cin >> inputString;
        removeDashs(inputString);
        toPureNumber(inputString, *table);
        isNewTel(inputString, *count);
    }
    int cnt = 0;
    for(map<string, int>::iterator it = count->begin(); it != count->end(); it++) {
        if(it->second > 1) {
            cnt ++;
            cout << toStdTel(it->first) << " " << it->second << endl;
        }
    }
    if(cnt == 0) {
        cout << "No duplicates.";
    }
}


void removeDashs(string& str)
{
    string res = "";
    for(auto c:str)
    {
        if(c != '-')
        {
            res += c;
        }
    }
    str = res;
}
void initTable(unordered_map<char, char>& tbl)
{
    char val = '2';
    int cnt = 3;
    for(char letter = 'a'; letter <= 'y'; letter++)
    {
        if(letter == 'q')
        {
            continue;
        }
        tbl[letter] = val;
        tbl[letter - 'a' + 'A'] = val;
        cnt--;
        if(!cnt)
        {
            val++;
            cnt = 3;
        }
    }
}
bool isNewTel(string tel, map<string, int>& count) {
    if(count[tel] != 0) {
        count[tel]++;
        return false;
    }
    count[tel] = 1;
    return true;
}
void toPureNumber(string& tel, unordered_map<char, char>& tbl) {
    for(int i = 0; i < tel.length(); i++) {
        if(isalpha(tel[i])) {
            tel[i] = tbl[tel[i]];
        }
    }
}
string toStdTel(const string& tel) {
    string res = "";
    int cnt = 0;
    for(auto c:tel) {
        res += c;
        cnt++;
        if(cnt == 3) {
            res += '-';
        }
    }
    return res;
}
