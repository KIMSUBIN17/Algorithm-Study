#include <iostream>

using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	result += n / 500;  //500원으로 총 몇번 나누어지는지 (몫 만큼 더함) 
	n %= 500;  // 거슬러줘야하는 돈을 500원 미만으로 떨어트림 
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	cout << result;
	return 0;
}
