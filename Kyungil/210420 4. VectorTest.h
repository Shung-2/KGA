#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VectorTest
{
private: 
	// 벡터
	// 배열 형식으로 이루어져있다
	// 늘었다 줄었다 하는 가변형 배열이라 생각하면 쉽다.
	// 삽입 삭제를 많이하면 느려지며 데이터 8천개 이하에서는 속도가 빠르다.

	vector<int>					_vNum;
	vector<int>::iterator		_viNum;
	// iterator = 이터레이터, 반복자 == 디자인패턴
	// iterator의 보다 자세한 설명은 아래와 같다
	// https://eehoeskrap.tistory.com/263

	/* 일부 발췌
	즉, 포인터와 상당히 비슷하며, 컨테이너에 저장되어 있는 원소들을 참조할 때 사용한다.
	추상적으로 말하자면, 반복자란 컨테이너에 저장되어 있는 모든 원소들을 전체적으로 훑어 나갈 때 사용하는,
	일종의 포인터와 비슷한 객체라고 할 수 있다.
	알고리즘 마다 각기 다른 방식으로 컨테이너를 훑어가기 때문에, 반복자에도 여러가지 종류가 있게 된다. 
	*/

public:
	VectorTest();
	~VectorTest();
};