#include <iostream>

using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	result += n / 500;  //500������ �� ��� ������������ (�� ��ŭ ����) 
	n %= 500;  // �Ž�������ϴ� ���� 500�� �̸����� ����Ʈ�� 
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	cout << result;
	return 0;
}
