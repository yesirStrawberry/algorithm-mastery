#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 7, a[9];
bool endFlag = false;

void submit(vector<int> idx) {
    int res = 0;
    for (int i : idx) {
        res += a[i];
    }

    if (res == 100) {
        for (int i : idx) {
            cout << a[i] << '\n';
        }
        endFlag = true;
    }
}

void combi(vector<int> b, int start) {
    if (endFlag) return;

    if (b.size() == k) {
        submit(b);
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi(b, i);
        b.pop_back();
    }
    return;
}

void solve() {
    endFlag = false;
    memset(a, 0, sizeof(a));

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a + 9);

    vector<int> b;
    combi(b, -1);
}
