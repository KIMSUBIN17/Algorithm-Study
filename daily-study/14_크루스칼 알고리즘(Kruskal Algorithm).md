## 알고리즘 공부 내용 정리

### 7. 크루스칼 알고리즘(Kruskal Algorithm)

크루스칼 알고리즘은 '**가장 적은 비용으로 모든 노드를 연결**'하기 위해서 사용하는 알고리즘으로, 최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘이다.  여러 개의 도시가 있을 때 최소의 비용으로 각 도시를 도로로 이용해 여-연결하고자 할때 실제 적용하는 알고리즘이다.

- 노드 = 정점 = 도시: 그래프에서 동그라미에 해당하는 부분
- 간선 = 거리 = 비용 : 그래프에서 선에 해당하는 부분

간선의 개수 = 노드 - 1개 이다.

모든 노드를 최대한 적은 비용을 사용해 연결시키면 되기 때문에 간선 정보를 오름차순 정렬해 비용이 적은 간선부터 그래프에 포함시키면 된다. 

노드1~7까지 연결된 모든 간선 정보를 저장하고,

모든 간선들을 '거리(비용)을 기준으로 오름차순 정렬을 수행'하고 알고리즘에 맞게 그래프를 연결하면 '**가장 적은 비용으로 모든 노드를 연결한 그래프**'인 '**최소 신장 트리**' 가 만들어진다.

1. 정렬된 순서에 맞게 그래프에 포함시킨다.
2. 포함시키기 전에 사이클 테이블을 확인한다.
3. 사이클을 형성하는 경우 간선을 포함하지 않는다. 

사이클 발생 여부를 확인할 때 Union-Find 알고리즘을 사용한다.



  소스코드로 확인해보면

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//특정한 노드의 부모 가져옴
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
	if( a == b ) return 1;
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
			//이미 포함되어 있으면(사이클 존재함) 무시 
		}
	}
	
	printf("%d\n", sum);
}


```

![image-20200828182117008](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200828182117008.png)

크루스칼 알고리즘의 시간 복잡도는 정렬 알고리즘과 동일하다. 

크루스칼 알고리즘은 정렬 알고리즘과 Union - Find알고리즘의 합이라고 할 수도 있다.



*참고링크 https://blog.naver.com/ndb796/221230994142*