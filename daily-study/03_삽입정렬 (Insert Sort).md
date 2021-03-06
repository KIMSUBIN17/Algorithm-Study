## 알고리즘 공부 내용 정리

### 1. 정렬

#### 3. 삽입 정렬( Insert Sort)

다음 숫자를 오름차순으로 정렬하려면 어떻게 해야할까?

1 10 5 8 7 6 4 3 2 9 

앞선 예시와 같은 예시를 통해 확인해보면 삽입 정렬은 **각 숫자를 적절한 위치에 삽입**하는 방법으로 문제를 해결한다.  

=> **'삽입 정렬'이란?**

**각 숫자를 적절한 위치에 삽입하는 방법**으로 필요할 때만 위치를 바꾸게 된다. 그래서 같은 O(N^2) 시간복잡도 중에서는 가장 빠르고 효율적인 편이다. (앞에 있는 원소들이 이미 정렬이 되어 있다고 가정한다는 특정때문에 선택정렬이나 버블정렬보다 효율적이라고 할 수 있다.)

1 10 5 8 7 6 4 3 2 9 이 상태에서 10, 5, 8, 7 등의 순서대로 한 개씩 그 값을 어느 앞의 어느 자리에 넣어줄지 고민한다. 이렇게 한 개씩 정렬이루어지게된다.

7의 자리까지 정해주고나면 1 5 7 8 10 6 4 3 2 1의 상태가 되는데, 이 상태에서는 6의 앞자리까지 1 5 7 8 10까지의 숫자들은 이미 정렬이 되어있는 상태라고 볼 수 있다. 이처럼 특정원소를 기준으로 (이 설명에서는 숫자 6) 이미 정렬이 된 상태에서는 앞에 있는 숫자들(왼쪽에 있는 숫자들)을 추가적으로 정렬할 필요가 없다. 단순히 특정 위치만 확인해 값을 바꿔주면 되기 때문이다. 당장 내가 왼쪽에 있는 값들보다 크다면 멈추면 된다. (멈춤 포인트를 알고 있음) 



소스코드로 확인해보면

```c
#include<stdio.h>

int main(void){
	int i,j,temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i = 0; i < 9; i++){
		j = i;  //현재 정렬할 원소를 선택해 적절한 위치에 삽입
		while(array[j] > array[j + 1]){
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	for(i = 0; i< 10; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
```



앞서 이야기한 내용을 정리하자면, 삽입 정렬은 기본적으로 '정렬이 되어있다고 가정'을 한다는 점에서 특정한 경우에 따라 빠른 속도를 보인다. 소스코드상에서 반복문이 두 번 들어가 있기 때문에 시간복잡도는 O(N^2) 이다.

10 + 9 + 8 + 7 + ... + 1

=> 10 * (10 + 1) / 2 

=> N* (N + 1) / 2  

=> O(N * N)   

=> O(N^2)



하지만, 2 3 4 5 6 7 8 9 10 1 의 경우에서 오름차순 정렬을 하려고 한다면 어떨까 생각해볼 수 있다.

위의 경우처럼 '거의 정렬된' 상태라면 삽입 정렬이 가장 효율적이다. 숫자들을 보면 10까지는 거의 연산하지않고 빠른 처리가 가능하고 맨 마지막의 1만 앞으로 정렬되면 되기때문이다. 이처럼 삽입 정렬은 필요할 때에 한해서만 삽입을 진행하기 때문에 '데이터가 이미 거의 정렬된 상태에 한해서는 어떤 알고리즘보다도 빠르다는 특징'을 가지고 있다.







*참조링크 : https://blog.naver.com/ndb796/221226806398*