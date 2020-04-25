/*

	https://programmers.co.kr/learn/courses/30/lessons/42587?language=cpp
	����/ť - ������

*/
#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location) {
	//list�� Ȱ���� ��ȯť
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
				importance = true; // �� ū �켱������ ������ �ִٸ� true;
				break;
			}
		}

		if (importance == true) { //�켱������ ���� ������ �����Ƿ�
			li.erase(li.begin()); //���� ���� ������ �ڷκ���
			li.push_back({ prior, index });
			importance = false;
		}
		else {
			cnt++; 
			if (location == index) answer = cnt; //ã�� ��ġ�� ������ ��� 
			li.erase(li.begin());
		}
	}

	return answer;
}

int main() {
	printf("%d\n", solution({ 2, 1, 3, 2 }, 2));
	printf("%d\n", solution({ 1, 1, 9, 1, 1, 1 }, 0));
}