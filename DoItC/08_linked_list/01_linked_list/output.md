## output

### 주요 테스트 항목

* **빈 리스트 초기화 검증 (`init_list`)**
  * 리스트 생성 직후 `head`와 `crnt`(주목 포인터)가 정상적으로 `NULL`로 세팅되는지 확인합니다.


* **빈 리스트에서의 예외 처리(Guard Clause) 검증**
  * 데이터가 없는 상태에서 `remove_front`, `remove_reer`, `remove_current` 호출 시 프로그램이 터지지 않고 안전하게 false(`FAILED`)를 반환하는지 체크합니다.


* **리스트 머리(Front) 삽입 연산 검증 (`insert_front`)**
  * 새로운 노드를 맨 앞에 추가했을 때 $O(1)$ 속도로 연결 관계가 갱신되고, `head`와 `crnt`가 새 노드를 올바르게 가리키는지 확인합니다.


* **리스트 꼬리(Reer) 삽입 연산 검증 (`insert_reer`)**
  * 리스트의 끝까지 탐색($O(N)$)하여 새 노드를 안전하게 연결하고, `crnt` 포인터가 새로 추가된 tail 노드로 이동하는지 검증합니다.


* **조건 검색 및 주목 포인터 이동 검증 (`search`)**
  * 콜백 함수(`compare_member_age`)를 통해 특정 조건의 데이터를 정확히 찾아내는지 확인하고, 검색 성공 시 `crnt`가 해당 노드로 갱신되는지 체크합니다.


* **주목 노드 삭제 연산 검증 (`remove_current`)**
  * 리스트 중간에 위치한 `crnt` 노드(예: Bob)를 지웠을 때, 이전 노드와 다음 노드가 끊어짐 없이 연결되고 `crnt`가 이전 노드로 안전하게 후퇴하는지 검증합니다.


* **단일 노드 상황에서의 예외 위임 검증 (Edge Case)**
  * 노드가 딱 하나만 남았을 때 `remove_reer`를 호출하면, 내부적으로 `remove_front`로직으로 안전하게 위임되어 에러 없이 삭제되는지 확인합니다.


* **전체 삭제 및 메모리 해제 검증 (`clear`)**
  * 리스트 내 모든 노드를 순회하며 할당된 메모리를 완전히 해제하고, `head`와 `crnt`를 다시 `NULL`로 초기화하여 댕글링 포인터를 차단하는지 확인합니다.


* **주목 노드 및 전체 리스트 출력 기능 검증 (`print_node`, `print_list`)**
  * 현재 선택된 노드의 데이터와 다음 노드의 주소값, 그리고 리스트 전체 요소들이 visual하게 정상 출력되는지 디버깅 뷰를 확인합니다.


* **리스트 종료 및 자원 정리 검증 (`terminate_list`)**
  * 프로그램 종료 전 내부적으로 `clear`를 호출하여 동적 할당된 메모리 누수(Memory Leak) 없이 `CLEAN`한 상태로 안전하게 종료되는지 최종 검증합니다.



## main.c의 실행결과

```text
========================================
[TEST] Initial Empty List State
----------------------------------------
Current List Elements:
empty list
----------------------------------------
Current Selected Node (crnt):
list->crnt : NULL
========================================
[Guard Check] Remove from empty list (front): FAILED (Expected)
[Guard Check] Remove from empty list (reer): FAILED (Expected)
[Guard Check] Remove current from empty list: FAILED (Expected)

[Insert] Inserting 'Alice(20)' at front...

========================================
[TEST] After insert_front (1 Element)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Alice
age  : 20
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Alice
age  : 20
next : 0
========================================

[Insert] Inserting 'Bob(22)' at front...

========================================
[TEST] After insert_front (2 Elements)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Bob
age  : 22
next : 2741032504116440
--------------
name : Alice
age  : 20
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Bob
age  : 22
next : 2741032504116440
========================================

[Insert] Inserting 'Charlie(25)' at reer...

========================================
[TEST] After insert_reer (3 Elements)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Bob
age  : 22
next : 2741032504116440
--------------
name : Alice
age  : 20
next : 2741032504116600
--------------
name : Charlie
age  : 25
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Charlie
age  : 25
next : 0
========================================

[Search] Searching for member with age 22...
Result: Found node address [0x5e10d5109d50] -> Name: Bob, Age: 22

========================================
[TEST] After Search (crnt should point to Bob)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Bob
age  : 22
next : 2741032504116440
--------------
name : Alice
age  : 20
next : 2741032504116600
--------------
name : Charlie
age  : 25
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Bob
age  : 22
next : 2741032504116440
========================================

[Delete] Removing current node (Bob)...
Result: Current node removed successfully.

========================================
[TEST] After remove_current (Bob should be gone, crnt updated to Alice)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Alice
age  : 20
next : 2741032504116600
--------------
name : Charlie
age  : 25
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Alice
age  : 20
next : 2741032504116600
========================================

[Delete] Removing reer node (Charlie)...

========================================
[TEST] After remove_reer (Only Alice should remain)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Alice
age  : 20
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : Alice
age  : 20
next : 0
========================================

[Insert] Inserting 'David(30)' at reer...

========================================
[TEST] Preparation for clear (Alice -> David)
----------------------------------------
Current List Elements:
--------------
print_list
--------------
name : Alice
age  : 20
next : 2741032504116660
--------------
name : David
age  : 30
next : 0
----------------------------------------
Current Selected Node (crnt):
--------------
print_node
--------------
name : David
age  : 30
next : 0
========================================

[Memory] Clearing all nodes to prevent memory leaks...

========================================
[TEST] After clear (List must be empty, head/crnt must be NULL)
----------------------------------------
Current List Elements:
empty list
----------------------------------------
Current Selected Node (crnt):
list->crnt : NULL
========================================

[Termination] List terminated safely. Dynamic memory leak status: CLEAN
```
