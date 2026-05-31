##output

**main.c 실행결과**

```text
########################################################################
#                KMP 알고리즘 시나리오 기반 정밀 테스트                #
########################################################################

========================================================================
[시나리오 1] 기본 패턴 탐색 및 조기 매칭 검증
- 텍스트 데이터: "ppapabab"
- 탐색용 패턴  : "abab"
========================================================================
00 ppapabab
   |
   abab 

01 ppapabab
    |
    abab 

02 ppapabab
     +
     abab 

02 ppapabab
      |
     abab 

03 ppapabab
      |
      abab 

04 ppapabab
       +
       abab 

04 ppapabab
        +
       abab 

04 ppapabab
         +
       abab 

04 ppapabab
          +
       abab 

------------------------------------------------------------------------
▶ [검색 성공] 패턴이 텍스트의 인덱스 [4]번 위치에서 일치되었습니다.
========================================================================


========================================================================
[시나리오 2] 수정된 'ABABCABAD' 패턴의 기득권 붕괴 및 후퇴(3번 분기) 검증
- 텍스트 데이터: "ABABCABAX"
- 탐색용 패턴  : "ABABCABAD"
========================================================================
00 ABABCABAX
   +
   ABABCABAD 

00 ABABCABAX
    +
   ABABCABAD 

00 ABABCABAX
     +
   ABABCABAD 

00 ABABCABAX
      +
   ABABCABAD 

00 ABABCABAX
       +
   ABABCABAD 

00 ABABCABAX
        +
   ABABCABAD 

00 ABABCABAX
         +
   ABABCABAD 

00 ABABCABAX
          +
   ABABCABAD 

00 ABABCABAX
           |
   ABABCABAD 

05 ABABCABAX
           |
        ABABCABAD 

07 ABABCABAX
           |
          ABABCABAD 

08 ABABCABAX
           |
           ABABCABAD 

------------------------------------------------------------------------
◼ [검색 실패] 본문 내에 일치하는 패턴이 존재하지 않습니다. (반환값: -1)
========================================================================


========================================================================
[시나리오 3] 중첩 접두사 구조를 가진 텍스트 내 매칭 성공 검증
- 텍스트 데이터: "ABABCABABCABABA"
- 탐색용 패턴  : "ABABCABAD"
========================================================================
00 ABABCABABCABABA
   +
   ABABCABAD 

00 ABABCABABCABABA
    +
   ABABCABAD 

00 ABABCABABCABABA
     +
   ABABCABAD 

00 ABABCABABCABABA
      +
   ABABCABAD 

00 ABABCABABCABABA
       +
   ABABCABAD 

00 ABABCABABCABABA
        +
   ABABCABAD 

00 ABABCABABCABABA
         +
   ABABCABAD 

00 ABABCABABCABABA
          +
   ABABCABAD 

00 ABABCABABCABABA
           |
   ABABCABAD 

05 ABABCABABCABABA
           +
        ABABCABAD 

05 ABABCABABCABABA
            +
        ABABCABAD 

05 ABABCABABCABABA
             +
        ABABCABAD 

05 ABABCABABCABABA
              +
        ABABCABAD 

05 ABABCABABCABABA
               +
        ABABCABAD 

05 ABABCABABCABABA
                |
        ABABCABAD 

10 ABABCABABCABABA
                +
             ABABCABAD 

10 ABABCABABCABABA
                 |
             ABABCABAD 

12 ABABCABABCABABA
                 +
               ABABCABAD 

------------------------------------------------------------------------
◼ [검색 실패] 본문 내에 일치하는 패턴이 존재하지 않습니다. (반환값: -1)
========================================================================


========================================================================
[시나리오 4] 완전 불일치 상태에서의 포인터 전진 스펙 검증
- 텍스트 데이터: "XYZXYZXYZ"
- 탐색용 패턴  : "abab"
========================================================================
00 XYZXYZXYZ
   |
   abab 

01 XYZXYZXYZ
    |
    abab 

02 XYZXYZXYZ
     |
     abab 

03 XYZXYZXYZ
      |
      abab 

04 XYZXYZXYZ
       |
       abab 

05 XYZXYZXYZ
        |
        abab 

06 XYZXYZXYZ
         |
         abab 

07 XYZXYZXYZ
          |
          abab 

08 XYZXYZXYZ
           |
           abab 

------------------------------------------------------------------------
◼ [검색 실패] 본문 내에 일치하는 패턴이 존재하지 않습니다. (반환값: -1)
========================================================================
```
