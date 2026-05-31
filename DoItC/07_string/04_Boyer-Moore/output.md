## output

**main.c실행결과**

```text

==================================================
  SECTION: Boyer-Moore 알고리즘 (bm_match 인덱스 기반) 테스트
==================================================
00 VISION WITHOUT ACTION IS A DAYDREAM.
        +
   ACTION 

00 VISION WITHOUT ACTION IS A DAYDREAM.
       +
   ACTION 

00 VISION WITHOUT ACTION IS A DAYDREAM.
      +
   ACTION 

00 VISION WITHOUT ACTION IS A DAYDREAM.
     |
   ACTION 

03 VISION WITHOUT ACTION IS A DAYDREAM.
           |
      ACTION 

05 VISION WITHOUT ACTION IS A DAYDREAM.
             |
        ACTION 

11 VISION WITHOUT ACTION IS A DAYDREAM.
                   |
              ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                       +
                  ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                      +
                  ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                     +
                  ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                    +
                  ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                   +
                  ACTION 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                  +
                  ACTION 

[SUCCESS CASE] 패턴 "ACTION" 탐색 결과
-> 매칭 성공! 시작 인덱스: 15 (본문 일치 확인: ACTION IS A DAYDREAM.)

00 VISION WITHOUT ACTION IS A DAYDREAM.
         |
   REALITY 

07 VISION WITHOUT ACTION IS A DAYDREAM.
                |
          REALITY 

08 VISION WITHOUT ACTION IS A DAYDREAM.
                 |
           REALITY 

15 VISION WITHOUT ACTION IS A DAYDREAM.
                        |
                  REALITY 

22 VISION WITHOUT ACTION IS A DAYDREAM.
                               |
                         REALITY 

26 VISION WITHOUT ACTION IS A DAYDREAM.
                                   |
                             REALITY 

[FAILURE CASE] 패턴 "REALITY" 탐색 결과
-> 매칭 실패 확인 (예상대로 -1이 올바르게 반환되었습니다.)

00 VISION WITHOUT ACTION IS A DAYDREAM.
           |
   DAYDREAM. 

09 VISION WITHOUT ACTION IS A DAYDREAM.
                    |
            DAYDREAM. 

18 VISION WITHOUT ACTION IS A DAYDREAM.
                             |
                     DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                      +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                     +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                    +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                   +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                  +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                 +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                                +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                               +
                              DAYDREAM. 

27 VISION WITHOUT ACTION IS A DAYDREAM.
                              +
                              DAYDREAM. 

[EDGE CASE] 후미 패턴 "DAYDREAM." 탐색 결과
-> 매칭 성공! 시작 인덱스: 27


==================================================
  SECTION: Boyer-Moore 기반 맞춤형 str_str (포인터 반환 기반) 테스트
==================================================
[SUCCESS CASE] str_str("ACTION") 탐색 결과
-> 반환된 포인터 주소: 0x7fffadb7800f
-> 포인터 역참조 출력(역산 검증): ACTION IS A DAYDREAM.
-> 본문 시작점과의 오프셋 주소차(인덱스 변환): 15

[FAILURE CASE] str_str("REALITY") 탐색 결과
-> 매칭 실패 확인: NULL 포인터가 정확히 반환되었습니다.

[CRITICAL EDGE CASE] 빈 문자열 패턴 str_str("") 탐색 결과
-> 본문(text)의 원본 시작 주소 : 0x7fffadb78000
-> str_str이 반환한 포인터 주소: (nil)
-> 오류: 표준 규격을 만족하지 못했습니다.


==================================================
  SECTION: 전체 테스트 프로세스 종료
==================================================
```
