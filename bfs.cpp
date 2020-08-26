#include <iostream>
#include <queue>
#include <vector>  //������ ����

using namespace std;

int number = 7;
int c[7];  //checked�� ����->�湮ó���� ���� �迭 
vector<int> a[8];  //7���� 1��ŭ ������ ���Ͱ� �� �� �ִ� �迭(�� ����� �ε����� 1���� ó���ǰ� �ϱ����ؼ�_1~7����)

void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()){
		int x = q.front(); //���� �ϳ������� ����x�� �����
		q.pop(); 
		printf("%d ", x);
		
		for(int i = 0; i < a[x].size();i++) {
			int y = a[x][i]; //ť���� ���� ���� ������ ��带 �湮 
			if(!c[y]){  //�湮���� �ʾҴٸ� ť�� ����ְ� �湮ó�� 
				q.push(y);
				c[y] = true;
			}
		} 
	}
} 

int main(void){
	//1�� 2�� ���� 
	a[1].push_back(2);  //1�� 2,3�� ���� 
	a[2].push_back(1); //1�� 2�� ���� = 2�� 1�� ����
	//1�� 3�� ���� 
	a[1].push_back(3);  //�ϳ��� �������� �ΰ��� ��ɾ� 
	a[3].push_back(1);  
	//2�� 3�� ���� 
	a[2].push_back(3); 
	a[3].push_back(2); 
	//2�� 4�� ���� 
	a[2].push_back(4); 
	a[4].push_back(2);
	//2�� 5�� ���� 
	a[2].push_back(5);
	a[5].push_back(2);
	//3�� 6�� ���� 
	a[3].push_back(6);
	a[6].push_back(3);
	//3�� 7�� ���� 
	a[3].push_back(7);
	a[7].push_back(3);
	//4�� 5�� ���� 
	a[4].push_back(5);
	a[5].push_back(4);
	//6�� 7�� ���� 
	a[6].push_back(7);
	a[7].push_back(6);
	
	//�������� 1�� BFS�� ���� 
	bfs(1);   
	
	return 0; 
	
	
	
	
}
