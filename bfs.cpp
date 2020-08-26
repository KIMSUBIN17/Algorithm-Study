#include <iostream>
#include <queue>
#include <vector>  //데이터 저장

using namespace std;

int number = 7;
int c[7];  //checked의 약자->방문처리를 위한 배열 
vector<int> a[8];  //7에서 1만큼 더해준 벡터가 들어갈 수 있는 배열(각 노드의 인덱스가 1부터 처리되게 하기위해서_1~7까지)

void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()){
		int x = q.front(); //변수 하나꺼내서 변수x에 담아줌
		q.pop(); 
		printf("%d ", x);
		
		for(int i = 0; i < a[x].size();i++) {
			int y = a[x][i]; //큐에서 꺼낸 노드와 인접한 노드를 방문 
			if(!c[y]){  //방문하지 않았다면 큐에 담아주고 방문처리 
				q.push(y);
				c[y] = true;
			}
		} 
	}
} 

int main(void){
	//1과 2를 연결 
	a[1].push_back(2);  //1은 2,3과 연결 
	a[2].push_back(1); //1이 2과 연결 = 2도 1과 연결
	//1과 3을 연결 
	a[1].push_back(3);  //하나의 간선마다 두개의 명령어 
	a[3].push_back(1);  
	//2와 3을 연결 
	a[2].push_back(3); 
	a[3].push_back(2); 
	//2와 4를 연결 
	a[2].push_back(4); 
	a[4].push_back(2);
	//2와 5를 연결 
	a[2].push_back(5);
	a[5].push_back(2);
	//3과 6을 연결 
	a[3].push_back(6);
	a[6].push_back(3);
	//3과 7을 연결 
	a[3].push_back(7);
	a[7].push_back(3);
	//4와 5를 연결 
	a[4].push_back(5);
	a[5].push_back(4);
	//6과 7을 연결 
	a[6].push_back(7);
	a[7].push_back(6);
	
	//시작점을 1로 BFS를 수행 
	bfs(1);   
	
	return 0; 
	
	
	
	
}
