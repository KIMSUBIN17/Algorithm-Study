#include<stdio.h>

	//i,j - 배열의 원소를 반복적으로 탐색하기위해
	//min : 최소값
	//index:가장작은원소가 위치 
	//temp :특정한 두 숫자를 바꾸기 위해
int main(void){

	int i,j,min,index, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i=0;i<10;i++){
		min = 9999;  //가장 큰 값을 넣기
	//min은 항상 최소값을 선택해야하기때문에 처음에는 큰 값이 필요
		 
		for(j=i;j<10;j++) {
			if(min>array[j]){
				min = array[j];
				//탐색하고 있는 원소가 현재 최솟값보다 작으면
				//탐색하고 있는 현재 원소값으로 최솟값 변경 
				index = j;
			}
		}
		//swaping(가장 앞에 있는 값과 최솟값의 위치 교환) 
		 temp = array[i];
		 array[i] = array[index];
		 array[index] = temp;
	} 
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	
	return 0;
}
