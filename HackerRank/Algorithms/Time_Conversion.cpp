#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *  
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    //Get the hour of the time and convert it to an int
    string hourStr = "";
    hourStr += s[0];
    hourStr += s[1];
    int hour = stoi(hourStr);
    
    //Time output string (without the 'AM'/'PM')
    string output = "";
    for (int i = 0; i < 8; ++i) {
        output += s[i];
    }
    
    //If the hour is 12 and it is 'AM' then, make it hour 0
    if (hour == 12 && s[8] == 'A') {
        for (int i = 0; i < 2; ++i) {
            output[i] = '0';
        }
    }
    
    //If the hour is in between 1 'PM' and 11 'PM' add twelve to it
    if ((hour >= 1 && hour <= 11) && s[8] == 'P') {
       hour += 12;
       string afternoon = to_string(hour);
       
       for (int i = 0; i < 2; ++i) {
           output[i] = afternoon[i];
       } 
    }
    
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
