//超大搜索，写吐了，标程都180多行
//oj还疯狂TLE，气炸了，结果是读入没结束？wqnmd，别的地方都好使的写法怎么来你这就拉了裤了？
#include<bits/stdc++.h>
using namespace std;
vector<int> denom;
void solve(int c);
vector<int> decompose(int mLeft, int sLeft, const vector<int>& idx, bool& tie, int& resMaxDenom);
// #define DEBUG_DECOMPOSE_S1
// #define DEBUG_DECOMPOSE_S2
// #define DEBUG_DECOMPOSE_S3
// #define DEBUG_SOLVE_S1
#define SUBMIT
class Combination{
public:
    Combination(int n, int r) {
        this->n = n;
        this->r = r;
    }
    bool getNext(vector<int>& c) {
        int j = -1;
        for(int i = this->r; i >= 1; i--) {
            if(c[i-1] < this->n - this->r + i) {
                j = i-1;
                break;
            }
        }
        if(j == -1) {
            return false;
        }
        c[j]++;
        for(int i = j+1; i < this->r; i++) {
            c[i] = c[i-1] + 1;
        }
        return true;
    }
    int getN() {
        return n;
    }
    int getR() {
        return r;
    }
private:
    int n, r;
};
int main() {
    int d, c;
    do{
        denom.clear();
        while(1) {
            if(scanf("%d", &d) == EOF) exit(0);
            if(d == 0) {
                break;
            }
            denom.push_back(d);
        }
        while(cin >> c) {
            if(c == 0) {
                break;
            }
            solve(c);
        }
    }while(1);
    return 0;
}
vector<int> decompose(int mLeft, int sLeft, const vector<int>& idx, bool& tie, int& resMaxDenom) {
    //max idx size: 4
    // given types & number of stamps, find best combination
    vector<int> v; //saves idx repeatedly, diff idx stands diff types
    if(mLeft <= 0) {
        return v; //for convenient return a useless vector
    }
    #ifdef DEBUG_DECOMPOSE_S1
        for(auto i:idx) {
            cout << i << " " ;
        }
        cout << endl;
    #endif
    Combination comb = Combination(idx.size() * sLeft, sLeft);
    for(int i = 0; i < idx.size(); i++) {
        for(int j = 0; j < sLeft; j++) {
            v.push_back(idx[i]);
        }
    }
    #ifdef DEBUG_DECOMPOSE_S1
        for(auto i:v) {
            cout << i << " " ;
        }
        cout << endl;
    #endif
    vector<int> idx4v; // save index of v
    for(int i = 1; i <= sLeft; i++) {
        idx4v.push_back(i);
    }
    #ifdef DEBUG_DECOMPOSE_S1
        for(auto i:idx4v) {
            cout << i << " " ;
        }
        cout << endl;
    #endif
    vector<int> res; res.clear();
    int globalMaxDenom = 0;
    tie = false;
    map<int, int> tieChecker;
    do{
        #ifdef DEBUG_DECOMPOSE_S2
            for(auto i:idx4v) {
                cout << i << " ";
            }
            cout << endl;
            // for(auto i:res) {
            //     cout << i << " ";
            // }
            // cout << endl;
        #endif
        int tempC = mLeft;
        int maxDenom = 0;
        for(auto i:idx4v) {
            tempC -= denom[v[i-1] - 1];
            maxDenom = max(denom[v[i-1] - 1], maxDenom);
        }
        
        if(tempC != 0) { // not enough
            continue;
        }else { //legal result, deal with denom
            if(globalMaxDenom <= maxDenom) {
                if(globalMaxDenom < maxDenom) { //new res better
                    tie = false; //reset tie
                    res.clear();
                    for(auto i:idx4v) { //update new res
                        res.push_back(v[i-1]); //saves type(idx+1 of denom)
                    }
                    globalMaxDenom = maxDenom;
                }else { //equals(may be the same)
                    #ifdef DEBUG_DECOMPOSE_S3
                        for(auto i:idx4v) {
                            cout << i << " ";
                        }
                        cout << endl;
                        for(auto i:res) {
                            cout << i << " ";
                        }
                        cout << endl;
                    #endif
                    tieChecker.clear();
                    tie = false; //assume that is a repeat
                    for(auto i:res) {
                        tieChecker[i]++;
                    }
                    for(auto j:idx4v) {
                        tieChecker[v[j-1]]--;
                        if(tieChecker[v[j-1]] < 0) { //is a tie
                            tie = true;
                            break;
                        }
                    }
                }
            }
        }

    }while(comb.getNext(idx4v));
    resMaxDenom = globalMaxDenom;
    return res;
}
void solve(int customer) {
    int totTypes = denom.size();
    vector<int> idx;
    bool hasRes = false;
    int stampTypes = 4;
    bool tie = false;
    vector<int> finalRes; finalRes.clear();
    while(stampTypes) { 
        //deal with max types, the earlier the result is got, the better the result is 
        if(stampTypes > totTypes) {
            stampTypes--;
            continue;
        }
        idx.clear();
        Combination comb = Combination(totTypes, stampTypes);
        for(int i = 1; i <= stampTypes; i++) {
            idx.push_back(i);
        }
        vector<int> midRes; midRes.clear();
        vector<int> innerRes; innerRes.clear();
        bool innerTie, midTie;
        midTie = false;
        int tempMaxDenom = 0;
        int midMaxDenom;
        do {
            midMaxDenom = 0;
            innerTie = false;
            int tempC = customer;
            for(auto i:idx) {
                tempC -= denom[i-1]; //i = index + 1
                midMaxDenom = max(denom[i-1], midMaxDenom);
            }
            if(tempC == 0) {
                hasRes = true;
            }
            int innerMaxDenom = 0;
            for(int i = 1; i <= 4-stampTypes; i++) { 
                // deal with min tot number, same types and same number of types
                // the earlier the result get, the better the result is
                // fix number of stamps
                innerRes.clear();
                innerRes = decompose(tempC, i, idx, innerTie, innerMaxDenom);
                if(innerTie == true || innerRes.size() > 0) { //tie or get result
                    hasRes = true; //has Result
                    break;
                }
            }
            #ifdef DEBUG_SOLVE_S1
                cout << "customer: " << customer << endl;
                cout << "tempC: " << tempC << endl;
                cout << "idx:  ";
                for(auto i:idx) {
                    cout << i << " ";
                }
                cout << endl << "innerRes:  ";
                for(auto i:innerRes) {
                    cout << i << " ";
                }
                cout << endl <<"midRes:  ";
                for(auto i:midRes) {
                    cout << i << " ";
                }
                cout << endl << "midTie:  ";
                cout << midTie;
                cout << endl << "innerTie:  ";
                cout << innerTie << endl;
                cout << "--------------------" << endl;
            #endif
            if(innerRes.size() > 0 || tempC == 0) { //has solution
                if(midRes.size() == 0) { // first solution
                    midRes = innerRes;
                    tempMaxDenom = max(midMaxDenom, innerMaxDenom);
                    midTie = innerTie;
                    for(auto i:idx) {
                        midRes.push_back(i);
                    }
                    continue;
                }
                //already has solution
                if(midRes.size() >= innerRes.size() + idx.size()) {
                    if(midRes.size() > innerRes.size() + idx.size()) { //new res has fewer stamps
                        midRes = innerRes;
                        tempMaxDenom = max(midMaxDenom, innerMaxDenom);
                        midTie = innerTie;
                        for(auto i:idx) {
                            midRes.push_back(i);
                        }
                    }else {//same number of stamps, compare max denomination
                        if(tempMaxDenom <= max(midMaxDenom, innerMaxDenom)) { //has larger denomination
                            if(tempMaxDenom < max(midMaxDenom, innerMaxDenom)) {//larger denom, better res

                                midRes = innerRes;
                                tempMaxDenom = max(midMaxDenom, innerMaxDenom);
                                midTie = innerTie;
                                for(auto i:idx) {
                                    midRes.push_back(i);
                                }
                            }else { //tie(has same number of types and same number of stamps, only need to compare denomination)
                                midTie = true;
                            }
                        }
                    }
                }
            }
            
            //fix types of stamps
            //same number of types but different types(cons 2)
            //the earlier the res get does NOT mean better res
        }while(comb.getNext(idx));
        if(midRes.size() > 0) {
            if(midTie) {//has a tie
                tie = true;
            }
            finalRes = midRes;
            break;
        }
        stampTypes--;
    }
    if(!hasRes) {
        printf("%d ---- none\n", customer);
        return;
    }
    if(tie) {
        printf("%d (%d): tie\n", customer, stampTypes);
        return;
    }
    //has optimal result
    printf("%d (%d): ", customer, stampTypes);
    sort(finalRes.begin(), finalRes.end());
    for(int i = 0; i < finalRes.size(); i++) {
        cout << denom[finalRes[i]-1] << ( i == finalRes.size()-1 ? "\n" : " ");
    }
    return;
}

/*
最多种类
最少总数
单值最高
tie

最多4种

不同种邮票最多25张
*/
