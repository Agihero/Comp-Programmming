#include <bits/stdc++.h>
using namespace std;

int main() {
    //Input
    string a = "";
    string garbage = "";
    for (int i = 0; i < 3; ++i) {
        cin >> garbage;
        a += garbage;
    }
    string g = "";
    for (int i = 0; i < 3; ++i) {
        cin >> garbage;
        g += garbage;
    }

    //two maps for guess and answer
    map<char, int> mapA;
    map<char, int> mapG;

    //Searches for number of greens and populates maps with incorrect guesses and yellows
    int greens = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == g[i]) {
            ++greens;
        } else {
            ++mapA[a[i]];
            ++mapG[g[i]];
        }
    }

    //Output green
    cout << greens << endl;

    //Searches for Yellows
    int yellows = 0;
    for (auto const& [key, val] : mapA) {
        if (mapG[key] > 0) {
            yellows += min(val, mapG[key]);
        }
    }

    //output yellow
    cout << yellows << endl;
    return 0;
}
/*
All code by August!
*/
