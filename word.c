#include<stdio.h>
#include<string.h>
#include <conio.h>
#define M 1000
#define MAX 256

//��ȡ�ļ��ַ���
int GetChNum(char *strFilePath)
{
	int nNum = 0;
	FILE* fp = NULL;
	
    fp = fopen(strFilePath, "r");//���ļ�
    if( fp == NULL )
    {
        return 0;
    }
    
	//��ȡ�ļ���Ϣ
	while(!feof(fp))
	{
		fgetc(fp);
		nNum++;
    }
	
	fclose(fp);
	
	return nNum;
}

//��ȡ������Ŀ
int GetWordNum(char *strFilePath)
{
	int nTotal = 0;
	int nStart = 0;
	int nEnd = 0;
	char szBuf[M] = { 0 };
	FILE* fp = NULL; //�����ļ�

    fp = fopen(strFilePath, "r");//���ļ�

    if( fp == NULL )
    {
        return 0;
    }
    
    //��ȡ�ļ���Ϣ
    while ( fgets(szBuf, M, fp) )
    {
		nStart = 0;
		nEnd = 0;
		while ( nStart < strlen(szBuf) )
		{
			//��д��ĸת��ΪСд��ĸ
			if ( szBuf[nStart] >= 'A' &&  szBuf[nStart] <= 'Z' )
			{
				szBuf[nStart] += 32;
			}
			else if ( szBuf[nStart] < 'a' ||  szBuf[nStart] > 'z' )
			{
				szBuf[nStart] = ' ';
			}

			//ȡÿ������
			if ( (szBuf[nStart] >= 'a' &&  szBuf[nStart] <= 'z') || (szBuf[nStart] >= '0' &&  szBuf[nStart] <= '9'))
			{
				nEnd = nStart + 1;
				while ( szBuf[nEnd] >= 'a' &&  szBuf[nEnd] <= 'z' )
				{
					nEnd++;
				}
					
				nTotal++;

				nStart = nEnd;
			}

			nStart++;
		}
    }

	fclose(fp);

	return nTotal;
}

//��ȡ�ļ����� 
int GetLineNum(char *strFilePath)
{
	int nTotalLine = 0;
	FILE* fp = NULL; //�����ļ�
	char szBuf[M] = { 0 };
	
    fp = fopen(strFilePath, "r");//���ļ�
	
    if( fp == NULL )
    {
        return 0;
    }
    
    //��ȡ�ļ���Ϣ
    while ( fgets(szBuf, M, fp) )
    {
		nTotalLine++;
    }
	
	fclose(fp);
	
	return nTotalLine;
}

int main(int argc,char *argv[])
{
// 	wc.exe -c file.c     //�����ļ� file.c ���ַ���
// 	wc.exe -w file.c    //�����ļ� file.c �Ĵʵ���Ŀ  
// 	wc.exe -l file.c      //�����ļ� file.c ������

	char strExe[MAX] = { 0 };
	char strCmd[MAX] = { 0 };
	char strFilePath[MAX] = { 0 };
	int nNum = 0;
	int iSel = 0;
	char chCmd;

	if( argc != 3 )
	{
		printf("����������� \n");
		getch();
		return 0;
	}

	strcpy(strExe, argv[0]);
	strcpy(strCmd, argv[1]);
	strcpy(strFilePath, argv[2]);

	chCmd = strCmd[1];

	switch(chCmd)
	{
	//�ַ���
	case 'c': 
		nNum = GetChNum(strFilePath);
		printf("�ļ����ַ���Ϊ��%d \n", nNum);
		break;

	//������
	case 'w':
		nNum = GetWordNum(strFilePath);
		printf("�ļ��ĵ�����Ϊ��%d \n", nNum);
		break;

	//����
	case 'l':
		nNum = GetLineNum(strFilePath);
		printf("�ļ�������Ϊ��%d \n", nNum);
		break;

	default:
		printf("�����������% \n");
		return 0;
		break;
	}

	getch();

}
