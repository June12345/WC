#include<stdio.h>
#include<string.h>
#include <conio.h>
#define M 1000
#define MAX 256

//读取文件字符数
int GetChNum(char *strFilePath)
{
	int nNum = 0;
	FILE* fp = NULL;
	
    fp = fopen(strFilePath, "r");//打开文件
    if( fp == NULL )
    {
        return 0;
    }
    
	//读取文件信息
	while(!feof(fp))
	{
		fgetc(fp);
		nNum++;
    }
	
	fclose(fp);
	
	return nNum;
}

//读取单词数目
int GetWordNum(char *strFilePath)
{
	int nTotal = 0;
	int nStart = 0;
	int nEnd = 0;
	char szBuf[M] = { 0 };
	FILE* fp = NULL; //读入文件

    fp = fopen(strFilePath, "r");//打开文件

    if( fp == NULL )
    {
        return 0;
    }
    
    //读取文件信息
    while ( fgets(szBuf, M, fp) )
    {
		nStart = 0;
		nEnd = 0;
		while ( nStart < strlen(szBuf) )
		{
			//大写字母转换为小写字母
			if ( szBuf[nStart] >= 'A' &&  szBuf[nStart] <= 'Z' )
			{
				szBuf[nStart] += 32;
			}
			else if ( szBuf[nStart] < 'a' ||  szBuf[nStart] > 'z' )
			{
				szBuf[nStart] = ' ';
			}

			//取每个单词
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

//读取文件行数 
int GetLineNum(char *strFilePath)
{
	int nTotalLine = 0;
	FILE* fp = NULL; //读入文件
	char szBuf[M] = { 0 };
	
    fp = fopen(strFilePath, "r");//打开文件
	
    if( fp == NULL )
    {
        return 0;
    }
    
    //读取文件信息
    while ( fgets(szBuf, M, fp) )
    {
		nTotalLine++;
    }
	
	fclose(fp);
	
	return nTotalLine;
}

int main(int argc,char *argv[])
{
// 	wc.exe -c file.c     //返回文件 file.c 的字符数
// 	wc.exe -w file.c    //返回文件 file.c 的词的数目  
// 	wc.exe -l file.c      //返回文件 file.c 的行数

	char strExe[MAX] = { 0 };
	char strCmd[MAX] = { 0 };
	char strFilePath[MAX] = { 0 };
	int nNum = 0;
	int iSel = 0;
	char chCmd;

	if( argc != 3 )
	{
		printf("命令参数有误 \n");
		getch();
		return 0;
	}

	strcpy(strExe, argv[0]);
	strcpy(strCmd, argv[1]);
	strcpy(strFilePath, argv[2]);

	chCmd = strCmd[1];

	switch(chCmd)
	{
	//字符数
	case 'c': 
		nNum = GetChNum(strFilePath);
		printf("文件的字符数为：%d \n", nNum);
		break;

	//单词数
	case 'w':
		nNum = GetWordNum(strFilePath);
		printf("文件的单词数为：%d \n", nNum);
		break;

	//行数
	case 'l':
		nNum = GetLineNum(strFilePath);
		printf("文件的行数为：%d \n", nNum);
		break;

	default:
		printf("命令参数有误% \n");
		return 0;
		break;
	}

	getch();

}
