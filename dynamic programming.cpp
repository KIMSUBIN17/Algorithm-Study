#include <stdio.h> 

int d[1001];  //결과 담을 수 있는 배열 

int dp(int x){
	if(x == 1) return 1;
	if(x == 2) return 3;  

	if(d[x] != 0) return d[x];  
	return d[x] = ( dp(x - 1) + 2 * dp(x - 2)) % 10007; //나머지값출력(값이 너무 커지지않게) 
	 
}

int main(void){
	int x;
	scanf("%d", &x);
	printf("%d",dp(x));
} 
