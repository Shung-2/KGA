#pragma once
#include <iostream>
#include <map>
using namespace std;
// �ٸ� ������ ��ųʸ� ��� �Ѵ� �ִ�.

class MapTest
{
private:
	// ���� �����̳� ���� �� �ϳ��̴�.
	// first, second ���� 2���� ������ �ִ�.
	map<const char*, int>			_mapTest;
	map<const char*, int>::iterator _mi;
	
	// 1���� �̸��� �����ʹ� ���Ͱ� �����ϴ� (�迭�� �����Ǿ� �ֱ� ����)
	// 1���� �̻��� �����ʹ� ����Ʈ�� �����ϴ�.
	// 10���� �̻��� �����ʹ� ���� �����ϴ�.
	// 100���� �̻��� �����ʹ� �ؽ� ���� �����ϴ�.
	// hash_map -> unordered_map ���� ����� �����ϰ� �ִ�.
	// map = ����� Ʈ��, hash_map�� (?)�� �Ǿ� �ִ�.

public:
	MapTest();
	~MapTest();
};

