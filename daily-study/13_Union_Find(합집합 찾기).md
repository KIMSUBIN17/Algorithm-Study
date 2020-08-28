## 알고리즘 공부 내용 정리

### 6. Union-Find(합집합 찾기)

Union-Find는 대표적인 그래프 알고리즘이다. '**합집합 찾기**'라는 의미의 알고리즘으로 '**서로소 집합**'알고리즘이라고도 부른다.(서로 같은 집합이 아닌 것을 찾는 것) '여러 개의 노드가 존재할때 두 개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별'하는 알고리즘이다. 

노드들이 모두 서로 연결되지 않고 각자 자기만을 집합의 원소로 가지고 있을 때 '모든 값이 자기 자신을 가리키도록' 만든다. 부모 노드 번호는 자신이 어떤 부모에 포함되어 있는지를 의미한다.

1과 2가 연결되면, 2의 부모자리에 1이 들어간다. 이렇게 부모가 합쳐질때는 일반적으로 더 작은 값 쪽으로 합친다. 이 과정을 합침(Union)이라고 한다. 2와 3도 연결되었다면 어떻게 표현할 수 있을 지 생각해보면 3의 부모를 찾기위해서 3이 가리키고 있는 2를 찾고 2가 가리키는 부모가 1을 가리키고 있으므로 결과적으로 3의 부모가 1이 된다는 사실을 파악할 수 있다. 이때 재귀 함수가 사용된다.' 두개의 노드의 부모 노드를 확인하여 현재 같은 집합에 속하는지 확인하는 알고리즘'이다. 이 Union-Find 알고리즘을 응용한 크루스칼 알고리즘(Kruskal Algorithm)이 있다.

  소스코드로 확인해보면

```c
#include <stdio.h>

//특정한 노드의 부모 찾음 
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;  //x값이 해당 부모의 값과 같으면 x반환(재귀함수의 종료조건)	
	//다르면 실제부모 찾기위해 재귀 수행 
	return parent[x] = getParent(parent, parent[x]);
	
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a ; //더 작은 쪽으로 부모 합쳐줌
	else parent[a] = b; 
} 

// 같은 부모 노드 가지는지 확인 
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if( a ==b ) return 1;
	else return 0;
}


int main(void) {
	int parent[11];
	for(int i = 1; i <= 10; i++) {
		parent[i] = i;   //자기자신을 부모로 가리키도록함(전부 개별적) 
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);  //1과 5 연결 
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
}



```

![image-20200828165935344](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200828165935344.png)





*참고링크 https://blog.naver.com/ndb796/221242106787*