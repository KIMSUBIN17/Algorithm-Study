## 알고리즘 공부 내용 정리

### 5. 그리디(Greedy) 알고리즘 

#### 1. 그리디(Greedy) 알고리즘 기초

그리디알고리즘은 '**당장 눈 앞에 보이는 최적의 상황만을 쫓는 알고리즘**'이다. 항상 최적의 결과를 도출하는 것은 아니지만 어느 정도 최적의 해에 근사한 값을 빠르게 구할 수 있다는 장점이 있따. 특정한 상황에 있어서는 그리디 알고리즘이 최적의 해를 보장할 수도 있다. 대표적인 예제는 거스름 돈 문제이다. 이때 '무조건 더 큰 화폐 단위부터 거슬러 준다.'는 알고리즘만 지키면 최적의 해를 보장할 수 있다. 

그리디 알고리즘은 기본적으로 '무조건 큰 경우대로, 무조건 작은 경우대로, 무조건 긴 경우대로, 무조건 짧은 경우대로' 등으로 극단적으로 문제에 접근한다는 점에서 정렬기법이 함께 사용되기도 한다. (예 - 크루스칼(Kruskal)알고리즘으로 모든 간선을 정렬한 이후에 짧은 간선부터 연결하는 최소 비용 신장 트리 알고리즘이다. )

1260원을 거슬러주어야 할 때 가장 적은 숫자의 화폐를 이용해 거슬러 주는 경우에 대해 생각해보자. '무조건 큰 숫자의 화폐부터 골라서 거슬러주면' 된다. 500원짜리 최대 2개를 거슬러줄 수 있고 560원이 남으면 500원 1개 50원 1개 10원 1개 로 거슬러주면 0원이 되므로 총 6개의 동전만 거슬러 주면 된다. 

  소스코드로 확인해보면

```c++
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


```

![image-20200828141318968](C:\Users\Subin\AppData\Roaming\Typora\typora-user-images\image-20200828141318968.png)



#### >> 그리디 알고리즘 기초 문제풀이 - 1

백준 5585번 거스름돈

```c++
#include <iostream>

using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	n = 1000 - n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	n %= 10;
	result += n / 5;
	n %= 5;
	result += n;
	cout << result;
	return 0;
}
```

백준 11047번 동전 0

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main(void) {
	int n, k;
	cin >> n >> k;
	int result = 0;
	 
	for(int i = 0; i < n; i++){
		int x;
		//화폐 종류 담을 수 있는 배열 생성 
		cin >> x;
		a.push_back(x);
	}
	for(int i = a.size() - 1; i >= 0; i--){
		result += k / a[i];
		k %= a[i];
		//화폐 가치 큰 것부터 나누어줌 (처리순서 거꾸로) 
	}
	cout << result;
	return 0;
}
```

백준 11399번 ATM



백준 2217번 로프



백준 1138번 한 줄로 서기



백준 1541번 잃어버린 괄호



백준 10610번 30



백준 1946번 신입 사원

#### >> 그리디 알고리즘 기초 문제풀이 - 2



백준 2437번 저울

```c++

```



백준 1783번 병든 나이트



백준 1969번 DNA



백준 2812번 크게 만들기







*참고링크 https://blog.naver.com/ndb796/221242106787*