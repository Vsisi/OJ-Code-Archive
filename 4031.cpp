#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010 * 2;
int iniScore[MAXN];
int strength;
struct Player{
    Player(int id, int score, int strength):id(id), score(score), strength(strength) {}
    bool operator<(const Player& rhs) const {
        if(this->score != rhs.score) {
            return this->score > rhs.score;
        }
        return this->id < rhs.id;
    }
    int id;
    int score;
    int strength;
};
vector<Player> player;
int main() {
    int n, r, q;
    cin >> n >> r >> q;
    for(int i = 0; i < n*2; i++) {
        cin >> iniScore[i];
    }
    for(int i = 0; i < n*2; i++) {
        cin >> strength;
        player.push_back(Player(i+1, iniScore[i], strength));
    }
    sort(player.begin(), player.end());
    for(int cc = 0; cc < r; cc++) {
        for(int i = 0; i < 2 * n; i += 2) {
            if(player[i].strength > player[i+1].strength) {
                player[i].score++;
            }else {
                player[i+1].score++;
            }
        }
        sort(player.begin(), player.end());
    }
    cout << player[q-1].id;
    return 0;
}
