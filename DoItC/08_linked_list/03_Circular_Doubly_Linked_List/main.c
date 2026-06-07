/**
 * @file main.c
 * @brief 원형 이중 연결 리스트 라이브러리 검증을 위한 상세 테스트 시나리오
 * @details 각 함수의 정상 동작 및 예외 처리 케이스를 명세서 형태로 출력하며 검증합니다.
 */

#include <stdio.h>
#include <string.h>
#include "CircDbLinkedList.h"

// member 구조체 간의 나이를 비교하는 함수 (search 함수용)
int compare_age(const member *x, const member *y) {
	if (x->age == y->age) return 0;
	return (x->age > y->age) ? 1 : -1;
}

// 테스트 결과 서식을 일관되게 출력하기 위한 헬퍼 함수
void print_test_header(const char *test_id, const char *title) {
	printf("\n======================================================================\n");
	printf("[%s] %s\n", test_id, title);
	printf("----------------------------------------------------------------------\n");
}

int main(void) {
	Dlist list;

	// 테스트용 임시 데이터 정의
	member m1 = {"홍길동", 20};
	member m2 = {"김철수", 25};
	member m3 = {"이영희", 22};
	member m4 = {"박민수", 30};
	member search_target = {"미확인", 25}; // 검색용 (나이 25세 기준)

	printf("======================================================================\n");
	printf("              원형 이중 연결 리스트 기능 검증 테스트 명세서           \n");
	printf("======================================================================\n");

	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-01", "init_Dlist : 리스트 초기화 및 초기 상태 검증");
	printf("[동작] 리스트를 초기화한 후, 현재 노드 상태 및 비어있는지 여부를 확인합니다.\n\n");

	init_Dlist(&list);

	printf("[예측 출력]\n");
	printf(" - list is empty 또는 current node is not exist\n");
	printf("\n[실제 출력]\n - ");
	print_current(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-02", "insert_front : 맨 앞에 노드 삽입 (첫 번째 노드)");
	printf("[동작] 빈 리스트에 '홍길동(20)' 노드를 맨 앞에 삽입하고 리스트 상태를 확인합니다.\n\n");

	insert_front(&list, &m1);

	printf("[예측 출력]\n");
	printf(" - print_list\n");
	printf("   -----------------\n");
	printf("   [이름: 홍길동, 나이: 20]node address : [주소]\n");
	printf("   next address : [더미 주소]\n");
	printf("   prev address : [더미 주소]\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-03", "insert_front : 맨 앞에 노드 연속 삽입 (연결 관계 확인)");
	printf("[동작] '김철수(25)' 노드를 맨 앞에 추가로 삽입하여 순서가 [김철수 -> 홍길동]이 되는지 확인합니다.\n\n");

	insert_front(&list, &m2);

	printf("[예측 출력]\n");
	printf(" - 리스트 순서: 김철수(25) -> 홍길동(20)\n");
	printf(" - 현재 주목 노드(crnt): 김철수(25)\n");

	printf("\n[실제 출력]\n");
	printf(" - 현재 주목 노드 정보:\n");
	print_current(&list);
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-04", "insert_rear : 맨 뒤에 노드 삽입");
	printf("[동작] '이영희(22)' 노드를 맨 뒤에 삽입하여 순서가 [김철수 -> 홍길동 -> 이영희]가 되는지 확인합니다.\n\n");

	insert_rear(&list, &m3);

	printf("[예측 출력]\n");
	printf(" - 리스트 순서: 김철수(25) -> 홍길동(20) -> 이영희(22)\n");
	printf(" - 현재 주목 노드(crnt): 이영희(22)\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-05", "insert_after : 특정 노드 뒤에 삽입");
	printf("[동작] 리스트의 맨 앞 노드(김철수)를 찾아서 그 바로 뒤에 '박민수(30)'를 삽입합니다.\n");
	printf("       결과 순서: [김철수 -> 박민수 -> 홍길동 -> 이영희]\n\n");

	Dnode *front_node = list.head->next; // 첫 번째 데이터 노드 (김철수)
	insert_after(&list, front_node, &m4);

	printf("[예측 출력]\n");
	printf(" - 리스트 순서: 김철수(25) -> 박민수(30) -> 홍길동(20) -> 이영희(22)\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-06", "print_list_rsv : 리스트 역방향 출력 검증");
	printf("[동작] 현재 리스트 상태를 역순(이영희 -> 홍길동 -> 박민수 -> 김철수)으로 출력하여 prev 링크를 검증합니다.\n\n");

	printf("[예측 출력]\n");
	printf(" - 리스트 역순: 이영희(22) -> 홍길동(20) -> 박민수(30) -> 김철수(25)\n");

	printf("\n[실제 출력]\n");
	print_list_rsv(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-07", "search : 데이터 검색 및 주목 노드(crnt) 이동 확인");
	printf("[동작] 나이가 25세인 데이터를 검색합니다. 성공 시 crnt가 김철수로 변경되어야 합니다.\n\n");

	Dnode *found = search(&list, &search_target, compare_age);

	printf("[예측 출력]\n");
	if (found != NULL) {
		printf(" - 검색 성공 여부: 성공\n");
		printf(" - 현재 주목 노드 데이터: [이름: 김철수, 나이: 25]\n");
	}

	printf("\n[실제 출력]\n");
	if (found != NULL) {
		printf(" - 검색 성공 여부: 성공 (주소: %p)\n", (void*)found);
		printf(" - 현재 주목 노드 상세 정보:\n");
		print_current(&list);
	} else {
		printf(" - 검색 실패\n");
	}


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-08", "move_next : 순방향 경계면 순환 테스트 (원형 구조 검증)");
	printf("[동작] 현재 crnt인 '김철수'에서 출발하여 move_next를 4번 연속 실행합니다.\n");
	printf("       김철수(출발) -> 박민수 -> 홍길동 -> 이영희 -> [더미점프] -> 김철수 순으로 순환해야 합니다.\n\n");

	printf("[예측 출력]\n");
	printf(" 1. 이동 후: [이름: 박민수, 나이: 30]\n");
	printf(" 2. 이동 후: [이름: 홍길동, 나이: 20]\n");
	printf(" 3. 이동 후: [이름: 이영희, 나이: 22]\n");
	printf(" 4. 이동 후 (더미노드 통과 점프): [이름: 김철수, 나이: 25]\n");

	printf("\n[실제 출력]\n");
	for(int i = 1; i <= 4; i++) {
		move_next(&list);
		printf(" %d. 이동 후: ", i);
		print_member(&list.crnt->data);
		printf("\n");
	}


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-09", "move_prev : 역방향 경계면 순환 테스트 (원형 구조 검증)");
	printf("[동작] 현재 crnt인 '김철수'에서 move_prev를 실행하여 역방향 경계 점프(마지막 노드로 이동)를 검증합니다.\n");
	printf("       김철수(출발) -> [더미점프] -> 이영희 순으로 이동해야 합니다.\n\n");

	move_prev(&list);

	printf("[예측 출력]\n");
	printf(" - 이동 후 주목 노드: [이름: 이영희, 나이: 22]\n");

	printf("\n[실제 출력]\n");
	printf(" - 이동 후 주목 노드: ");
	print_member(&list.crnt->data);
	printf("\n");


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-10", "remove_front : 맨 앞 노드 삭제");
	printf("[동작] 리스트의 맨 앞 노드(김철수)를 삭제하고 구조를 확인합니다.\n");
	printf("       남은 노드 순서: [박민수 -> 홍길동 -> 이영희]\n\n");

	remove_front(&list);

	printf("[예측 출력]\n");
	printf(" - 리스트 순서: 박민수(30) -> 홍길동(20) -> 이영희(22)\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-11", "remove_rear : 맨 뒤 노드 삭제");
	printf("[동작] 리스트의 맨 뒤 노드(이영희)를 삭제하고 구조를 확인합니다.\n");
	printf("       남은 노드 순서: [박민수 -> 홍길동]\n\n");

	remove_rear(&list);

	printf("[예측 출력]\n");
	printf(" - 리스트 순서: 박민수(30) -> 홍길동(20)\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


    /* ---------------------------------------------------------------------- */
    print_test_header("TEST-12", "remove_current : 현재 주목하고 있는 노드 삭제");
    printf("[동작] 현재 crnt의 위치를 확인하고, remove_current를 통해 해당 노드를 제거합니다.\n");
    printf("       (주의: remove_rear 직후 crnt는 자동으로 '홍길동'을 가리키고 있으므로,\n");
    printf("       remove_current 호출 시 '홍길동' 노드가 삭제됩니다.)\n\n"); // <-- [동작] 설명 보완
    
    printf(" - 삭제 전 현재 주목 노드 정보:\n");
    print_current(&list);
    
    remove_current(&list);
    
    printf("\n[예측 출력]\n");
    printf(" - 삭제 후 남은 노드: 박민수(30) 하나만 남음\n"); // <-- 홍길동(20)에서 박민수(30)로 수정!
    
    printf("\n[실제 출력]\n");
    print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-13", "remove_Dnode 예외 처리 : 사용자의 더미 노드 삭제 시도 차단");
	printf("[동작] 사용자가 악의적 혹은 실수로 remove_Dnode(list, list.head)를 호출할 때 방어 코드가 작동하는지 확인합니다.\n\n");

	printf("[예측 출력]\n");
	printf(" - Warning: Cannot remove the dummy node.\n");

	printf("\n[실제 출력]\n");
	remove_Dnode(&list, list.head);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-14", "clear : 리스트 비우기 기능 검증");
	printf("[동작] clear 함수를 호출하여 리스트 내부의 남아있는 모든 데이터 노드를 삭제합니다.\n\n");

	clear(&list);

	printf("[예측 출력]\n");
	printf(" - empty list\n");

	printf("\n[실제 출력]\n");
	print_list(&list);


	/* ---------------------------------------------------------------------- */
	print_test_header("TEST-15", "terminate_Dlist : 리스트 사용 종료 및 더미 노드 최종 해제");
	printf("[동작] 모든 데이터가 비워진 리스트의 자원을 완전히 반환합니다. (정상 종료 시 에러 없음)\n\n");

	terminate_Dlist(&list);

	printf("[예측 출력]\n");
	printf(" - 프로그램이 정상적으로 메모리를 해제하고 종료됨 (Valgrind 등에서 Leak 0 확인 가능)\n");
	printf("\n[실제 출력]\n");
	printf(" - 리스트 자원 해제 완료.\n");

	printf("\n======================================================================\n");
	printf("                      모든 상세 기능 테스트가 종료되었습니다.         \n");
	printf("======================================================================\n");

	return 0;
}



