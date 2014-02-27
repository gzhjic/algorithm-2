#include <stdio.h>
#include <math.h>

/*�˻ʺ���������8*8�������Ϸ���8ö�ʺ�ʹ��������ÿ��������������������б������������б���ֻ��һö�ʺ�*/

const int N = 8; //��������
int a[N] = {0}; //��ʾ���̣���a[2]=2,���ʾ�ڵ�3�е�2�з�һ���ʺ���Ϊͬһ�в��ܷ������ʺ�����ֻ��Ҫ1ά����Ϳ��Ա�ʾһ�����̡�

int num = 0;//��ĸ���

//����б����û���лʴ��ڣ��򷵻�true;���򷵻�false;
bool IsValid(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[n] || (abs(a[i] - a[n]) == n - i))
		{
			return false;
		}
	}
	return true;
}

//��ӡ�����н�
void Print()
{
	printf("��%d�ֽ⣺\n",++num);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i] == j)
			{
				printf("%d", i);
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}

	printf("-----------------\n");
}

void Put(int n)
{
	if (n == N)
	{
		Print();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		a[n] = i;
		if (IsValid(n))
		{
			Put(n + 1);
		}
	}
}

int main()
{
	Put(0);
	return 0;
}