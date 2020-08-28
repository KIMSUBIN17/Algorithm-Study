#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

//간선 클래스 선언
class Edge {
public:
	int node[2];
	int distance;  //거리=비용정보
	Edge(int a, int b, int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
		
	} 
	//정렬(거리가 작은거 먼저 출력되게) 
	bool operator <(Edge &edge){
		return this -> distance < edge.distance;
		
	}

}; 



int main(void) {
	int n = 7;  	//정점
	int m = 1; 		//간선
	
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	
	//간선의 비용으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	//각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for (int i = 0; i < n; i++)   //union-find알고리즘 
	{
		parent[i] = i;  //모든 정점이 자기자신 가리키게 
	}
	
	//거리의 합을 0으로 초기화
	int sum = 0;
	for(int i = 0; i < v.size();i++) {
		//사이클이 발생하지 않는 경우(동일한 부모를 가리키지 않은) 그래프에 포함
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			//간선에서의 첫번째 노드와 두번째 노드가 서로 연결되지 않은상태(사이클생성X) 
			sum += v[i].distance;  //해당 거리만큼 결과값에 더 함 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1); // 실제 두개 노드 연 결
			//이미 포함되어 있으면(사이클 존재함녀) 무시 
		}
	}
	
	printf("%d\n", sum);
}


