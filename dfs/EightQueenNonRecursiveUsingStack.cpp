#include <stdio.h>
#include <math.h>
#include <stack>
using namespace std;
/*�˻ʺ���������8*8�������Ϸ���8ö�ʺ�ʹ��������ÿ��������������������б������������б���ֻ��һö�ʺ�*/

const int N = 8; //��������
int a[N] = {0}; //��ʾ���̣���a[2]=2,���ʾ�ڵ�3�е�2�з�һ���ʺ���Ϊͬһ�в��ܷ������ʺ�����ֻ��Ҫ1ά����Ϳ��Ա�ʾһ�����̡�

int num = 0;//��ĸ���

struct Node
{
	int x;
	int y;
};

//����б����û���лʴ��ڣ��򷵻�true;���򷵻�false;
bool IsValid(Node node)
{
	for (int i = 0; i < node.x; i++)
	{
		if (a[i] == node.y || (abs(a[i] - node.y) == node.x - i))
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

void Put()
{
	Node node;
	stack<Node> stack;

	node.x = 0;
	node.y = 0;
	stack.push(node);
	while(stack.size() >= 1)
	{

		node = stack.top();
		while (node.y < N && !IsValid(node))
		{
			node.y++;
			a[node.x] = node.y;
		}

	
		if (node.y == N)
		{
			//����
			stack.pop();
			
			if (stack.size() == 0)
			{
				return;
			}
			node = stack.top();
			node.y++;
			a[node.x] = node.y;
			stack.pop();
			stack.push(node);
			
		}
		else
		{
			if (node.x == N-1)
			{
				//��ӡ���
				Print();
			
				//node = stack.top();
				node.y++;
				a[node.x] = node.y;
				stack.pop();
			    stack.push(node);
			}
			else
			{

				stack.pop();
				stack.push(node);
				
				//������һ��
				node.x++;
				node.y = 0;
				a[node.x] = node.y;
				stack.push(node);
			}

		}

	}

}

int main()
{
	Put();
	return 0;
}