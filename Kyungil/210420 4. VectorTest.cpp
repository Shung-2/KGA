#include "210420 4. VectorTest.h"

VectorTest::VectorTest()
{
	// 차곡차곡 데이터를 넣을땐
	// Push_back()
	_vNum.push_back(1);
	_vNum.push_back(2);

	for (int i = 0; i < 5; i++)
	{
		_vNum.push_back(i * 100);
	}

	// 자료를 차례로 뺄때
	// pop_back()
	_vNum.pop_back();
	_vNum.pop_back();

	// 중간에 삽입하려면 insert()
	_vNum.insert(_vNum.begin() + 3, 777);
	_vNum.insert(_vNum.end() - 2, 22);
	// begin은 Vector의 맨 앞자리 =(제일 처음),  777은 '값'
	// end는 Vecotr의 맨 뒷자리 =(제일 끝), 22는 '값'

	// 중간에 데이터를 삭제하려면 erase()
	_vNum.erase(_vNum.begin() + 2);
	_vNum.erase(_vNum.end() - 1);
	// begin과 end는 위와 같다.

	// 싹다 날리고 싶으면 clear()
	// _vNum.clear()

	// 컨테이너의 자료 갯수를 반환해주는 size()
	cout << "지금 벡터 갯수는 : " << _vNum.size() << endl;
	for (int i = 0; i < _vNum.size(); i++)
	{
		cout << _vNum[i] << endl;
	}
}

VectorTest::~VectorTest()
{

}

// * 기타*
// resize(), reserve() == 공부해두면 참 좋은데 지금은 굳이...

// 시영이가 _vNum을 7개 선언을 하고 값을 입력하고 클리어를 하면
// 사이즈는 0이겠지만, 공간은 아직도 7개의 값이 남아있다.

// Push_back과 emplace_back의 차이
// https://sonagi87174.tistory.com/14