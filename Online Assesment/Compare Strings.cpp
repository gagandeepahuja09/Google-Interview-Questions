// https://leetcode.com/discuss/interview-question/352458/

#include<bits/stdc++.h>
using namespace std;

int countMin(string s) {
    char mn = 'z'; 
    int cnt = 0;
    for(char c : s) {
        if(c < mn) {
            mn = c;
            cnt = 1;
        }
        else if(c == mn) {
            cnt++;
        }
    }
    return cnt;
}

vector<int> f(string a, string b) {
    vector<int> freq;
    string s;
    for(int i = 0; i <= a.size(); i++) {
        if(i == a.size() || a[i] == ' ') {
            int cnt = countMin(s);
            freq.push_back(cnt);
            s = "";
        }
        else {
            s += a[i];
        }
    }
    sort(freq.begin(), freq.end());
    vector<int> ret;
    for(int i = 0; i <= b.size(); i++) {
        if(i == b.size() || b[i] == ' ') {
            int cnt = countMin(s);
            int ans = lower_bound(freq.begin(), freq.end(), cnt) - freq.begin();
            cout << ans << endl;
            ret.push_back(ans);
            s = "";
        }
        else {
            s += b[i];
        }
    }
    return ret;
}

int main() {
    string a = "abcd aabc bd";
    string b = "aaa aa";
    f(a, b);
	return 0;
}

