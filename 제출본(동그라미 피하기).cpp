#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>





#define map_x 30//����
#define map_y 22//����
#define STAR map_x-1//�� �ִ밹��
#define left 75//����
#define right 77//������
#define dead 0
#define clear 1
#define score cnt_star * ((stage + 1) * 10)

typedef struct xy {

	int x;

	int y;

};

struct xy star[STAR];
struct xy cr;


int max_star = 0; // �������� �ϴ� ��Ʈ�� ��

int cnt_star = 0; // ������ ��Ʈ�� ��

int speed = 0; // ���� �ӵ�

int stage = 0; // ��������

// ������ ������ ���
void endgame(int); 
 // �⺻ ���� �׵θ� ���
void field();
// ������ �ʱ�ȭ�Ѵ�
void game(); 
// ������ �����Ѵ�
void startgame(); 
// ȭ�鿡 ��Ʈ�� �ѷ��ش�
void printstar(); 
// ���� ĳ���� �浹 üũ
void checkhit();


// �Է¹��� ��ǥ�� �̵����ִ� �Լ�
void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//�������� ���ִ� �Լ�
void zjtj() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible ��� ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // ���氪 ����
}


// �⺻ ���� �׵θ� ���
void field() {
	int i, j;
	// �̸� ������ ���� ���� ũ�⸸ŭ �ݺ�
	for (i = 0; i <= map_y; i++) {
		// �� ó�� ��� ���� ������ �� �϶� ����
		if (i == 0 || i == map_y) {
			for (j = 0; j <= map_x; j++){
				gotoxy(j*2, i);
				
				printf("��");
				
			}
		}
		else// ������ �� �϶� ����
		{
			gotoxy(0, i);
			
			printf("��");

			gotoxy(map_x*2 , i);
			
			printf("��");

		}
	}
	
}

// ������ ������ ���
void endgame(int f) {
	if (f==dead) {
		getch(); system("cls");
		gotoxy(map_x / 2, map_y / 2);
		printf("���׶�̿� �¾� ������ �������ϴ�.\n");
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


// ������ �ʱ�ȭ�Ѵ�
void game() {
	 int cnt = 0;

	 max_star = 50; // �������� �ϴ� ��Ʈ�� ��

	 cnt_star = 0; // ������ ��Ʈ�� ��

	speed = 100; // ���� �ӵ�

	// ��Ʈ ��ġ �ʱ�ȭ
	for (cnt = 0; cnt < STAR; cnt++)

	{

		star[cnt].x = cnt + 1;

		star[cnt].y = rand() % 50;

		star[cnt].x *= 2;

		star[cnt].y *= -1;

	}
	
	cr.x = 30; cr.y = 21;
	gotoxy(cr.x, cr.y);
	printf("��");

	gotoxy(0, map_y + 1);
	printf("STAGE = %d\n", stage + 1);
	
	printf("SCORE = %d\n", score);
	
}
// ȭ�鿡 ���� �ѷ��ش�
// �� x, y��ǥ�� �迭�� ��Ƽ� �ݺ��� �����鼭 �� gotoxy�� �Ű���
//printstar�Լ� �ѹ������ϸ� �� ��ĭ�� ������
//Ŭ���� �ϰų� ���������� printstar�� startgame �Լ����� ���ѹݺ�
void printstar() {
	
	int cnt = 0; int r;
	for (cnt = 0; cnt < STAR; cnt++) {
		//���� ���������
		if (star[cnt].y == map_y - 1) {
			gotoxy(star[cnt].x, star[cnt].y);
			printf("  ");
			cnt_star++;
			gotoxy(0, map_y + 1);
			printf("STAGE = %d\n", stage + 1);
			
			printf("SCORE = %d\n", score);
			
			if (max_star == cnt_star) {
				gotoxy(map_x-20, map_y+1);
				
				printf("�����׶�̸� �� ���ϼ̽��ϴ�. �ƹ�Ű�� �����ּ��䢽");
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
		} while (star[cnt].y > 21);//������ ��ĭ�� ������

		if (star[cnt].y > 1) {
			gotoxy(star[cnt].x, star[cnt].y - 1);
			printf("  ");
			gotoxy(star[cnt].x, star[cnt].y);
			printf("��"); 
		}
		
	}
	
}

// ���� ĳ���� �浹 üũ
void checkhit() {
	int cnt = 0;
	for (cnt = 0; cnt < STAR; cnt++) {
		if (star[cnt].x == cr.x) {
			if (star[cnt].y == cr.y) {
				gotoxy(map_x-13, map_y + 1);
				
				printf("[�浹�Ͽ����ϴ�. �ƹ�Ű�� ��������.]");
				endgame(dead);
			}
		}
	}
}

void startgame() {
	char in = '\0';
	
	while (1) {
		if (kbhit())//�Է��� �޴´�
		{
			in = getch();
			if (in == left) {
				if (cr.x - 2 > 0) {
					gotoxy(cr.x, cr.y);
					printf("  ");
					cr.x = cr.x - 2;
					gotoxy(cr.x, cr.y);
					printf("��");
				}
			}
			else if (in == right) { //���������� ����� ������
				if (cr.x + 2 < map_x * 2) {
					gotoxy(cr.x, cr.y);
					printf("  ");
					cr.x = cr.x + 2;
					gotoxy(cr.x, cr.y);
					printf("��");
				}
			}
		}
		else {
			// ���� �ӵ� ����		
			Sleep(speed);
			// ȭ�鿡 ���׶�� ���
			printstar();
		}
		// ���׶�̸� �¾Ҵ��� Ȯ��
		checkhit();
	}
}
int main() {
	srand(time(0));

	system("mode con cols=62 lines=26");

	zjtj();//Ŀ�� ���ִ� �Լ�

	printf("������������������������������������������������������������������������������������\n");
	 printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("��        ���׶�� ���ϱ� ����            ��\n");
	printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("��        �ƹ�Ű�� ������ ����!           ��\n");
	printf("��                                        ��\n");
	printf("��        ���� ����Ű : ����Ű ��, ��     ��\n");
	printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("��                                        ��\n");
	printf("������������������������������������������������������������������������������������\n");
	         
	
	getch();
	system("cls");

	field();// ���� ���� �׵θ��� ������ش�.
	
	game();
	
	startgame();

	return 0;
}
