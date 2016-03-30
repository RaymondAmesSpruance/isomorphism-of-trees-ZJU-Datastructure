#include"stdio.h"
#include"stdlib.h"
//首先在一行中给出一个非负整数NNN (≤10\le 10≤10)，即该树的结点数（此时假设结点从0到N−1N-1N−1编号）；
#define MaxSize 10
#define ElementType char
#define Tree int
#define Null -1
struct NodeOfTree 
{
	ElementType Data;
	Tree Left;
	Tree Right;
};
struct NodeOfTree t1[MaxSize];
struct NodeOfTree t2[MaxSize];
Tree BuildTree(struct NodeOfTree T[])
{
	int N = 0;
	scanf("%d",&N);
	Tree Root = -1;
	bool check[MaxSize] = { 0 };
	if (N)
	{
		char cl = NULL;
		char cr = NULL;
		for (int i = 0; i < N; i++)
		{

			scanf("\n%c %c %c", &T[i].Data, &cl,&cr);
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
			{
				T[i].Left = -1;
			}

			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = -1;
			}
		}
		int j = 0;
		for (j = 0; j < N; j++)
		{
			if (check[j] == 0) break;
		}
		Root = j;
	}
	return Root;
}
//bool isomophism(struct NodeOfTree t1[], struct NodeOfTree t2[], int t1root, int t2root)
//不用传结构体数组，这个在调用函数之前已经存在内存中了，而且生存期可以挺过这个函数。
//就像链表也只需要传头指针一样，其他的都存在内存里了，可以靠指针或者某种索引找到。
bool isomophism(int t1root, int t2root)
{

	if ((t1root == -1) && (t2root == -1))
		return true;
	if (((t1root == -1) && (t2root != -1)) || ((t1root != -1) && (t2root == -1)))
		return false;
	if (t1[t1root].Data != t2[t2root].Data)
		return false;
	if ((t1[t1root].Left == -1) && (t1[t1root].Right == -1) && (t2[t2root].Left == -1) && (t2[t2root].Right == -1))
		return true;
	if ((t1[t1root].Left == -1) && (t2[t2root].Left == -1) && (t1[t1root].Right != -1) && (t2[t2root].Right != -1))
		return isomophism(t1[t1root].Right, t2[t2root].Right);
	if ((t1[t1root].Left != -1) && (t2[t2root].Left != -1) && (t1[t1root].Right == -1) && (t2[t2root].Right == -1))
		return isomophism(t1[t1root].Left, t2[t2root].Left);
	if ((t1[t1root].Left == -1) && (t2[t2root].Left != -1) && (t1[t1root].Right != -1) && (t2[t2root].Right == -1))
		return isomophism(t1[t1root].Right, t2[t2root].Left);
	if ((t1[t1root].Left != -1) && (t2[t2root].Left == -1) && (t1[t1root].Right == -1) && (t2[t2root].Right != -1))
		return isomophism(t1[t1root].Left, t2[t2root].Right);
	if ((t1[t1root].Left != -1) && (t2[t2root].Left != -1) && (t1[t1root].Right != -1) && (t2[t2root].Right != -1))
	
	return ( 
					( isomophism(t1[t1root].Left, t2[t2root].Right) && isomophism(t1[t1root].Right, t2[t2root].Left) )
					|| 
					( isomophism(t1[t1root].Left, t2[t2root].Left) && isomophism(t1[t1root].Right, t2[t2root].Right) )
				);
	else return false;
}
int main()
{
	int t1root = -1;
	int t2root = -1;
	bool flag = NULL;
	t1root = BuildTree(t1);
	t2root = BuildTree(t2);
	flag = isomophism(t1root, t2root);
	if (flag == true)
		printf("Yes");
	else
		printf("No");
	//system("pause");
	return 0;
}