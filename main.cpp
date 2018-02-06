#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LEN 21
int N,C,Test_case;
char map[LEN][LEN];
int min_lstDis;//the minimum distance
int t,nt;//the turn of the queue to be visited
int length[2];//the length of the 2 queue
bool is_find = false;
char standard = 1;
int offset[4][2] = {{1,0},{0,1},{-1,0},{0.-1}};
typedef struct node{
	int x;
	int y;
	char value;
	int source;
}Node;

Node queue[2][LEN*LEN];//queue struct to store the node to be visited

void check(Node center)
{
	int x,y;
	Node neighbor;
	for(int i = 0;i < 4;i++)
	{
		x = center.x+offset[i][0];
		y = center.y+offset[i][1];
		if(map[x][y]!=standard&&map[x][y]!=0)
		{
			char temp = pow(2,center.source-1);
			if(map[x][y]&)	//if map[x][y]的第source位不为1
				//将第source位置1
				//检查map[x][y]==standard?
				//若是，is_find = true；return；
				//否则
				neighbor.source = center.source;
				neighbor.value = map[x][y];
				neighbor.x = x;
				neighbor.y = y;
				queue[nt][length[nt]] = neighbor;
				length[nt]++;
		}
	}
	
}
int main(void)
{
	freopen("sample_input.txt","r",stdin);


	int T,Test_case;
	int i,j,k;
	scanf("%d",&T);//read the number of the test_case
	for(Test_case = 1;Test_case <= T;Test_case++)
	{
		scanf("%d",&N);//read the scale of the map
		scanf("%d",&C);
		min_lstDis = 0;
		t = nt = 0;
		length[t] = C;

		//push the location information to the 1st queue
		for(i=0;i< C;i++)
		{
			scanf("%d",&queue[t][i].y);
			scanf("%d",&queue[t][i].x);
			queue[t][i].source = i;
			queue[t][i].value = 1;
			standard +=2;
		}

		for(i=0;i<N;i++)
		{
			for(j = 0;j< N;j++)
			{
				scanf("%c",&map[i][j]);
				//printf("%c ",map[i][j]);
			}
				//printf("\n");
		}

		while(length[t]!=0&&is_find == false)
		{
			min_lstDis++;
			nt = min_lstDis%2;
			for(i=0;i<length[t];i++)
			{
				if(is_find==false)
					break;
				check(queue[t][i]);
				//check(queue[t][i].x,queue[t][i].y+1);
				//check(queue[t][i].x-1,queue[t][i].y);
				//check(queue[t][i].x,queue[t][i].y-1);

				//clear the value of the ith node
				queue[t][i].x = 0;
				queue[t][i].y = 0;
				queue[t][i].source = 0;
				queue[t][i].value = 0;
			}
		    length[t] = 0;
			t = nt;

		}


	}
	
	return 0;
}