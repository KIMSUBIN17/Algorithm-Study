## 알고리즘 공부 내용 정리

### 3. 이진 트리의 구현과 순회(Traversal)방식

#### 1. 이진트리와 전위/중위/후위 순회

기본적으로 가장 많이 사용되는 비선형 자료구조는 **이진트리(Binary Tree)**이다. 이진트리는 자료구조를 활용한 것으로 **데이터의 탐색 속도 증진을 위해 사용되는 구조**이다. 포인터를 통해 특정 루트에서 자식 노드로 접근할 수 있다. 하나의 노드는 왼쪽 자식과 오른쪽 자식을 가진다. 

힙 정렬을 구현할 때는 '완전 이진 트리'가 사용되어서 배열로 표현했지만 완전 이진 트리가 아닌 이진 트리는 배열로 표현하기 어렵기 때문에 포인터를 사용한다. 

이진 트리에서 데이터를 탐색하는 3가지 방법이 있다.

1. 전위 순회(preorder Traversal)
2. 중위 순회(Inorder Traversal)
3. 후위 순회(Postorder Traversal)



1. 전위 순회(preorder Traversal) 
   1. **먼저 자기 자신을 처리한다.**
   2. 왼쪽 자식을 방문한다.
   3. 오른쪽 자식을 방문한다.
2. 중위 순회(Inorder Traversal)
   1. 왼쪽 자식을 방문한다.
   2. **먼저 자기 자신을 처리한다.**
   3. 오른쪽 자식을 방문한다.

3. 후위 순회(Postorder Traversal)
   1. 왼쪽 자식을 방문한다.
   2. 오른쪽 자식을 방문한다.
   3. **먼저 자기 자신을 처리한다.**

![image-20200827105902989](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200827105902989.png)

위 예제로 순회를 진행해보면 아래와 같다.

전위 순회 : 1 - 2 - 4 - 8 - 9 - 5 - 10 - 11 - 3 - 6 - 12 - 13 - 7 - 14 - 15

중위 순회 : 8 - 4 - 9 - 2 - 10 - 5 - 11 - 1 - 12 - 6 - 13 - 3 - 14 - 7 - 15

후위 순회 : 8 - 9 - 4 - 10 - 11 - 5 - 2 - 12 - 13 - 6 - 14 - 15 - 7 - 3 - 1

소스코드로 확인해보면

1. 전위 순회

```c++
#include <iostream>

using namespace std;

int number = 15;

//하나의 노드 정보를 선언
typedef struct node *treePointer;
typedef struct node{
	int data;
	treePointer leftChild, rightChild;
} node; 
	
//전위 순회를 구현
void preorder(treePointer ptr) {
	if(ptr) {  //데이터를 가지고 있는 경우 데이터 먼저 출력 
		cout << ptr ->data << ' '; 
		preorder(ptr->leftChild);
				preorder(ptr->rightChild);
	}
} 

//중위 순회를 구현
void inorder(treePointer ptr) {
	if(ptr) {   
		inorder(ptr->leftChild);
		cout << ptr ->data << ' '; 
		inorder(ptr->rightChild);
	}
} 

//후위 순회를 구현
void postorder(treePointer ptr) {
	if(ptr) {   
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr ->data << ' ';
	}
} 


int main(void){
	node nodes[number + 1];  //15개의 노드가 담길 수 있는 데이터배열 
	for(int i = 0; i <= number; i++){
		nodes[i].data = i;  //데이터는 1~15까지 자기자신이 들어갈 수 있도록 
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	//노드들 연결 
	for(int i = 0; i <= number; i++){
		if(i % 2 == 0)  //짝수는 왼쪽 
			nodes[i / 2].leftChild = &nodes[i];
		else   //홀수는 오른쪽 
			nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	return 0;
}



```

![image-20200827111258364](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200827111258364.png)

2. 중위 순회

```c++
#include <iostream>

using namespace std;

int number = 15;

//하나의 노드 정보를 선언
typedef struct node *treePointer;
typedef struct node{
	int data;
	treePointer leftChild, rightChild;
} node; 
	
//전위 순회를 구현
void preorder(treePointer ptr) {
	if(ptr) {  //데이터를 가지고 있는 경우 데이터 먼저 출력 
		cout << ptr ->data << ' '; 
		preorder(ptr->leftChild);
				preorder(ptr->rightChild);
	}
} 

//중위 순회를 구현
void inorder(treePointer ptr) {
	if(ptr) {   
		inorder(ptr->leftChild);
		cout << ptr ->data << ' '; 
		inorder(ptr->rightChild);
	}
} 

//후위 순회를 구현
void postorder(treePointer ptr) {
	if(ptr) {   
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr ->data << ' ';
	}
} 


int main(void){
	node nodes[number + 1];  //15개의 노드가 담길 수 있는 데이터배열 
	for(int i = 0; i <= number; i++){
		nodes[i].data = i;  //데이터는 1~15까지 자기자신이 들어갈 수 있도록 
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	//노드들 연결 
	for(int i = 0; i <= number; i++){
		if(i % 2 == 0)  //짝수는 왼쪽 
			nodes[i / 2].leftChild = &nodes[i];
		else   //홀수는 오른쪽 
			nodes[i / 2].rightChild = &nodes[i];
	}
	inorder(&nodes[1]);
	return 0;
}

```

![image-20200827111330700](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200827111330700.png)

3. 후위 순회

   ```c++
   #include <iostream>
   
   using namespace std;
   
   int number = 15;
   
   //하나의 노드 정보를 선언
   typedef struct node *treePointer;
   typedef struct node{
   	int data;
   	treePointer leftChild, rightChild;
   } node; 
   	
   //전위 순회를 구현
   void preorder(treePointer ptr) {
   	if(ptr) {  //데이터를 가지고 있는 경우 데이터 먼저 출력 
   		cout << ptr ->data << ' '; 
   		preorder(ptr->leftChild);
   				preorder(ptr->rightChild);
   	}
   } 
   
   //중위 순회를 구현
   void inorder(treePointer ptr) {
   	if(ptr) {   
   		inorder(ptr->leftChild);
   		cout << ptr ->data << ' '; 
   		inorder(ptr->rightChild);
   	}
   } 
   
   //후위 순회를 구현
   void postorder(treePointer ptr) {
   	if(ptr) {   
   		postorder(ptr->leftChild);
   		postorder(ptr->rightChild);
   		cout << ptr ->data << ' ';
   	}
   } 
   
   
   int main(void){
   	node nodes[number + 1];  //15개의 노드가 담길 수 있는 데이터배열 
   	for(int i = 0; i <= number; i++){
   		nodes[i].data = i;  //데이터는 1~15까지 자기자신이 들어갈 수 있도록 
   		nodes[i].leftChild = NULL;
   		nodes[i].rightChild = NULL;
   	}
   	//노드들 연결 
   	for(int i = 0; i <= number; i++){
   		if(i % 2 == 0)  //짝수는 왼쪽 
   			nodes[i / 2].leftChild = &nodes[i];
   		else   //홀수는 오른쪽 
   			nodes[i / 2].rightChild = &nodes[i];
   	}
   	postorder(&nodes[1]);
   	return 0;
   }
   
   ```

   ![image-20200827111350546](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200827111350546.png)



*참고링크 :https://blog.naver.com/ndb796/221233560789*
