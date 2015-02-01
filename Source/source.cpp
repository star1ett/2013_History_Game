/*
재미없는 역사 미로 v1.2
10107 김지훈
*/

#include "header.h"
#define RAN(map) rand()%((sizeof(map)/(sizeof(int))/100))	// 맵 랜덤 생성

void menu();

enum {HIDDEN, SHOW};
int map[50][80];
int map_x=50, map_y=30;	// 맵 크기
int qrand=5;		// 빈 공간에 문제가 나올 확률(1/N)
int key_delay=150;		// 키입력 지연시간
char problem[100][100];		//문제 배열 [문제번호]
char answer[100][4][20];	//답지 배열 [문제번호][답지번호]
int p_number;			// 문제의 개수
int health_point;		// HP
int start_time;			//게임 시작시간


void endgame(int win)
{
	gotoxy(map_x-15, map_y/2-4);
	win ? setcolor(10,0) : setcolor(12,0);
	gotoxy(map_x-15, map_y/2-5);	printf("┏━━━━━━━━━━━━━┓");
	gotoxy(map_x-15, map_y/2-4);win?printf("┃       축하합니다!        ┃") :
									printf("┃     패배하셨습니다!      ┃");
	gotoxy(map_x-15, map_y/2-3);win?printf("┃  미로를 빠져나왔습니다.  ┃") :
									printf("┃   체력이 바닥났습니다.   ┃");
	gotoxy(map_x-15, map_y/2-2);	printf("┃                          ┃");
	gotoxy(map_x-15, map_y/2-1);	printf("┃   *** 플레이  정보 ***   ┃");
	gotoxy(map_x-15, map_y/2);		printf("┃     맵 크기: %2d * %2d     ┃",map_x,map_y);
	gotoxy(map_x-15, map_y/2+1);	printf("┃ 플레이 시간: %3ds        ┃",(clock()-start_time)/1000);
	gotoxy(map_x-15, map_y/2+2);	printf("┗━━━━━━━━━━━━━┛");
	while(1)
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000 || GetAsyncKeyState(VK_RETURN)==0xffff8000)
			menu();
}

void printhp()
{
	int i;
	gotoxy(map_x*2+5,map_y-2);
	printf("HP: ");
	if (health_point>10)
		health_point=10;
	if (health_point>=4)
		setcolor(10,0);
	else if (health_point>=2)
		setcolor(14,0);
	else if (health_point==1)
		setcolor(12,0);
	else{
		setcolor(12,0);
		printf("0");
		endgame(0);
	}
	for (i=0; i<health_point; i++)
		printf("■");
	for (i=0; i<10-health_point; i++)
		printf(" ");
	setcolor(7,0);
}

void question()
{
	int i, j;
	int p_rand=rand()%p_number;
	int ran_answer[4]={1,2,3,4};
	int real_answer;		//정답
	for (i=0; i<100; i++){
		if (i%35==0)
			gotoxy((map_x+1)*2,4+i/35);
		if (problem[p_rand][i]==NULL)
			printf(" ");
		else printf("%c",problem[p_rand][i]);
	}
	for (i=0; i<4; i++){
		int ran_answer_selected;	//ran_answer 배열에서 몇번째 값을 골랐는지 포인트
		gotoxy((map_x+1)*2,8+i);
		for (j=0; j<20; j++)
			printf(" ");
		gotoxy((map_x+1)*2,8+i);
		ran_answer_selected=rand()%(4-i);
		if (ran_answer[ran_answer_selected]==1) real_answer=i;
		printf(" %d%s",i+1,answer[p_rand][ran_answer[ran_answer_selected]-1]);
		for (j=ran_answer_selected; j<3-i; j++)
			ran_answer[j]=ran_answer[j+1];
	}
	gotoxy((map_x+3)*2,15);
	while (1){
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			menu();
		else if (GetAsyncKeyState(0x31)==0xffff8000 || GetAsyncKeyState(0x61)==0xffff8000 ||
			GetAsyncKeyState(0x32)==0xffff8000 || GetAsyncKeyState(0x33)==0xffff8000 || GetAsyncKeyState(0x34)==0xffff8000 || 
			GetAsyncKeyState(0x62)==0xffff8000 || GetAsyncKeyState(0x63)==0xffff8000 || GetAsyncKeyState(0x64)==0xffff8000){
			if (GetAsyncKeyState(0x31+real_answer)==0xffff8000 || GetAsyncKeyState(0x61+real_answer)){
				switch(rand()%10){
				case 9:
				case 8:{
					printf("정답입니다. 보너스 체력 +1    ");
					health_point++;
					printhp();
					break;
					   }
				case 7:{
					printf("정답입니다. 보너스 체력 +2    ");
					health_point+=2;
					printhp();
					break;
					   }
				default:{
					printf("정답입니다.                   ");
						}
				}
				break;
			}
			else{
				printf("틀렸습니다. 답은 %d번입니다.",real_answer+1);
				health_point--;
				printhp();
				break;
			}
		}
	}
}

void printmap()		// 맵 프린트
{
	system("cls");
	char sys[100];
	sprintf(sys,"mode con cols=%d lines=%d",map_x*2+40,map_y+1);
	system(sys);
	srand(time(NULL));
	int i, j, k, num=RAN(firstmap);
	for (i=0; i<10; i++)
		for (j=0; j<10; j++){
			if (firstmap[num][i][j]==0 && rand()%qrand==0 && (i!=1 || j!=1))
				map[i][j]=2;
			else
				map[i][j]=firstmap[num][i][j];
		}
		for (i=0; i<((map_x/10)*(map_y/10)-2); i++){
			num=RAN(mainmap);
			for (j=0; j<10; j++)
				for (k=0; k<10; k++){
				if (mainmap[num][j][k]==0 && rand()%qrand==0)
					map[(i+1)/(map_x/10)*10+j][(i+1)%(map_x/10)*10+k]=2;
				else
					map[(i+1)/(map_x/10)*10+j][(i+1)%(map_x/10)*10+k]=mainmap[num][j][k];
			}
	}
	num=RAN(lastmap);
	for (i=0; i<10; i++)
		for (j=0; j<10; j++){
			if (lastmap[num][i][j]==0 && rand()%qrand==0 && (i!=8 || j!=8))
				map[map_y-10+i][map_x-10+j]=2;
			else
				map[map_y-10+i][map_x-10+j]=lastmap[num][i][j];
		}
	for (i=0; i<map_x; i++)
		map[map_y-1][i]=1;
	for (i=0; i<map_y; i++)
		map[i][map_x-1]=1;
	for (i=0; i<map_y; i++){
		for (j=0; j<map_x; j++)
			switch (map[i][j]){
			case 0: printf("  "); break;
			case 1: printf("▩"); break;
			case 2: printf("Qu"); break;
		}
		printf("\n");
	}
	setcolor(15,0);
	for (i=0; i<map_y; i++){
		gotoxy(map_x*2,i);
		printf("┃");
	}
	setcolor(7,0);
	gotoxy((map_x+1)*2,1); printf("┌────┐");
	gotoxy((map_x+1)*2,2); printf("│ 문  제 │");
	gotoxy((map_x+1)*2,3); printf("└────┘");
}

void menu1()	//게임
{
	int x=1, y=1;
	int i, j;
	health_point=5;
	for (i=0; i<map_y; i++)
		for (j=0; j<map_x; j++)
			if (map[i][j]==2) map[i][j]=0;
	printmap();
	printhp();
	setcolor(14,0);
	gotoxy(x*2,y);
	printf("◎");
	gotoxy((map_x-2)*2,map_y-2);
	printf("▣");
	setcolor(7,0);
	start_time=clock();
	while(1){
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			menu();
		else if (GetAsyncKeyState(VK_UP)==0xffff8000 && y>0){
			switch(map[y-1][x]){
			case 0:{
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,--y);
				if (x==map_x-2 && y==map_y-2)
					endgame(1);
				printf("◎");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y-1][x]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,--y);
				printf("◎");
				setcolor(7,0);
				question();
				Sleep(key_delay);
				break;
				   }
			}
		}
		else if (GetAsyncKeyState(VK_DOWN)==0xffff8000 && y<map_y-1){
			switch(map[y+1][x]){
			case 0:{
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,++y);
				if (x==map_x-2 && y==map_y-2)
					endgame(1);
				printf("◎");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y+1][x]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,++y);
				printf("◎");
				setcolor(7,0);
				question();
				Sleep(key_delay);
				break;
				   }
			}
		}
		else if (GetAsyncKeyState(VK_LEFT)==0xffff8000 && x>0){
			switch(map[y][x-1]){
			case 0:{
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(--x*2,y);
				if (x==map_x-2 && y==map_y-2)
					endgame(1);
				printf("◎");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y][x-1]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(--x*2,y);
				printf("◎");
				setcolor(7,0);
				question();
				Sleep(key_delay);
				break;
				   }
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT)==0xffff8000 && x<map_x-1){
			switch(map[y][x+1]){
			case 0:{
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(++x*2,y);
				if (x==map_x-2 && y==map_y-2)
					endgame(1);
				printf("◎");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y][x+1]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(++x*2,y);
				printf("◎");
				setcolor(7,0);
				question();
				Sleep(key_delay);
				break;
				   }
			}
		}
	}
}

void menu2()	//게임방법
{
	system("cls");
	system("mode con cols=45 lines=35");
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("              ***  게임방법  ***           \n\n\n");
	setcolor(7,0);
	printf("  '게임하기' 메뉴로 들어가 게임을 시작하면\n");
	printf("  좌측 상단에 '◎'와 같이 생긴 노란색 원이\n");
	printf("  보일 것입니다. 이 원이 플레이어의 위치를\n");
	printf("  나타냅니다. 플레이어는 방향키를 이용하여\n");
	printf("  이 원을 움직일 수 있습니다. 하지만 만약 \n");
	printf("  플레이어가 이동하려는 방향에 '▩'와 같은\n");
	printf("  모양이 있다면, 그 방향으로는 이동할 수가\n");
	printf("  없습니다. 또, 플레이어가 이동하고자 하는\n");
	printf("  위치에 'Qu'라는 글자가 있을 수 있습니다.\n");
	printf("  이 글자가 존재하는 위치로 이동하려 하면,\n");
	printf("  화면 하단에 있는 문제창에 역사와 관련된 \n");
	printf("  문제가 출력됩니다. 답이라고 생각되어지는\n");
	printf("  문제지의 번호를 키보드로 누르기 전까지  \n");
	printf("  다른 위치로 이동할 수 없습니다. 문제의  \n");
	printf("  정답을 맞추게 되면 화면 하단에 표시되는 \n");
	printf("  HP가 줄어들지 않고, 20% 확률로 추가 HP  \n");
	printf("  1점 또는 10% 확률로 추가 HP 2점을 획득할\n");
	printf("  수 있습니다. 하지만 문제를 틀리게 되면  \n");
	printf("  HP가 줄어들며, HP가 0이 되면 게임이 종료\n");
	printf("  되고 맙니다. 이 게임의 최종 목표는 HP를 \n");
	printf("  0이 되지 않도록 문제의 정답을 잘 맞추며 \n");
	printf("  화면 우측 하단에 있는 '▣' 모양의 노란색\n");
	printf("  사각형으로 원을 이동시키는 것입니다.    \n");
	while(1)
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			menu();
}

void menu3()	//옵션
{
	system("cls");
	int select=1;
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("            ***  옵  션  ***\n\n\n");
	setcolor(7,0);
	printf("           ▶ 맵크기(가로) ◀\n\n");
	printf("              맵크기(세로)   \n\n");
	printf("              문제제출확률   \n\n");
	printf("             키입력지연시간  \n\n\n");
	printf("────────────────────\n");
	printf("         맵크기(가로) 설정하기\n");
	printf("                ◀ %2d ▶",map_x);
	Sleep(300);
	while(1)
	{
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			menu();
		else if (GetAsyncKeyState(VK_UP)&&select!=1){
			gotoxy(11,select*2+5);
			printf(" ");
			gotoxy(27,select*2+5);
			printf(" ");
			select--;
			gotoxy(11,select*2+5);
			printf("▶");
			gotoxy(27,select*2+5);
			printf("◀");
			gotoxy(0,18);
			switch (select){
			case 1:{
				printf("         맵크기(가로) 설정하기\n");
				printf("                ◀ %2d ▶    ",map_x);
				break;
				   }
			case 2:{
				printf("         맵크기(세로) 설정하기\n");
				printf("                ◀ %2d ▶    ",map_y);
				break;
				   }
			case 3:{
				printf("         문제제출확률 설정하기\n");
				printf("               ◀ 1/%2d ▶  ",qrand);
				break;
				   }
			case 4:{
				printf("        키입력지연시간 설정하기\n");
				printf("            ◀ 약  %3dms ▶",key_delay);
				   }
			}
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_DOWN)&&select!=4){
			gotoxy(11,select*2+5);
			printf(" ");
			gotoxy(27,select*2+5);
			printf(" ");
			select++;
			gotoxy(11,select*2+5);
			printf("▶");
			gotoxy(27,select*2+5);
			printf("◀");
			gotoxy(0,18);
			switch (select){
			case 1:{
				printf("         맵크기(가로) 설정하기\n");
				printf("                ◀ %2d ▶    ",map_x);
				break;
				   }
			case 2:{
				printf("         맵크기(세로) 설정하기\n");
				printf("                ◀ %2d ▶    ",map_y);
				break;
				   }
			case 3:{
				printf("         문제제출확률 설정하기\n");
				printf("               ◀ 1/%2d ▶  ",qrand);
				break;
				   }
			case 4:{
				printf("        키입력지연시간 설정하기\n");
				printf("             ◀ 약 %3dms ▶",key_delay);
				   }
			}
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_LEFT)==0xffff8000){
			gotoxy(0,19);
			switch (select){
			case 1:{
				if (map_x>30) map_x-=10;
				printf("                ◀ %2d ▶  ",map_x);
				break;
				   }
			case 2:{
				if (map_y>20) map_y-=10;
				printf("                ◀ %2d ▶  ",map_y);
				break;
				   }
			case 3:{
				if (qrand>3) qrand--;
				printf("               ◀ 1/%2d ▶  ",qrand);
				break;
				   }
			case 4:{
				if (key_delay>50) key_delay-=50;
				printf("             ◀ 약 %3dms ▶",key_delay);
				break;
				   }
			}
			Sleep(200);
		}
		else if (GetAsyncKeyState(VK_RIGHT)==0xffff8000){
			gotoxy(0,19);
			switch (select){
			case 1:{
				if (map_x<60) map_x+=10;
				printf("                ◀ %2d ▶  ",map_x);
				break;
				   }
			case 2:{
				if (map_y<50) map_y+=10;
				printf("                ◀ %2d ▶  ",map_y);
				break;
				   }
			case 3:{
				if (qrand<10) qrand++;
				printf("               ◀ 1/%2d ▶  ",qrand);
				break;
				   }
			case 4:{
				if (key_delay<300) key_delay+=50;
				printf("             ◀ 약 %3dms ▶",key_delay);
				break;
				   }
			}
			Sleep(200);
		}
	}
}

void menu4()	//정보
{
	system("cls");
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("            ***  정  보  ***\n\n\n");
	setcolor(7,0);
	printf(" < 제 작 자 > 정보통신과 10107 김지훈\n\n");
	printf(" < 개발기간 > 2013. 8. 22. ~ 9. 21.  \n\n");
	printf(" < 개발환경 > Visual Studio 2012 Pro \n\n");
	printf(" < 도    움 > 백지훈 고맙다zz      \n\n\n");
	printf("────────────────────\n");
	printf(" 엔터를 누르시면 info.hwp로 연결됩니다.\n");
	printf("    메뉴로 나가시려면 ESC를 누르세요.");
	Sleep(200);
	while(1){
		if (GetAsyncKeyState(VK_ESCAPE))
			menu();
		else if (GetAsyncKeyState(VK_RETURN)==0xffff8000){
			system("start /b info.hwp");
			menu();
		}
	}
}

void menu()
{
	int select=1;
	system("cls");
	system("mode con cols=40 lines=25");
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("        ┌──────────┐\n");
	printf("        │ 재미없는 역사 미로 │\n");
	printf("        └──────────┘\n\n");
	printf("            ***  메  뉴  ***\n\n");
	printf("             ▶ 게임하기 ◀\n\n");
	setcolor(7,0);
	printf("                게임방법   \n\n");
	printf("                  옵션     \n\n");
	printf("                  정보     \n\n");
	printf("                  종료     ");
	Sleep(300);
	while(1)
	{
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			exit(0);
		else if (GetAsyncKeyState(VK_RETURN)==0xffff8000)
			switch (select){
			case 1: menu1(); break;
			case 2: menu2(); break;
			case 3: menu3(); break;
			case 4: menu4(); break;
			case 5: exit(0); break;
		}
		else if (GetAsyncKeyState(VK_UP)&&select!=1){
			gotoxy(0,select*2+8);
			switch (select){
			case 2: printf("                게임방법   "); break;
			case 3: printf("                  옵션     "); break;
			case 4: printf("                  정보     "); break; 
			case 5: printf("                  종료     "); break;
			}
			select--;
			setcolor(15,0);
			gotoxy(0,select*2+8);
			switch (select){
			case 1: printf("             ▶ 게임하기 ◀"); break;
			case 2: printf("             ▶ 게임방법 ◀"); break;
			case 3: printf("             ▶   옵션   ◀"); break;
			case 4: printf("             ▶   정보   ◀"); break;
			}
			setcolor(7,0);
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_DOWN)&&select!=5){
			gotoxy(0,select*2+8);
			switch (select){
			case 1: printf("                게임하기   "); break;
			case 2: printf("                게임방법   "); break;
			case 3: printf("                  옵션     "); break;
			case 4: printf("                  정보     "); break;
			}
			select++;
			setcolor(15,0);
			gotoxy(0,select*2+8);
			switch (select){
			case 2: printf("             ▶ 게임방법 ◀"); break;
			case 3: printf("             ▶   옵션   ◀"); break;
			case 4: printf("             ▶   정보   ◀"); break;
			case 5: printf("             ▶   종료   ◀"); break;
			}
			setcolor(7,0);
			Sleep(150);
		}
	}
}

void main()
{
	CursorView(HIDDEN);
	SetConsoleTitle(TEXT("재미없는 역사 미로 v1.2"));
	int a_point=0;
	char temp[200];
	FILE *prob=fopen("problems.dat","r");
	while(1){
		fgets(temp,100,prob);
		if (strcmp(temp,"END")==0) break;
		if (temp[0]=='Q'){
			temp[strlen(temp)-1]=0;
			strcpy(problem[p_number],temp);
			a_point=0;
			while(a_point!=4){
				fgets(temp,20,prob);
				if (temp[0]=='A'){
					temp[0]=' ';
					strcpy(answer[p_number][a_point++],temp);
				}
			}
			p_number++;
		}
	}
	fclose(prob);
	menu();
}