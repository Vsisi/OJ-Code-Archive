#include<bits/stdc++.h>
using namespace std;
vector<string> decompose(string org) {
    string temp = "";
    vector<string> res;
    for(int i = 0; i < org.size(); ) {
        if(isdigit(org[i])) {
            temp = org[i];
            for(int j = i+1; j < org.size(); j++) {
                if(isdigit(org[j]) || org[j] == '.') {
                    temp.push_back(org[j]);
                }else {
                    i = j;
                    break;
                }
            }
        }else {
            temp = org[i];
            i++;
        }
        res.push_back(temp);
    }
    return res;
}
double str2dbl(string x) {
    double res;
    stringstream ss;
    ss << x;
    ss >> res;
    return res;
}
int cmp(string opr) {
    if(opr == "+" || opr == "-") {
        return 0;
    }
    if(opr == "*" || opr == "/") {
        return 1;
    }
    return -1;
}
double compute(double a, double b, string opr) {
    if(opr == "+") {
        return a+b;
    }else if(opr == "-") {
        return a-b;
    }else if(opr == "*") {
        return a*b;
    }else if(opr == "/") {
        return a/b;
    }
    return -1;
}
double calc(const vector<string>& expr) {
    stack<double> num;
    stack<string> opr;
    double a, b;
    string o;
    for(auto word:expr) {
        if(isdigit(word[0])) { //number
            num.push(str2dbl(word));
        }else {//operator
            if(word == "(") {
                opr.push(word);
            }else if(word == ")") {
                while(opr.top() != "(") {
                    b = num.top(); num.pop();
                    a = num.top(); num.pop();
                    o = opr.top(); opr.pop();
                    num.push(compute(a, b, o));
                }
                opr.pop();
            }else if(word != "_") {
                if(!opr.empty() && cmp(opr.top()) >= cmp(word)) {
                    b = num.top(); num.pop();
                    a = num.top(); num.pop();
                    o = opr.top(); opr.pop();
                    num.push(compute(a, b, o));
                }
                opr.push(word);
            }else { //is _, EOE
                while(!opr.empty()) {
                    b = num.top(); num.pop();
                    a = num.top(); num.pop();
                    o = opr.top(); opr.pop();
                    num.push(compute(a, b, o));
                }
            }
        }
    }
    return num.top();
}
int main() {
    string str;
    cin >> str;
    str += "_";
    vector<string> expr = decompose(str);
    printf("%.2lf", calc(expr));
    return 0;
}
