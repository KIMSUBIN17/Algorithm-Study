#include<stdio.h>

	//i,j - �迭�� ���Ҹ� �ݺ������� Ž���ϱ�����
	//min : �ּҰ�
	//index:�����������Ұ� ��ġ 
	//temp :Ư���� �� ���ڸ� �ٲٱ� ����
int main(void){

	int i,j,min,index, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i=0;i<10;i++){
		min = 9999;  //���� ū ���� �ֱ�
	//min�� �׻� �ּҰ��� �����ؾ��ϱ⶧���� ó������ ū ���� �ʿ�
		 
		for(j=i;j<10;j++) {
			if(min>array[j]){
				min = array[j];
				//Ž���ϰ� �ִ� ���Ұ� ���� �ּڰ����� ������
				//Ž���ϰ� �ִ� ���� ���Ұ����� �ּڰ� ���� 
				index = j;
			}
		}
		//swaping(���� �տ� �ִ� ���� �ּڰ��� ��ġ ��ȯ) 
		 temp = array[i];
		 array[i] = array[index];
		 array[index] = temp;
	} 
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	
	return 0;
}
