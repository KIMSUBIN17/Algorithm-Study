#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Ư���� ����� �θ� ã�� 
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;  //x���� �ش� �θ��� ���� ������ x��ȯ(����Լ��� ��������)	
	//�ٸ��� �����θ� ã������ ��� ���� 
	return parent[x] = getParent(parent, parent[x]);
	
}

// �� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a ; //�� ���� ������ �θ� ������
	else parent[a] = b; 
} 

// ���� �θ� ��� �������� Ȯ�� 
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if( a ==b ) return 1;
	else return 0;
}

//���� Ŭ���� ����
class Edge {
public:
	int node[2];
	int distance;  //�Ÿ�=�������
	Edge(int a, int b, int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
		
	} 
	//����(�Ÿ��� ������ ���� ��µǰ�) 
	bool operator <(Edge &edge){
		return this -> distance < edge.distance;
		
	}

}; 



int main(void) {
	int n = 7;  	//����
	int m = 1; 		//����
	
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
	
	
	//������ ������� �������� ����
	sort(v.begin(), v.end());
	
	//�� ������ ���Ե� �׷����� ������� ����
	int parent[n];
	for (int i = 0; i < n; i++)   //union-find�˰��� 
	{
		parent[i] = i;  //��� ������ �ڱ��ڽ� ����Ű�� 
	}
	
	//�Ÿ��� ���� 0���� �ʱ�ȭ
	int sum = 0;
	for(int i = 0; i < v.size();i++) {
		//����Ŭ�� �߻����� �ʴ� ���(������ �θ� ����Ű�� ����) �׷����� ����
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			//���������� ù��° ���� �ι�° ��尡 ���� ������� ��������(����Ŭ����X) 
			sum += v[i].distance;  //�ش� �Ÿ���ŭ ������� �� �� 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1); // ���� �ΰ� ��� �� ��
			//�̹� ���ԵǾ� ������(����Ŭ �����Գ�) ���� 
		}
	}
	
	printf("%d\n", sum);
}


