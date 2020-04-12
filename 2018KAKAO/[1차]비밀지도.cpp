/*
	프로그래머스
	2018 KAKAO BLIND [1차] 비밀지도
	https://programmers.co.kr/learn/courses/30/lessons/17681
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;
string toBinary(int a, int n) {
	string s;

	while (n--) {
		if (a % 2) s ='#' + s;
		else s =' ' + s;
		a = a / 2;
	}
	return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		answer.push_back(toBinary(arr1[i] | arr2[i], n));
	}

	return answer;
}

int main() {
	vector <string> s;
	int n = 5;
	vector <int> arr1 = {9, 20, 28, 18, 11};
	vector <int> arr2 = {30, 1, 21, 17, 28};

	s = solution(n, arr1, arr2);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
}
