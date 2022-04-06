#include<bits/stdc++.h>
using namespace std;
class Rat{
public:
    Rat(int weight, string color):weight(weight), color(color) {
    }
    bool operator<(const Rat& rhs) const {
        return this->weight < rhs.weight;
    }
    string getColor() const {
        return color;
    }
private:
    int weight;
    string color;
};
int main() {
    int n;
    int w;
    string c;
    cin >> n;
    vector<Rat> rats;
    for(int i = 0; i < n; i++) {
        cin >> w >> c;
        rats.push_back(Rat(w, c));
    }
    sort(rats.begin(), rats.end());
    for(auto rat:rats) {
        cout << rat.getColor() << endl;
    }
    return 0;
}
