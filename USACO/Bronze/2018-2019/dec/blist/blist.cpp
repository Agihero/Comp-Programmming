#include <bits/stdc++.h>
using namespace std;

int main() {
    //IO ("blist.in" & "blist.out")
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    
    //array for each of the input cows' details (j = 0 is start time, j = 1 is end time, j = 2 is the amount to milk)
    int n; fin >> n;
    int details[n][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            fin >> details[i][j];
        }
    }

    //number of free buckets and used buckets
    int free = 0;
    int use = 0;

    for (int i = 0; i < 100; ++i) {
        //Checks if a cow starts at this particular index of the milking simulation
        for (int j = 0; j < n; ++j) {
            if (details[j][0] == i) {
                //If a cow is starting, then check the amount of avaliable buckets. If enough aren't avaliable add more to make em avaible.
                if (free < details[j][2]) {
                    use += free;
                    use += details[j][2] - free;
                    free = 0;
                    break;
                } else {
                    use += free;
                    free = 0;
                    break;
                }
            }
        }
        //Checks if a cow ends at this particular index of the milking simulation and frees all the buckets currently in use.
        for (int j = 0; j < n; ++j) {
            if (details[j][1] == i) {
                use -= details[j][2];
                free += details[j][2];
                break;
            }
        }
    }
    
    //Output answer
    cout << free + use << endl;
    
    return 0;
}
