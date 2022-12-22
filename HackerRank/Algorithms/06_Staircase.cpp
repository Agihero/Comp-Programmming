#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    int spaces = n - 1;
    int hashes = 1;
    //goes down through the levels
    for (int i = 0; i < n; ++i) {
        //Prints the spaces at the beginning of each level
        for (int j = 0; j < spaces; ++j) {
            cout << " ";
        }
        
        //Prints the number of hashes in that level
        for (int j = 0; j < hashes; ++j) {
            cout << "#";
        }
        
        //End the level
        cout << endl;
        
        //Decrement the number of spaces for the next level and increase the hashes
        --spaces;
        ++hashes;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
