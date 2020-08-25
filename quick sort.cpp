#include<stdio.h>

int number = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};
	
 
void quickSort(int *data, int start, int end){
	if (start >= end) {   //원소가 1개인 경우 그대로 두기  
			return;
	}
		
	int key = start ;  //키는 첫번째 원소
	int i = start + 1;  				
	int j = end;    
	int temp;
		//왼쪽부터 출발한 값이 오른쪽부터 출발한 값보다 작은경우까지만 반복) 
	while(i <= j) {   //엇갈릴 때까지 반복
		while(data[i] <= data[key]) {  //키값보다 큰 값을 만날때까지 i 오른쪽으로 이동 
				i++;
		} 
		
		while(data[j] >= data[key] &&  j > start) {  //키값보다 작은값을 만날때까지 반복 
			j--;
		}
		
		
		if (i > j){			//현재 엇갈린 상태면 키 값과 교체 
		temp = data[j];
		data[j] = data[key];
		data[key] = temp;
		}
  		 
  		else {  //엇갈리지않았다면 큰값과 작은값 교체 
		temp = data[j];
		data[j] = data[i];
		data[i] = temp;
		}
	} 
		
	//키값을 기준으로 왼쪽과 오른쪽에서 다시 퀵 정렬 수행 
	quickSort(data, start,  j - 1);
	quickSort(data, j + 1,  end);
		 
	}
	

int main(void){
	quickSort(data, 0,  number - 1);
	for(int i = 0; i < number ; i++){
		printf("%d ", data[i]);
	}
}
