#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	unsigned timer=3;
		char op;
		while(1){
			printf("等待用户命令：\n");
				printf("开始游戏 请按s\n");
				printf("退出游戏 请按q\n");

				char input;
				scanf("%c",&input);
				if (input=='s')
					break;
					if (input=='q')
						exit(0);
		}
		system("cls");
			printf("开始游戏lsalslsl\n");
			return 0;
}
