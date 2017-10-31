/*背包的一系列问题*/

//1、最优装载问题  贪心 给吃n 个问题，第 i个物体的重量为w，选择尽可能多的物体,使得总重量不超过 c
//题目说是选择尽可能多的物体，那么从小到大排 先把小的选了 
#include<stdio.h>
#include <algorithm>
using namespace std; 
int main(){
	int n, w[100], C;
	scanf("%d%d", &n, &C);
	for(int i=0; i<n; i++){
		scanf("%d", &w[i]);
	}
	sort(w, w+n);
	int ans = 0;//记录个数 
	for(int i=0; i<n; i++){
		if(C >= w[i]){
			ans++;
			C -= w[i];
		} 
		else break;
	}
	printf("%d\n", ans);
	return 0;
} 

//部分背包问题 贪心 
/*有  n个物体，第 i个物体的的重量为 w ，价值为  v，在总重量不超过C 的情况下让总价值最高，
每一个物体都可以只取走一部分，价值个重量按比例计算*/

#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct{
	double w, v, k;
}P;
bool com(P a, P b){
	return a.k > b.k;
}
int main(){
	int n, C;
	P p[100];
	scanf("%d%d", &n, &C);
	for(int i=0; i<n; i++){
		scanf("%lf%lf", &p[i].w, &p[i].v);
		p[i].k = p[i].v / p[i].w;
	}
	sort(p, p+n, com);
	double ans = 0;//记录总价值 
	for(int i=0; i<n; i++){
		if(!C) break;
		if(C >= p[i].w){
			ans += p[i].v;
			C -= p[i].w;
		}
		else{
			ans += p[i].k * C;
			C = 0;
		} 
	}
	printf("%lf", ans);
	return 0;
} 

//物品无限的背包问题(完全背包)
/*有n种物品，每种均有无限多个，第 i 种物品的体积为 v，重量为w， 选一些
物品装到容量为c 的背包中，使得背包内物品在总体积不超过c的前提下重量尽量大*/
//再次看这个题的时候就不太会了   类似于硬币问题
//还要把硬币问题看一下 有点儿不会了....加油 
#include <stdio.h>
#define max(a, b) a>b?a:b
int main(){
	int n, w[100], v[100], c, dp[100] = {0};//dp[i]表示容量为i时，最大的重量 
	scanf("%d%d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d%d", &w[i], &v[i]);
		for(int j=1; j<=c; j++){
			if(j>=v[i]) dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
 		} 
	}
	return 0;
} 

//突然感觉自己把完全背包和0 1背包有点儿弄混淆了.....
//还得多看看 加油. 


// 0 1 背包问题   --> 放 与 不放 
/*
有n种物品，每种只有 1 个，第i种物品的体积为v ，重量为 w ,选一些物品装到一个容量
为c的背包中，使得额背包内物品在总体积不超过c的前提下重量尽量大。 
*/ 
#include <stdio.h>
int main(){
	int n, w[100], v[100], c, dp[100][100];
	scanf("%d%d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d%d", &w[i], &v[i]);
		for(int j=0; j<=c; j++){
			dp[i][j] = i==0?0:dp[i-1][j];
			if(j>=v[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i]);
			//dp[i-1]的原因：
			/*对于第i个物品，如果要放的话，就要加上相应的w[i]
			  那么上一步 i-1 中就要减去相应的v[i]*/ 
 		}
	}
	printf("%d", dp[n-1][c]);
	return 0;
}
