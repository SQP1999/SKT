#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 35
#pragma warning(disable: 4996)
int str[22][N] = { 0 }, plane = 9, width = 24, speed = 3, density = 30, score = 0, death = 0,time=0,enemybullet=0;
//ȫ�ֱ��������桢�һ���ʼλ�������ȡ��л��ٶȡ��л��ܶȡ��÷֡�����
void show(int a[][N]);//��ӡ����
void movebul(int[][N]);//�ӵ��ƶ�����
void moveplane(int[][N]);//�л��ƶ�����
void moveenemybul(int[][N]);
int main()
{
    int i = 0, j = 0;
    str[21][plane] = 1;
    str[0][5] = 3;
    while (1)
    {
        if (kbhit())
            switch (getch())//���������ƶ����ӵ�
        {
            case 'a':
            case 'A':
                if (plane>0)str[21][plane] = 0, str[21][--plane] = 1;
                break;
            case 'd':
            case 'D':
                if (plane<width - 2)str[21][plane] = 0, str[21][++plane] = 1;
                break;
            case 'w':
            case 'W':
                str[20][plane] = 2; break;
                break;
        }
        if (++j%density == 0)//���������л����ٶ�
        {
            j = 0; srand(time);
            str[0][rand() % width] = 3;
        }
        if (++i%speed == 0)//���Ƶл��ƶ��ٶȣ�������ӵ��ƶ��ٶ�
            moveplane(str);
        movebul(str);
        show(str);
        if (i == 30000)i = 0;//����i Խ��
    }
    system("pause");
    return 0;
}
void show(int a[][N])
{
    system("cls");
    int i, j;
    for (i = 0; i<22; i++)
    {
        a[i][width - 1] = 4;
        for (j = 0; j<width; j++)
        {
            if (a[i][j] == 0)printf(" ");
            if (a[i][j] == 1)printf("\5");//����һ��ķ���
            if (a[i][j] == 2)printf(".");//�ӵ�
            if (a[i][j] == 3)printf("\4"); //����л�����
            if (a[i][j] == 4)printf("|");
            if (i == 0 && j == width - 1)printf("�÷֣�%d", score);//���Ͻ���ʾ�÷�
            if (i == 1 && j == width - 1)printf("������%d", death);
        }
        printf("\n");//Sleep(100);      
    }
    Sleep(80);
}
void movebul(int a[][N])//�ӵ��ƶ�����
{
    int i, j;
    for (i = 0; i<22; i++)
    for (j = 0; j<width; j++)
    {
        if (i == 0 && a[i][j] == 2)
            a[i][j] = 0;
        if (a[i][j] == 2)
        {
            if (a[i - 1][j] == 3)
                score += 10;//,printf("\7")
            a[i][j] = 0, a[i - 1][j] = 2;
        }
    }
}
void moveplane(int a[][N])//�л��ƶ�����
{
    int i, j;
    for (i = 21; i >= 0; i--)//�����һ��������Ϊ�˱���ѵл�ֱ�ӳ�����顣
    for (j = 0; j<width; j++)
    {
        if (i == 21 && a[i][j] == 3)a[i][j] = 0;//���и�ֵ0 ����Խ�硣
        if (a[i][j] == 3)a[i][j] = 0, a[i + 1][j] = 3;
    }
    if (a[20][plane] == 3 && a[21][plane] == 1)//�л����һ�����
        death++;
}
void moveenemybul(int a[][N])//�л��ӵ�����
{
int i,j;
for (i = 21; i >= 0; i++)
    for (j = 0; j<width; j--)
	{
if (i == 21 && a[i][j] == 3)a[i][j] = 0;
        if (a[i][j] == 3)a[i][j] = 0, a[i + 1][j] = 3;
	}
if (a[20][plane] == 3 && a[21][plane] == 1)
        death++;
}