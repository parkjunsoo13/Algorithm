/*

	https://programmers.co.kr/learn/courses/30/lessons/42587?language=cpp
	스텍/큐 - 프린터

*/
#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location) {
	//list를 활용한 순환큐
	bool importance = false; 
	int cnt = 0;
	int answer = 0;
	list <pair<int, int>> li;
	list<pair<int, int>>::iterator it;

	for (int i = 0; i < priorities.size(); i++) {
		li.push_back({ priorities[i], i });
	}

	while (!li.empty()) {
		int prior = li.front().first;
		int index = li.front().second;
		
		for (it = li.begin(); it != li.end(); it++) {
			if (prior < (*it).first) {
				importance = true; // 더 큰 우선순위의 문서가 있다면 true;
				break;
			}
		}

		if (importance == true) { //우선순위가 높은 문서가 있으므로
			li.erase(li.begin()); //가장 앞의 문서를 뒤로보냄
			li.push_back({ prior, index });
			importance = false;
		}
		else {
			cnt++; 
			if (location == index) answer = cnt; //찾는 위치의 문서일 경우 
			li.erase(li.begin());
		}
	}

	return answer;
}

int main() {
	printf("%d\n", solution({ 2, 1, 3, 2 }, 2));
	printf("%d\n", solution({ 1, 1, 9, 1, 1, 1 }, 0));
}