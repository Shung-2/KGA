#include "210420 4. VectorTest.h"

VectorTest::VectorTest()
{
	// �������� �����͸� ������
	// Push_back()
	_vNum.push_back(1);
	_vNum.push_back(2);

	for (int i = 0; i < 5; i++)
	{
		_vNum.push_back(i * 100);
	}

	// �ڷḦ ���ʷ� ����
	// pop_back()
	_vNum.pop_back();
	_vNum.pop_back();

	// �߰��� �����Ϸ��� insert()
	_vNum.insert(_vNum.begin() + 3, 777);
	_vNum.insert(_vNum.end() - 2, 22);
	// begin�� Vector�� �� ���ڸ� =(���� ó��),  777�� '��'
	// end�� Vecotr�� �� ���ڸ� =(���� ��), 22�� '��'

	// �߰��� �����͸� �����Ϸ��� erase()
	_vNum.erase(_vNum.begin() + 2);
	_vNum.erase(_vNum.end() - 1);
	// begin�� end�� ���� ����.

	// �ϴ� ������ ������ clear()
	// _vNum.clear()

	// �����̳��� �ڷ� ������ ��ȯ���ִ� size()
	cout << "���� ���� ������ : " << _vNum.size() << endl;
	for (int i = 0; i < _vNum.size(); i++)
	{
		cout << _vNum[i] << endl;
	}
}

VectorTest::~VectorTest()
{

}

// * ��Ÿ*
// resize(), reserve() == �����صθ� �� ������ ������ ����...

// �ÿ��̰� _vNum�� 7�� ������ �ϰ� ���� �Է��ϰ� Ŭ��� �ϸ�
// ������� 0�̰�����, ������ ������ 7���� ���� �����ִ�.

// Push_back�� emplace_back�� ����
// https://sonagi87174.tistory.com/14