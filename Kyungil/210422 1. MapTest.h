#pragma once
#include <iostream>
#include <map>
using namespace std;
// 다른 언어에서는 딕셔너리 라고 한다 있다.

class MapTest
{
private:
	// 연관 컨테이너 종류 중 하나이다.
	// first, second 인자 2개를 가지고 있다.
	map<const char*, int>			_mapTest;
	map<const char*, int>::iterator _mi;
	
	// 1만개 미만의 데이터는 벡터가 유리하다 (배열로 구성되어 있기 때문)
	// 1만개 이상의 데이터는 리스트가 유리하다.
	// 10만개 이상의 데이터는 맵이 유리하다.
	// 100만개 이상의 데이터는 해쉬 맵이 유리하다.
	// hash_map -> unordered_map 으로 사용을 권장하고 있다.
	// map = 레드블랙 트리, hash_map은 (?)로 되어 있다.

public:
	MapTest();
	~MapTest();
};

