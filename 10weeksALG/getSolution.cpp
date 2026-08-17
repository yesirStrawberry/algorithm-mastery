#include <bits/stdc++.h>
using namespace std;

// solution.cpp에 있는 solve 함수 프로토타입 선언
void solve();

struct TestCase {
    string input;
    string expected_output;
};

// 개행 및 공백 정규화 함수
string normalize(const string& str) {
    stringstream ss(str);
    string token, result;
    while (ss >> token) {
        result += token + "\n";
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<TestCase> test_cases = {
        // {"입력1\n", "출력1\n"},
        // {"입력2\n", "출력2\n"}
    };

    int failed_count = 0;

    for (size_t i = 0; i < test_cases.size(); i++) {
        stringstream in_ss(test_cases[i].input);
        stringstream out_ss;

        streambuf* orig_cin = cin.rdbuf(in_ss.rdbuf());
        streambuf* orig_cout = cout.rdbuf(out_ss.rdbuf());

        solve();

        cin.rdbuf(orig_cin);
        cout.rdbuf(orig_cout);

        string actual = normalize(out_ss.str());
        string expected = normalize(test_cases[i].expected_output);

        if (actual != expected) {
            failed_count++;
            cout << "[TC " << i + 1 << " 실패]\n";
            cout << "<기대 출력>\n" << expected;
            cout << "<실제 출력>\n" << (actual.empty() ? "(출력 없음)\n" : actual);
            cout << "--------------------------------\n";
        }
    }

    if (failed_count == 0) {
        cout << "맞음" << '\n';
    } else {
        cout << "틀림 (총 " << test_cases.size() << "개 중 " << failed_count << "개 실패)" << '\n';
    }

    return 0;
}
