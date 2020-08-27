#include <iostream>
#include <vector>  

using namespace std;

int number = 7;
int c[8];  //방문처리를 위한 배열 
vector<int> a[8];  //총 7개의 노드가 각각 인접한 노드를 갖을 수 있도록

void dfs(int x){  //x값이 들어왔을때 현재 그 노드를 방문했다면 return 
	if(c[x]) return;
	c[x] = true;  //처음방문했다면 방문처리
	cout << x << ' ';   //해당 노드 출력 
	for(int i = 0; i < a[x].size() ;i++){  //해당노드와 인접한 노드를 방문
		int y = a[x][i];   
		dfs(y); 
	} 
} 

int main(void){
	//1과 2를 연결 
	a[1].push_back(2);  
	a[2].push_back(1); 
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
	
	//시작점을 1로 DFS를 수행 
	dfs(1);   
	
	return 0; 
	
}
