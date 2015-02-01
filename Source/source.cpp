/*
��̾��� ���� �̷� v1.2
10107 ������
*/

#include "header.h"
#define RAN(map) rand()%((sizeof(map)/(sizeof(int))/100))	// �� ���� ����

void menu();

enum {HIDDEN, SHOW};
int map[50][80];
int map_x=50, map_y=30;	// �� ũ��
int qrand=5;		// �� ������ ������ ���� Ȯ��(1/N)
int key_delay=150;		// Ű�Է� �����ð�
char problem[100][100];		//���� �迭 [������ȣ]
char answer[100][4][20];	//���� �迭 [������ȣ][������ȣ]
int p_number;			// ������ ����
int health_point;		// HP
int start_time;			//���� ���۽ð�


void endgame(int win)
{
	gotoxy(map_x-15, map_y/2-4);
	win ? setcolor(10,0) : setcolor(12,0);
	gotoxy(map_x-15, map_y/2-5);	printf("������������������������������");
	gotoxy(map_x-15, map_y/2-4);win?printf("��       �����մϴ�!        ��") :
									printf("��     �й��ϼ̽��ϴ�!      ��");
	gotoxy(map_x-15, map_y/2-3);win?printf("��  �̷θ� �������Խ��ϴ�.  ��") :
									printf("��   ü���� �ٴڳ����ϴ�.   ��");
	gotoxy(map_x-15, map_y/2-2);	printf("��                          ��");
	gotoxy(map_x-15, map_y/2-1);	printf("��   *** �÷���  ���� ***   ��");
	gotoxy(map_x-15, map_y/2);		printf("��     �� ũ��: %2d * %2d     ��",map_x,map_y);
	gotoxy(map_x-15, map_y/2+1);	printf("�� �÷��� �ð�: %3ds        ��",(clock()-start_time)/1000);
	gotoxy(map_x-15, map_y/2+2);	printf("������������������������������");
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
		printf("��");
	for (i=0; i<10-health_point; i++)
		printf(" ");
	setcolor(7,0);
}

void question()
{
	int i, j;
	int p_rand=rand()%p_number;
	int ran_answer[4]={1,2,3,4};
	int real_answer;		//����
	for (i=0; i<100; i++){
		if (i%35==0)
			gotoxy((map_x+1)*2,4+i/35);
		if (problem[p_rand][i]==NULL)
			printf(" ");
		else printf("%c",problem[p_rand][i]);
	}
	for (i=0; i<4; i++){
		int ran_answer_selected;	//ran_answer �迭���� ���° ���� ������� ����Ʈ
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
					printf("�����Դϴ�. ���ʽ� ü�� +1    ");
					health_point++;
					printhp();
					break;
					   }
				case 7:{
					printf("�����Դϴ�. ���ʽ� ü�� +2    ");
					health_point+=2;
					printhp();
					break;
					   }
				default:{
					printf("�����Դϴ�.                   ");
						}
				}
				break;
			}
			else{
				printf("Ʋ�Ƚ��ϴ�. ���� %d���Դϴ�.",real_answer+1);
				health_point--;
				printhp();
				break;
			}
		}
	}
}

void printmap()		// �� ����Ʈ
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
			case 1: printf("��"); break;
			case 2: printf("Qu"); break;
		}
		printf("\n");
	}
	setcolor(15,0);
	for (i=0; i<map_y; i++){
		gotoxy(map_x*2,i);
		printf("��");
	}
	setcolor(7,0);
	gotoxy((map_x+1)*2,1); printf("������������");
	gotoxy((map_x+1)*2,2); printf("�� ��  �� ��");
	gotoxy((map_x+1)*2,3); printf("������������");
}

void menu1()	//����
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
	printf("��");
	gotoxy((map_x-2)*2,map_y-2);
	printf("��");
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
				printf("��");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y-1][x]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,--y);
				printf("��");
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
				printf("��");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y+1][x]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(x*2,++y);
				printf("��");
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
				printf("��");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y][x-1]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(--x*2,y);
				printf("��");
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
				printf("��");
				setcolor(7,0);
				Sleep(key_delay);
				break;
				   }
			case 2:{
				map[y][x+1]=0;
				gotoxy(x*2,y); printf("  ");
				setcolor(14,0);
				gotoxy(++x*2,y);
				printf("��");
				setcolor(7,0);
				question();
				Sleep(key_delay);
				break;
				   }
			}
		}
	}
}

void menu2()	//���ӹ��
{
	system("cls");
	system("mode con cols=45 lines=35");
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("              ***  ���ӹ��  ***           \n\n\n");
	setcolor(7,0);
	printf("  '�����ϱ�' �޴��� �� ������ �����ϸ�\n");
	printf("  ���� ��ܿ� '��'�� ���� ���� ����� ����\n");
	printf("  ���� ���Դϴ�. �� ���� �÷��̾��� ��ġ��\n");
	printf("  ��Ÿ���ϴ�. �÷��̾�� ����Ű�� �̿��Ͽ�\n");
	printf("  �� ���� ������ �� �ֽ��ϴ�. ������ ���� \n");
	printf("  �÷��̾ �̵��Ϸ��� ���⿡ '��'�� ����\n");
	printf("  ����� �ִٸ�, �� �������δ� �̵��� ����\n");
	printf("  �����ϴ�. ��, �÷��̾ �̵��ϰ��� �ϴ�\n");
	printf("  ��ġ�� 'Qu'��� ���ڰ� ���� �� �ֽ��ϴ�.\n");
	printf("  �� ���ڰ� �����ϴ� ��ġ�� �̵��Ϸ� �ϸ�,\n");
	printf("  ȭ�� �ϴܿ� �ִ� ����â�� ����� ���õ� \n");
	printf("  ������ ��µ˴ϴ�. ���̶�� �����Ǿ�����\n");
	printf("  �������� ��ȣ�� Ű����� ������ ������  \n");
	printf("  �ٸ� ��ġ�� �̵��� �� �����ϴ�. ������  \n");
	printf("  ������ ���߰� �Ǹ� ȭ�� �ϴܿ� ǥ�õǴ� \n");
	printf("  HP�� �پ���� �ʰ�, 20% Ȯ���� �߰� HP  \n");
	printf("  1�� �Ǵ� 10% Ȯ���� �߰� HP 2���� ȹ����\n");
	printf("  �� �ֽ��ϴ�. ������ ������ Ʋ���� �Ǹ�  \n");
	printf("  HP�� �پ���, HP�� 0�� �Ǹ� ������ ����\n");
	printf("  �ǰ� ���ϴ�. �� ������ ���� ��ǥ�� HP�� \n");
	printf("  0�� ���� �ʵ��� ������ ������ �� ���߸� \n");
	printf("  ȭ�� ���� �ϴܿ� �ִ� '��' ����� �����\n");
	printf("  �簢������ ���� �̵���Ű�� ���Դϴ�.    \n");
	while(1)
		if (GetAsyncKeyState(VK_ESCAPE)==0xffff8000)
			menu();
}

void menu3()	//�ɼ�
{
	system("cls");
	int select=1;
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("            ***  ��  ��  ***\n\n\n");
	setcolor(7,0);
	printf("           �� ��ũ��(����) ��\n\n");
	printf("              ��ũ��(����)   \n\n");
	printf("              ��������Ȯ��   \n\n");
	printf("             Ű�Է������ð�  \n\n\n");
	printf("����������������������������������������\n");
	printf("         ��ũ��(����) �����ϱ�\n");
	printf("                �� %2d ��",map_x);
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
			printf("��");
			gotoxy(27,select*2+5);
			printf("��");
			gotoxy(0,18);
			switch (select){
			case 1:{
				printf("         ��ũ��(����) �����ϱ�\n");
				printf("                �� %2d ��    ",map_x);
				break;
				   }
			case 2:{
				printf("         ��ũ��(����) �����ϱ�\n");
				printf("                �� %2d ��    ",map_y);
				break;
				   }
			case 3:{
				printf("         ��������Ȯ�� �����ϱ�\n");
				printf("               �� 1/%2d ��  ",qrand);
				break;
				   }
			case 4:{
				printf("        Ű�Է������ð� �����ϱ�\n");
				printf("            �� ��  %3dms ��",key_delay);
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
			printf("��");
			gotoxy(27,select*2+5);
			printf("��");
			gotoxy(0,18);
			switch (select){
			case 1:{
				printf("         ��ũ��(����) �����ϱ�\n");
				printf("                �� %2d ��    ",map_x);
				break;
				   }
			case 2:{
				printf("         ��ũ��(����) �����ϱ�\n");
				printf("                �� %2d ��    ",map_y);
				break;
				   }
			case 3:{
				printf("         ��������Ȯ�� �����ϱ�\n");
				printf("               �� 1/%2d ��  ",qrand);
				break;
				   }
			case 4:{
				printf("        Ű�Է������ð� �����ϱ�\n");
				printf("             �� �� %3dms ��",key_delay);
				   }
			}
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_LEFT)==0xffff8000){
			gotoxy(0,19);
			switch (select){
			case 1:{
				if (map_x>30) map_x-=10;
				printf("                �� %2d ��  ",map_x);
				break;
				   }
			case 2:{
				if (map_y>20) map_y-=10;
				printf("                �� %2d ��  ",map_y);
				break;
				   }
			case 3:{
				if (qrand>3) qrand--;
				printf("               �� 1/%2d ��  ",qrand);
				break;
				   }
			case 4:{
				if (key_delay>50) key_delay-=50;
				printf("             �� �� %3dms ��",key_delay);
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
				printf("                �� %2d ��  ",map_x);
				break;
				   }
			case 2:{
				if (map_y<50) map_y+=10;
				printf("                �� %2d ��  ",map_y);
				break;
				   }
			case 3:{
				if (qrand<10) qrand++;
				printf("               �� 1/%2d ��  ",qrand);
				break;
				   }
			case 4:{
				if (key_delay<300) key_delay+=50;
				printf("             �� �� %3dms ��",key_delay);
				break;
				   }
			}
			Sleep(200);
		}
	}
}

void menu4()	//����
{
	system("cls");
	printf("\n\n\n\n");
	setcolor(15,0);
	printf("            ***  ��  ��  ***\n\n\n");
	setcolor(7,0);
	printf(" < �� �� �� > ������Ű� 10107 ������\n\n");
	printf(" < ���߱Ⱓ > 2013. 8. 22. ~ 9. 21.  \n\n");
	printf(" < ����ȯ�� > Visual Studio 2012 Pro \n\n");
	printf(" < ��    �� > ������ ����zz      \n\n\n");
	printf("����������������������������������������\n");
	printf(" ���͸� �����ø� info.hwp�� ����˴ϴ�.\n");
	printf("    �޴��� �����÷��� ESC�� ��������.");
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
	printf("        ������������������������\n");
	printf("        �� ��̾��� ���� �̷� ��\n");
	printf("        ������������������������\n\n");
	printf("            ***  ��  ��  ***\n\n");
	printf("             �� �����ϱ� ��\n\n");
	setcolor(7,0);
	printf("                ���ӹ��   \n\n");
	printf("                  �ɼ�     \n\n");
	printf("                  ����     \n\n");
	printf("                  ����     ");
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
			case 2: printf("                ���ӹ��   "); break;
			case 3: printf("                  �ɼ�     "); break;
			case 4: printf("                  ����     "); break; 
			case 5: printf("                  ����     "); break;
			}
			select--;
			setcolor(15,0);
			gotoxy(0,select*2+8);
			switch (select){
			case 1: printf("             �� �����ϱ� ��"); break;
			case 2: printf("             �� ���ӹ�� ��"); break;
			case 3: printf("             ��   �ɼ�   ��"); break;
			case 4: printf("             ��   ����   ��"); break;
			}
			setcolor(7,0);
			Sleep(150);
		}
		else if (GetAsyncKeyState(VK_DOWN)&&select!=5){
			gotoxy(0,select*2+8);
			switch (select){
			case 1: printf("                �����ϱ�   "); break;
			case 2: printf("                ���ӹ��   "); break;
			case 3: printf("                  �ɼ�     "); break;
			case 4: printf("                  ����     "); break;
			}
			select++;
			setcolor(15,0);
			gotoxy(0,select*2+8);
			switch (select){
			case 2: printf("             �� ���ӹ�� ��"); break;
			case 3: printf("             ��   �ɼ�   ��"); break;
			case 4: printf("             ��   ����   ��"); break;
			case 5: printf("             ��   ����   ��"); break;
			}
			setcolor(7,0);
			Sleep(150);
		}
	}
}

void main()
{
	CursorView(HIDDEN);
	SetConsoleTitle(TEXT("��̾��� ���� �̷� v1.2"));
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