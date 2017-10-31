//选择不相交区间
/*
数轴上有n个开区间(a,b), 选择尽量多的区间，使得这些区间两两之间没有公共点 
*/ 
//是不是以前看书的时候要聪明一些 现在看都好迷啊 

//只以 y 作为排序标准 不管x  反正y小的就排在前面  这样才能选出最多的区间 
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct{
	int x, y;
}P;
bool com(P a, P b){
	return a.y < b.y; 
}
int main(){
	int n;
	P p[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p, p+n, com);
	int ans = 1, temp = p[0].y;
	for(int i=1; i<n; i++){
		if(p[i].x>=temp){//是可以用等于符号的，因为事开区间 
			ans++;
			temp = p[i].y;
		}
	}
	printf("%d", ans); 
	return 0;
}

//区间选点问题
/*
数轴上有n个闭区间(a,b), 取尽量少的点，使得使得每个区间都至少有一个点
(不同区间内含的点可以是同一个)
*/ 
//在这里就是 小区间满足时大区间也一定满足，所以先看小区间
//再次看这个书 还是觉得好厉害  排序规则的 y从小到大排 y相同时 x从大到小(这样就能保证
//先看小区间) 
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct{
	int x, y;
}P;
bool com(P a, P b){
	if(a.y<b.y) return true;
	if(a.y==b.y&&a.x>b.x) return true;
	return false; 
}
int main(){
	int n;
	P p[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d",&p[i].x, &p[i].y);
	}
	sort(p, p+n, com);
	int ans = p[0].y;
	int sum = 1;
	for(int i=1; i<n; i++){
		if(ans < p[i].x){
			ans = p[i].y;
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
} 

//区间覆盖问题
/*
数轴上有n个闭区间(a,b)，选择尽量少的区间覆盖一条指定线段(s, t) 
*/ 
//尽量选取大区间 
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct{
	int x, y;
}P;
bool com(P a, P b){
	if(a.x<b.x) return true;
	if(a.x==b.x&&a.y>b.y) return true;
	return false; 
}
int main(){
	int n, s, t;
	P p[100];
	scanf("%d%d%d", &n, &s, &t);
	for(int i=0; i<n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p, p+n, com);
	//我真的是蠢 
	if(p[0].x>s) count = 0;
	else{
		int i = 0;
		//哎呀 不想写了 ，中间还有如果中间缺少一小段还要判断。 
	 	while(i<n){
	 		while(p[i].x <= s){
	 			i++;
			}
			count++;
			s = p[i].y;
			if(p[i].y>=t) break;
		}
	}
	return 0;
}









 
