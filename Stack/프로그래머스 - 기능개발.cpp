/*
	���α׷��ӽ� stack ��ɰ���
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

		if (stk.empty()) { //������ ��� �������
			max = d;       //stk.begin�� max�� ����
		}
		if (max < d) {
			answer.push_back(stk.size());
			while (!stk.empty()) {stk.pop();} // ���غ���
			max = d;
		}
		stk.push(d);
		if(i == progresses.size() - 1) //�������۾� �� ���
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