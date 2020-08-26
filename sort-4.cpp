#include <iostream>
#include <algorithm>

using namespace std; 

class Student {
	public:
		string  name;
		int score;
		Student(string name, int score){  //생성자:특정객체초기화 
			this->name = name;
			this->score = score;
		}
		//정렬 기준은 '점수가 작은 순서'
		bool operator <(Student &student){
			return this->score < student.score;
			//다른학생과 비교시 내 점수가 더 낮다면 우선순위 높다 
		} 
};
int main(void) {
	Student students[]={
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5);
	
	for(int i = 0; i < 5; i++){
		cout <<students[i].name << ' ';
	} 
}