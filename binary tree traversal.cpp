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



