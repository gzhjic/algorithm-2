#include <stdio.h>
#include <stdlib.h>
/*
���ȫ����
���磬���������{a,b,c},��ô���������Ԫ�ص�����������{(a,b,c),(a,c,b),(b,a,c),(b,c,a),(c,a,b),(c,b,a)}����Ȼ������n��Ԫ�ع���n!�ֲ�ͬ������.
��������������ļ��㷨�������������У�������(a,b,c)�����������������������ɣ�

��1����a��ͷ�������(b,c)������
  
��2����b��ͷ�������(a,c)������
	
��3����c��ͷ�������(a,b)������

����Ȼ��һ�ֵݹ��˼·���������ǵõ������µ�ʵ�֣�
*/

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void Permutation(char* a,int k,int m)
{
	int i,j;
	if(k == m)
	{
		for(i=0;i<=m;i++)
		{
			printf("%c", a[i]);
		}
		printf("\n");
	}
	else
	{
		for(j=k;j<=m;j++)
		{
			swap(a[j],a[k]);
			Permutation(a,k+1,m);
			swap(a[j],a[k]);
		}
	}
}
int main(void)
{
	char a[] = "abc";
	printf("ȫ���н��Ϊ��\n");
	Permutation(a,0,2);
	system("pause");
	return 0;
}