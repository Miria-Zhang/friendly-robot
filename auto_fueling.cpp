#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int num_full;//the numbers of filling cars
int min_dis;//the minimum moving distance
int fueling_type_flag;//indicate the fueling type which the robot carry now
int v_fueling;//indicate the v of the fueling remain
int main(void)
{
	freopen("sample_input.txt","r",stdin);


	int T,Test_case;
	int i,j,k;
	scanf("%d",&T);//read the number of the test_case
	for(Test_case = 1;Test_case <= T;Test_case++)
	{ 