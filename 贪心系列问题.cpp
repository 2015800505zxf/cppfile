//ѡ���ཻ����
/*
��������n��������(a,b), ѡ����������䣬ʹ����Щ��������֮��û�й����� 
*/ 
//�ǲ�����ǰ�����ʱ��Ҫ����һЩ ���ڿ������԰� 

//ֻ�� y ��Ϊ�����׼ ����x  ����yС�ľ�����ǰ��  ��������ѡ���������� 
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
		if(p[i].x>=temp){//�ǿ����õ��ڷ��ŵģ���Ϊ�¿����� 
			ans++;
			temp = p[i].y;
		}
	}
	printf("%d", ans); 
	return 0;
}

//����ѡ������
/*
��������n��������(a,b), ȡ�����ٵĵ㣬ʹ��ʹ��ÿ�����䶼������һ����
(��ͬ�����ں��ĵ������ͬһ��)
*/ 
//��������� С��������ʱ������Ҳһ�����㣬�����ȿ�С����
//�ٴο������ ���Ǿ��ú�����  �������� y��С������ y��ͬʱ x�Ӵ�С(�������ܱ�֤
//�ȿ�С����) 
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

//���串������
/*
��������n��������(a,b)��ѡ�����ٵ����串��һ��ָ���߶�(s, t) 
*/ 
//����ѡȡ������ 
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
	//������Ǵ� 
	if(p[0].x>s) count = 0;
	else{
		int i = 0;
		//��ѽ ����д�� ���м仹������м�ȱ��һС�λ�Ҫ�жϡ� 
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









 
