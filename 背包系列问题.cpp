/*������һϵ������*/

//1������װ������  ̰�� ����n �����⣬�� i�����������Ϊw��ѡ�񾡿��ܶ������,ʹ�������������� c
//��Ŀ˵��ѡ�񾡿��ܶ�����壬��ô��С������ �Ȱ�С��ѡ�� 
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
	int ans = 0;//��¼���� 
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

//���ֱ������� ̰�� 
/*��  n�����壬�� i������ĵ�����Ϊ w ����ֵΪ  v����������������C ����������ܼ�ֵ��ߣ�
ÿһ�����嶼����ֻȡ��һ���֣���ֵ����������������*/

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
	double ans = 0;//��¼�ܼ�ֵ 
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

//��Ʒ���޵ı�������(��ȫ����)
/*��n����Ʒ��ÿ�־������޶������ i ����Ʒ�����Ϊ v������Ϊw�� ѡһЩ
��Ʒװ������Ϊc �ı����У�ʹ�ñ�������Ʒ�������������c��ǰ��������������*/
//�ٴο�������ʱ��Ͳ�̫����   ������Ӳ������
//��Ҫ��Ӳ�����⿴һ�� �е��������....���� 
#include <stdio.h>
#define max(a, b) a>b?a:b
int main(){
	int n, w[100], v[100], c, dp[100] = {0};//dp[i]��ʾ����Ϊiʱ���������� 
	scanf("%d%d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d%d", &w[i], &v[i]);
		for(int j=1; j<=c; j++){
			if(j>=v[i]) dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
 		} 
	}
	return 0;
} 

//ͻȻ�о��Լ�����ȫ������0 1�����е��Ū������.....
//���ö࿴�� ����. 


// 0 1 ��������   --> �� �� ���� 
/*
��n����Ʒ��ÿ��ֻ�� 1 ������i����Ʒ�����Ϊv ������Ϊ w ,ѡһЩ��Ʒװ��һ������
Ϊc�ı����У�ʹ�ö������Ʒ�������������c��ǰ�������������� 
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
			//dp[i-1]��ԭ��
			/*���ڵ�i����Ʒ�����Ҫ�ŵĻ�����Ҫ������Ӧ��w[i]
			  ��ô��һ�� i-1 �о�Ҫ��ȥ��Ӧ��v[i]*/ 
 		}
	}
	printf("%d", dp[n-1][c]);
	return 0;
}
