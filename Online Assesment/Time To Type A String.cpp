#include <bits/stdc++.h>
using namespace std;

// Single Key Keyboard(LC Premium)

int singleRowKeyboard(string keyboard, string text) {
    int prev = 0;
    vector<int> pos(26, -1);
    for(int i = 0; i < 26; i++) {
        int idx = keyboard[i] - 'a';
        if(pos[idx] == -1) {
            pos[idx] = i;
        }
    }
    int totTime = 0;
    for(int i = 0; i < text.size(); i++) {
        int curr = pos[text[i] - 'a'];
        if(curr == -1)
            return -1;
        totTime += abs(prev - curr);
        prev = curr;
    }
    return totTime; 
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxy", t = "cba";
    cout << singleRowKeyboard(s, t) << endl;
	return 0;
}

