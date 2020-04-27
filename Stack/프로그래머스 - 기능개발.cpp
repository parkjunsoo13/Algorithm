/*
	프로그래머스 stack 기능개발
	https://programmers.co.kr/learn/courses/30/lessons/42586?language=cpp
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector <int> answer;
	stack <int> stk;
	double day;
	int max = 0;
	int cnt = 0;
	int d;
	for (int i = 0; i < progresses.size(); i++) {
		day = ceil((100 - (double)progresses[i]) / (double)speeds[i]);
		d = (int)day;

		if (stk.empty()) { //스텍이 비어 있을경우
			max = d;       //stk.begin을 max에 저장
		}
		if (max < d) {
			answer.push_back(stk.size());
			while (!stk.empty()) {stk.pop();} // 스텍비우기
			max = d;
		}
		stk.push(d);
		if(i == progresses.size() - 1) //마지막작업 일 경우
			answer.push_back(stk.size());
	}
	return answer;
}

int main() {
	vector <int> result = solution({ 40, 93, 30, 55, 60, 65 }, { 60, 1, 30, 5 , 10, 7 });
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
}