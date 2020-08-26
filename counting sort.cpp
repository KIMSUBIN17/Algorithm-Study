#include<stdio.h>

int main(void){
	int temp;
	int count[6];
	int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
					 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
					 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
					 
	for(int i = 0; i <=5; i++){
		count[i] = 0;  //각 배열을 0으로 초기화 
	} 
	//현재 만나는 데이터의 인덱스값을 1 더해줌 
	for(int i = 0; i < 30; i++){
		count[array[i]]++; 
	//배열의 인덱스는 0에서 시작하기때문
		
	}
	for(int i = 0; i <= 5; i++){
		if(count[i] !=0){   //데이터가  0이 아닌이상 데이터갯수만큼 출력 
			for(int j = 0; j < count[i]; j++) 
			printf("%d", i);
		}
	}
					 
					 
	return 0;
	
}
