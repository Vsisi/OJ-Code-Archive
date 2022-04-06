#include<bits/stdc++.h>
using namespace std;
void initSet(set<string>& pokerCards) {
    pokerCards.insert("Joker");
    pokerCards.insert("joker");
    string color[] = {"Heart", "Spade", "Diamond", "Club"};
    string val[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Ace", "Jack", "Queen", "King"};
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            pokerCards.insert(color[i] + val[j]);
        }
    }
}
int main() {
    int n;
    cin >> n;
    string pokerCard;
    set<string> pokerCards;
    initSet(pokerCards);
    set<string> tmpCards;
    while(n--) {
        tmpCards = pokerCards;
        for(int i = 0; i < 53; i++) {
            cin >> pokerCard;
            tmpCards.erase(pokerCard);
        }
        cout << (*tmpCards.begin()) << endl;
    }
    return 0l;
}
