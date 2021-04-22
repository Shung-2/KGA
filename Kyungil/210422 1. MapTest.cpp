#include "210422 1. MapTest.h"

MapTest::MapTest()
{
	// 선형구조로는 vector, list, deque
	// 트리구조로는 set, map이 있다.

	// 맵은 자동적으로 정렬하며, 레드블랙 트리로 구성되어 있다.
	// 아울러 연관 컨테이너 중 하나이다.	
	// 아울러 key, value로 구성되어 있고 key는 중복을 허용하지 않고, 오름차순으로 정렬된다.

	// 연관컨테이너란? key, value 처럼 관련이 있는 데이터를 하나의 쌍으로 저장하는 컨테이너.

	// 맵은 푸쉬백이 없다.
	// insert로 넣게 되어 있다.

	// 키와 값을 한쌍으로 데이터를 저장한다 (한쌍 : pair)
	// pair : 두 객체를 하나의 객체로 취급해준다
	// make_pair(데이터, 값) 데이터와 값을 pairing 한다.
	// 보다 자세한 내용 : https://velog.io/@choiiis/C-pair

	// 그럼 어디에 사용하나?
	// 정렬이 필요할때 > 자동 정렬해주므로, 많은 자료를 저장하고 검색이 빨라야 할 떄,
	// 빈번하게 삽입 / 삭제가 필요로 하지 않을때

	_mapTest.insert(pair<const char*, int>("민준", 4));
	_mapTest.insert(pair<const char*, int>("현진", 8));
	_mapTest.insert(pair<const char*, int>("유림", 7));

	_mi = _mapTest.find("현진"); // 맵 안에 0 민준, 1 현진, 2 유림

	// 맵 이터레이터가 맵의 끝이 아니라면 =(만약에 키 값이 있으면)
	if (_mi != _mapTest.end())
	{
		cout << _mi->first << "가 좋아하는 숫자는 " << _mi->second << " 입니다. " << endl;
		// first 찾는 키값, second 데이터
	}
	else // 만약에 키 값이 없으면
	{
		cout << "그런 애는 없는데요.." << endl;
	}

	// 던전앤 파이터와 같은 게임을 구현할 때 (z order)구현이 어렵다면 map을 이용하여 구현할 수 있다.
	// why? 자동으로 정렬되기 떄문에!
	// z order에 대한 보다 자세한 내용 https://mores.tistory.com/210
}
MapTest::~MapTest()
{

}