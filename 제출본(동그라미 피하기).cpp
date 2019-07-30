#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>





#define map_x 30//가로
#define map_y 22//세로
#define STAR map_x-1//별 최대갯수
#define left 75//왼쪽
#define right 77//오른쪽
#define dead 0
#define clear 1
#define score cnt_star * ((stage + 1) * 10)

typedef struct xy {

	int x;

	int y;

};

struct xy star[STAR];
struct xy cr;


int max_star = 0; // 떨어져야 하는 하트의 수

int cnt_star = 0; // 떨어진 하트의 수

int speed = 0; // 게임 속도

int stage = 0; // 스테이지

// 게임이 끝났을 경우
void endgame(int); 
 // 기본 맵의 테두리 출력
void field();
// 게임을 초기화한다
void game(); 
// 게임을 시작한다
void startgame(); 
// 화면에 하트을 뿌려준다
void printstar(); 
// 별과 캐릭터 충돌 체크
void checkhit();


// 입력받은 좌표로 이동해주는 함수
void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//깜박임을 없애는 함수
void zjtj() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible 멤버 변경
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 변경값 적용
}


// 기본 맵의 테두리 출력
void field() {
	int i, j;
	// 미리 선언한 맵의 가로 크기만큼 반복
	for (i = 0; i <= map_y; i++) {
		// 맨 처음 행과 가장 마지막 행 일때 수행
		if (i == 0 || i == map_y) {
			for (j = 0; j <= map_x; j++){
				gotoxy(j*2, i);
				
				printf("□");
				
			}
		}
		else// 나머지 열 일때 수행
		{
			gotoxy(0, i);
			
			printf("□");

			gotoxy(map_x*2 , i);
			
			printf("□");

		}
	}
	
}

// 게임이 끝났을 경우
void endgame(int f) {
	if (f==dead) {
		getch(); system("cls");
		gotoxy(map_x / 2, map_y / 2);
		printf("동그라미에 맞아 게임이 끝났습니다.\n");
		gotoxy(map_x / 2, map_y / 2 + 1);
		printf("LAST SCORE = %d\n", cnt_star*((stage + 1) * 10));
		getch(); exit(1);
	}
	else if(f==clear){
		getch(); getch();
		system("cls");
		gotoxy(map_x / 2+10, map_y / 2);
		
		printf("STAGE CLEAR\n"); 
		gotoxy(map_x / 2+10, map_y / 2 + 1);
		
		printf("NEXT STAGE \n"); 
		
		getch(); getch(); system("cls");

		field();

		stage++;

		game();
		max_star += stage * 30;
		speed -= stage * 10;
	}
}


// 게임을 초기화한다
void game() {
	 int cnt = 0;

	 max_star = 50; // 떨어져야 하는 하트의 수

	 cnt_star = 0; // 떨어진 하트의 수

	speed = 100; // 게임 속도

	// 하트 위치 초기화
	for (cnt = 0; cnt < STAR; cnt++)

	{

		star[cnt].x = cnt + 1;

		star[cnt].y = rand() % 50;

		star[cnt].x *= 2;

		star[cnt].y *= -1;

	}
	
	cr.x = 30; cr.y = 21;
	gotoxy(cr.x, cr.y);
	printf("★");

	gotoxy(0, map_y + 1);
	printf("STAGE = %d\n", stage + 1);
	
	printf("SCORE = %d\n", score);
	
}
// 화면에 별을 뿌려준다
// 별 x, y좌표를 배열에 담아서 반복문 돌리면서 다 gotoxy로 옮겨줌
//printstar함수 한번실행하면 다 한칸씩 내려감
//클리어 하거나 죽을때까지 printstar를 startgame 함수에서 무한반복
void printstar() {
	
	int cnt = 0; int r;
	for (cnt = 0; cnt < STAR; cnt++) {
		//땅에 떨어질경우
		if (star[cnt].y == map_y - 1) {
			gotoxy(star[cnt].x, star[cnt].y);
			printf("  ");
			cnt_star++;
			gotoxy(0, map_y + 1);
			printf("STAGE = %d\n", stage + 1);
			
			printf("SCORE = %d\n", score);
			
			if (max_star == cnt_star) {
				gotoxy(map_x-20, map_y+1);
				
				printf("♡동그라미를 다 피하셨습니다. 아무키나 눌러주세요♡");
				endgame(clear);
				return;
			}
			else if (max_star > cnt_star) {
				star[cnt].y = rand() % 50;
				star[cnt].y *= -1;
			}
			continue;
		}
		do {
			star[cnt].y = star[cnt].y + 1;
		} while (star[cnt].y > 21);//밑으로 한칸씩 내린다

		if (star[cnt].y > 1) {
			gotoxy(star[cnt].x, star[cnt].y - 1);
			printf("  ");
			gotoxy(star[cnt].x, star[cnt].y);
			printf("●"); 
		}
		
	}
	
}

// 별과 캐릭터 충돌 체크
void checkhit() {
	int cnt = 0;
	for (cnt = 0; cnt < STAR; cnt++) {
		if (star[cnt].x == cr.x) {
			if (star[cnt].y == cr.y) {
				gotoxy(map_x-13, map_y + 1);
				
				printf("[충돌하였습니다. 아무키나 누르세요.]");
				endgame(dead);
			}
		}
	}
}

void startgame() {
	char in = '\0';
	
	while (1) {
		if (kbhit())//입력을 받는다
		{
			in = getch();
			if (in == left) {
				if (cr.x - 2 > 0) {
					gotoxy(cr.x, cr.y);
					printf("  ");
					cr.x = cr.x - 2;
					gotoxy(cr.x, cr.y);
					printf("★");
				}
			}
			else if (in == right) { //오른쪽으로 가라고 했을때
				if (cr.x + 2 < map_x * 2) {
					gotoxy(cr.x, cr.y);
					printf("  ");
					cr.x = cr.x + 2;
					gotoxy(cr.x, cr.y);
					printf("★");
				}
			}
		}
		else {
			// 게임 속도 조절		
			Sleep(speed);
			// 화면에 동그라미 출력
			printstar();
		}
		// 동그라미를 맞았는지 확인
		checkhit();
	}
}
int main() {
	srand(time(0));

	system("mode con cols=62 lines=26");

	zjtj();//커서 없애는 함수

	printf("┌────────────────────────────────────────┐\n");
	 printf("│                                        │\n");
	printf("│                                        │\n");
	printf("│                                        │\n");
	printf("│        동그라미 피하기 게임            │\n");
	printf("│                                        │\n");
	printf("│                                        │\n");
	printf("│                                        │\n");
	printf("│        아무키나 누르면 시작!           │\n");
	printf("│                                        │\n");
	printf("│        게임 조작키 : 방향키 ←, →     │\n");
	printf("│                                        │\n");
	printf("│                                        │\n");
	printf("│                                        │\n");
	printf("└────────────────────────────────────────┘\n");
	         
	
	getch();
	system("cls");

	field();// 게임 맵의 테두리를 출력해준다.
	
	game();
	
	startgame();

	return 0;
}
