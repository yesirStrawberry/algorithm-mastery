## output

**main.c의 output**

```text
========================================
 테스트 1: 순방향 탐색 (bf_match)
 텍스트: abcdabcdebcd, 패턴: abcd
========================================
00 abcdabcdebcd
   +
   abcd 

00 abcdabcdebcd
    +
   abcd 

00 abcdabcdebcd
     +
   abcd 

00 abcdabcdebcd
      +
   abcd 

순방향 탐색 매칭 결과 인덱스: 0

========================================
 테스트 2: 역방향 탐색 (bf_matchr)
 텍스트: abcdabcdebcd, 패턴: abcd
========================================
08 abcdabcdebcd
              +
           abcd 

08 abcdabcdebcd
             +
           abcd 

08 abcdabcdebcd
            +
           abcd 

08 abcdabcdebcd
           |
           abcd 

07 abcdabcdebcd
             |
          abcd 

06 abcdabcdebcd
            |
         abcd 

05 abcdabcdebcd
           |
        abcd 

04 abcdabcdebcd
          +
       abcd 

04 abcdabcdebcd
         +
       abcd 

04 abcdabcdebcd
        +
       abcd 

04 abcdabcdebcd
       +
       abcd 

역방향 탐색 매칭 결과 인덱스: 4

========================================
 테스트 3: 예외 케이스 (존재하지 않는 패턴 탐색)
 텍스트: abcdabcdebcd, 패턴: efg
========================================
00 abcdabcdebcd
   |
   efg 

01 abcdabcdebcd
    |
    efg 

02 abcdabcdebcd
     |
     efg 

03 abcdabcdebcd
      |
      efg 

04 abcdabcdebcd
       |
       efg 

05 abcdabcdebcd
        |
        efg 

06 abcdabcdebcd
         |
         efg 

07 abcdabcdebcd
          |
          efg 

08 abcdabcdebcd
           +
           efg 

08 abcdabcdebcd
            |
           efg 

09 abcdabcdebcd
            |
            efg 

10 abcdabcdebcd
             |
             efg 

11 abcdabcdebcd
              |
              efg 

매칭 결과 인덱스 (기대값 -1): -1
```
