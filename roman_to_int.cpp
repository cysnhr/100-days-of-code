#include <iostream>
#include <string>
using namespace std;


int main() {
    string s = "D"; // MCMXCIV
    int len = s.length();
    int rom[len];
    int sum = 0;

    // turn string into integer array
    for (int i = 0; i < len; i++) {
    if (s[i] == 'I') {
        rom[i] = 1;
    }
    else if (s[i] == 'V') {
        rom[i] = 5;
    }
    else if (s[i] == 'X') {
            rom[i] = 10;
        }
    else if (s[i] == 'L') {
            rom[i] = 50;
        }
    else if (s[i] == 'C') {
            rom[i] = 100;
        }
    else if (s[i] == 'D') {
            rom[i] = 500;
        }
    else if (s[i] == 'M') {
            rom[i] = 1000;
        }
    // cout << rom[i]; checked and is correct
    }

    // for things with only one element
    if (len == 1) {
        sum += rom[0];
    }
    
    // process sum
    for (int i = 0; i < len - 1; i++) {
        cout << i + 1 << " try:" << endl;
        cout << "rom[i] " << rom[i];
        cout << " rom[i+1] " << rom[i+1] << endl;

        // last element checks
        if (i == len - 2) {
            if (rom[i] < rom[i+1]) {
                sum -= rom[i]; 
                sum += rom[i + 1];
            }
            else {
                sum += (rom[i] + rom[i + 1]);
            }
        }
        else {
            // normal checks
            if (rom[i] < rom[i + 1]) {
                sum -= rom[i];
                //sum += rom[++i]; // prevents messy last element problems
            }
            else {
                sum += rom[i];
            }
        }


        cout << "sum " << sum << endl;
    }

    cout << "final answer " << sum << endl;
}

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

for every character up until second to last
    // for last element
    if i is second to last and this < next
        subtract this
        add next
    else
        add this
        add next
    if this < after
        subtract this
    else
        add this

*/
