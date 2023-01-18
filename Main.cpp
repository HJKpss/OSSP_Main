#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define DINO_BOTTOM_Y 12
#define DINO_BOTTOM_HY 0
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

#define RE_TREE_BOTTOM_HY 1
#define RE_TREE_BOTTOM_X 90

#define RABBIT_BOTTOM_Y 12

#include <stralign.h>
#include <stdlib.h>
#define pause system("pause > nul")    //그냥 내가 많이 쓰는 커맨드를 줄여준 것이다.
#define cls system("cls")    //이것 또한
void SetColor(int color);
void CursorView(char show);
void gotoxy(int x, int y);

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By BlockDMask.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//공룡을 그리는 함수
void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

void DownDrawDino(int dinoY) { //s키를 눌렀을때
	GotoXY(0, dinoY);
	static bool legFlag = true;//높이 7
	printf("                       \n");
	printf("                       \n");
	printf("                       \n");
	printf("                       \n");
	printf("                       \n");
	printf("$               $$$$$$ \n");
	printf("$$$  $$$$$$$$  $$ $$$$$\n");
	printf(" $$$$$$$$$$$$$$$$$$$$$$\n");
	printf("  $$$$$$$$$$$$$$$$$    \n");
	printf("    $$$$$$$$$$$$$$$$$  \n");
	printf("     $$$$$$    $       \n");
	if (legFlag)
	{
	printf("     $    $$$  $$      \n");
	printf("     $$                  ");
		legFlag = false;
	}
	else
	{
	printf("     $$$  $    $$      \n");
	printf("          $$             ");
		legFlag = true;
	}
}

//토끼를 그리는 함수
void DrawRabbit(int rabbitY)
{
	GotoXY(0, rabbitY);
	static bool legFlag = true;
	printf("             \n");
	printf("             \n");
	printf("             \n");
	printf("             \n");
	printf("         $ $ \n");
	printf("         $ $ \n");
	printf("        $$$$ \n");
	printf("$ $$$$$$$$$$$\n");
	printf(" $$$$$$$$$ $$\n");
	printf(" $$$$$$$$$$$$\n");
	//printf("  $$   $$    \n");
	//printf("   $$$  $$   \n");
	if (legFlag)
	{
	printf("  $$   $$    \n");
	printf("   $$$         ");
		legFlag = false;
	}
	else
	{
	printf("  $$   $$    \n");
	printf("        $$     ");
		legFlag = true;
	}
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

//나무를 그리는 함수
void RE_DrawTree(int treeX)
{
	GotoXY(treeX, RE_TREE_BOTTOM_HY);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 1);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 2);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 3);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 4);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 5);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 6);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 7);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 8);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 9);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 10);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 11);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 12);
	printf(" $$ ");
	GotoXY(treeX, RE_TREE_BOTTOM_HY + 13);
	printf("$$$$");
}
struct  lank {
	int score;
	char name[128];
	int cpos;
	char k[128];
};
void sort(lank* a, lank* b) {
	lank c = *a;
	*a = *b;
	*b = c;
}

void bub(lank *b) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (b[j].score < b[j + 1].score) {
				sort(&b[j], &b[j + 1]);
			}
		}
	}
}
void file2(lank *b) {
	FILE* fp = fopen("Lank.txt", "w");
		for (int i = 0; i < 5; i++) {
		fprintf(fp, "%d %s %s\n", b[i].score, b[i].name, b[i].k);
	}
	fclose(fp);
}

void file(lank s){
	if (s.cpos == 1) strcpy(s.k, "디노");
	else strcpy(s.k, "토끼");

	lank a[5];
	lank b[6];
	FILE* fp = fopen("Lank.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%d %s %s\n", &a[i].score, a[i].name, a[i].k);
	}
	fclose(fp);
	for (int i = 0; i < 5; i++) {
		b[i].score = a[i].score;
		strcpy(b[i].name ,a[i].name);
		strcpy(b[i].k, a[i].k);
	}
	b[5].score = s.score;
	strcpy(b[5].name, s.name);
	strcpy(b[5].k, s.k);
	bub(b);
	for (int i = 0; i < 6; i++) {
		printf("%d %s %s\n", b[i].score, b[i].name, b[i].k);
	}	
	file2(b);
}

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score, char s[], int n)
{
	system("cls");
	struct lank LL;
	LL.score = score;
	strcpy(LL.name, s);
	LL.cpos = n;
	file(LL);
	int x = 60;
	int y = 8;
	printf("\n\n");
	printf(" ================================================================================================================== \n\n");
	printf("                                    =========== G A M E O V E R ===========                                         \n\n");
	printf("                                                   SCORE : %d                                                       \n\n", score);
	printf(" ================================================================================================================== \n\n");
	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

//(v2.0) 충돌했으면 true, 아니면 false
bool isCollision(const int treeX,const int RE_treeX, const int dinoY, const int dinoHY)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d dinoHY : %d", treeX, dinoY, dinoHY); //이런식으로 적절한 X, Y를 찾습니다.
	if (treeX <= 8 && treeX >= 4 &&
		dinoY > 8)
	{
		return true;
	}
	if (RE_treeX <= 8 && RE_treeX >= 4 &&
		dinoHY < 5)
	{
		return true;
	}
	return false;
}

bool isCollision1(const int treeX, const int rabbitY)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	printf("treeX : %d, rabbitY : %d", treeX, rabbitY); //이런식으로 적절한 X, Y를 찾습니다.
	if (treeX <= 8 && treeX >= 4 &&
		rabbitY > 8)
	{
		return true;
	}
	return false;
}

//수정
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleView1()
{
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	system("mode con cols=120 lines=30 | title MyGame");
	printf("\n");
	printf(" ================================================================================================================== \n");
	printf("||                                                                                                                ||\n");
	printf("||                                                                                                                ||\n");
	printf("||                #     #     #######     #             #####      #####      ##   ##     #######                 ||\n");
	printf("||                #  #  #     #           #            #          #     #     # # # #     #                       ||\n");
	printf("||                # # # #     ######      #            #          #     #     #  #  #     ######                  ||\n");
	printf("||                # # # #     #           #            #          #     #     #     #     #                       ||\n");
	printf("||                 #   #      #######     #######       #####      #####      #     #     #######                 ||\n");
	printf("||                                                                                                                ||\n");
	printf("||                                                                                                                ||\n");
	printf(" ================================================================================================================== \n");
	printf("\n");
	gotoxy(25, 13); printf("1. 게임시작 ");
	gotoxy(50, 13); printf("2. 랭킹 ");
	gotoxy(75, 13); printf("3. 게임종료");
	printf("\n\n\n");
}
int sel(char s[], int* cpos) {
	cls;
	char name[128];
	int n;
	printf("닉네임을 입력하세요.>> ");
	scanf("%s", name);
	printf("캐릭터를 선택하세요. (1->디노, 2->토끼) >> ");
	scanf("%d", &n);
	strcpy(s, name);
	*cpos = n;
	if (n == 1) {
		printf("캐릭터:디노\n");
		return *cpos;
	}
	else {
		printf("캐릭터:토끼\n");
		return *cpos;
	}
}

void start() {
	for (int n = 3; n >= 0; --n) {
		cls;
		if (n == 0) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                             #######     #######        #        ######      #######                            ||\n");
			printf("||                             #              #          # #       #     #        #                               ||\n");
			printf("||                             #######        #         #####      ######         #                               ||\n");
			printf("||                                   #        #        #     #     #    #         #                               ||\n");
			printf("||                             #######        #        #     #     #     #        #                               ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 1) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                        ##                                                      ||\n");
			printf("||                                                       # #                                                      ||\n");
			printf("||                                                         #                                                      ||\n");
			printf("||                                                         #                                                      ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 2) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                      #                                                         ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		else if (n == 3) {
			printf("\n");
			printf(" ================================================================================================================== \n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                            #                                                   ||\n");
			printf("||                                                      #######                                                   ||\n");
			printf("||                                                                                                                ||\n");
			printf("||                                                                                                                ||\n");
			printf(" ================================================================================================================== \n");
			printf("\n");
		}
		Sleep(500);
	}
}



int main()
{
	char name[128];
	int cpos=1; // 캐릭터 선택
	int POS = 0;	//0 - 게임시작, 1 - 랭킹, 2 - 게임 종료
	SetConsoleView1();
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 2;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 2) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(25, 13); printf("1. 게임시작 ");
			SetColor(15);
			gotoxy(50, 13); printf("2. 랭킹 ");
			gotoxy(75, 13); printf("3. 게임종료");
			break;
		case 1:
			gotoxy(25, 13); printf("1. 게임시작 ");
			SetColor(11);
			gotoxy(50, 13); printf("2. 랭킹 ");
			SetColor(15);
			gotoxy(75, 13); printf("3. 게임종료");
			break;
		case 2:
			gotoxy(25, 13); printf("1. 게임시작 ");
			gotoxy(50, 13); printf("2. 랭킹 ");
			SetColor(11);
			gotoxy(75, 13); printf("3. 게임종료");
			SetColor(15);
			break;
		default: break;
		}
		Sleep(100);
	}
	cls;

	
	if (POS == 0) {//구글디노
		while (true)		//(v2.0) 게임 루프
		{
			sel(name, &cpos);

			//start();//게임시작대기

			//게임 시작시 초기화
			bool isJumping = false;
			bool isBottom = true;
			const int gravity = 3;

			int dinoY = DINO_BOTTOM_Y;
			int dinoHY = DINO_BOTTOM_HY;
			int treeX = TREE_BOTTOM_X;
			int RE_treeX = RE_TREE_BOTTOM_X;
			int rabbitY = RABBIT_BOTTOM_Y;

			int score = 0;
			clock_t start, curr;	//점수 변수 초기화
			start = clock();		//시작시간 초기화
			if (cpos == 1) {
				while (true)	//한 판에 대한 루프
				{
					//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
					if (isCollision(treeX, RE_treeX, dinoY, dinoHY))
						break;

					//z키가 눌렸고, 바닥이 아닐때 점프
					if (GetKeyDown() == 'w' && isBottom)
					{
						isJumping = true;
						isBottom = false;
					}

					//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
					if (isJumping)
					{
						dinoY -= gravity;
					}
					else
					{
						dinoY += gravity;
					}

					//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
					if (dinoY >= DINO_BOTTOM_Y)
					{
						dinoY = DINO_BOTTOM_Y;
						isBottom = true;
					}

					//나무가 왼쪽으로 (x음수) 가도록하고
					//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
					treeX -= 2;
					if (treeX <= -45)
					{
						treeX = TREE_BOTTOM_X;
					}

					RE_treeX -= 2;
					if (RE_treeX <= 0)
					{
						RE_treeX = RE_TREE_BOTTOM_X;
					}


					//점프의 맨위를 찍으면 점프가 끝난 상황.
					if (dinoY <= 3)
					{
						isJumping = false;
					}

					if (GetKeyDown() == 's')
					{
						DownDrawDino(dinoY);		//draw dino
						dinoHY = 5;
					}

					else {
						DrawDino(dinoY);
						dinoHY = 0;
					}//draw dino
					if (0 <= treeX) {
						DrawTree(treeX);		//draw Tree
					}
					if (0 <= RE_treeX && RE_treeX <= 45) {
						RE_DrawTree(RE_treeX);
					}

					//(v2.0)
					curr = clock();			//현재시간 받아오기
					if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을
					{
						score++;	//스코어 UP
						start = clock();	//시작시간 초기화
					}
					Sleep(60);
					system("cls");	//clear

					//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
					GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
					printf("Score : %d ", score);	//점수 출력해줌.
				}

				//(v2.0) 게임 오버 메뉴
				DrawGameOver(score, name, cpos);
			}
			else {
				while (true)	//한 판에 대한 루프
				{
					//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
					const int gravity1 = 4.5;
					if (isCollision1(treeX, rabbitY))
						break;

					//z키가 눌렸고, 바닥이 아닐때 점프
					if (GetKeyDown() == 'w' && isBottom)
					{
						isJumping = true;
						isBottom = false;
					}

					//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
					if (isJumping)
					{
						rabbitY -= gravity1;
					}
					else
					{
						rabbitY += gravity1;
					}

					//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
					if (rabbitY >= RABBIT_BOTTOM_Y)
					{
						rabbitY = RABBIT_BOTTOM_Y;
						isBottom = true;
					}

					//나무가 왼쪽으로 (x음수) 가도록하고
					//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
					treeX -= 2;
					if (treeX <= -45)
					{
						treeX = TREE_BOTTOM_X;
					}

					RE_treeX -= 2;
					if (RE_treeX <= 0)
					{
						RE_treeX = RE_TREE_BOTTOM_X;
					}

					//점프의 맨위를 찍으면 점프가 끝난 상황.
					if (rabbitY <= 3)
					{
						isJumping = false;
					}

					DrawRabbit(rabbitY);
					

					if (0 <= treeX) {
						DrawTree(treeX);		//draw Tree
					}
					if (0 <= RE_treeX && RE_treeX <= 45) {
						RE_DrawTree(RE_treeX);
					}

					//(v2.0)
					curr = clock();			//현재시간 받아오기
					if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을
					{
						score++;	//스코어 UP
						start = clock();	//시작시간 초기화
					}
					Sleep(60);
					system("cls");	//clear

					//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
					GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
					printf("Score : %d ", score);	//점수 출력해줌.
				}

				//(v2.0) 게임 오버 메뉴
				DrawGameOver(score, name, cpos);
			}
		}
	}
	else if (POS == 1) {//랭킹

	}
	else puts("게임종료를 눌렀습니다.");//게임종료

	return 0;
}