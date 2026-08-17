#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

extern int solve();

struct TestCase {
    std::string input;
    std::string expected_output;
};

// extern을 사용해 다른 파일에 원본 데이터가 정의되어 있음을 알립니다.
extern std::vector<TestCase> test_cases;

#endif // HEADER_H