#include <iostream>
#include "210420 1. Player.h"
#include "210420 2. Enemy.h"
#include "210420 3. mainGame5.h"
#include "210420 4. VectorTest.h"
#include "210420 5. ArraySample.h"

int main()
{
	// 사용하려고 동적할당
	Player* pl = new Player;
	Enemy* em = new Enemy;

	// 접근자, 설정자를 통한 예제
	int tempHp = pl->getPlayerHP();
	// tempHp에는 getPlayerHp 접근자 return hp로 인해 tempHp는 100이 된다.
	int tempAtk = em->getEnemyAtk();
	// tempAtk에는 getEnemyAtk 접근자 return Atk로 인해 tempAtk는 10이 된다.

	pl->output();
	// pl의 output은 pl의 체력을 출력한다. tempHp의 체력을 출력하는 것이 아니다.
	pl->setPlayerHP(tempHp - tempAtk);
	// pl의 setPlayerHp 설정자를 통해 값을 가져오지만 매개변수 (tempHp - tempAtk) = (100 - 10)의 값인 90이 setPlayerHp로 반환된다 
	pl->output();
	// pl의 체력은 21행의 코드로 인해 90이 된다.
	
	pl->setPlayerHP(pl->getPlayerHP() - em->getEnemyAtk());
	pl->output();
	em->setEnemyHp(em->getEnemyHP() - pl->getPlayerAtk());
	em->output();
	// 위와같이 사용해도 무관하다. 자세한 설명은 생략한다. (짤)

	// 다 사용했으니 종료
	delete pl;
	delete em;

	// STL
	cout << endl;
	mainGame5 mg;
	/*
	template<typename T>
	inline void mainGame::output(T t)
	output(T t)로 인해 mg.output의 데이터 타입이 무엇이 와도 다 사용이 가능하다!
	*/
	mg.output(7);
	mg.output(3.14f);
	mg.output("점심 뭐먹지?");

	// STL 컨테이너의 종료
	// 스택, 큐, 리스트, 벡터, 맵 등등!

	// 벡터
	VectorTest vT;

	// 배열을 직접 만들어보자.
	cout << endl;
	arraySample<int> arrInt;

	arrInt.pushBack(10);

	for (int i = 0; i < 10; i++)
	{
		arrInt.pushBack(i * 100);
	}

	for (int i = 0; i < arrInt.GetSize(); i++)
	{
		cout << arrInt[i] << endl;
	}
	cout << endl;

	arraySample<float> arrFloat;

	arrFloat.pushBack(3.14f);
	arrFloat.pushBack(181.9f);
	arrFloat.pushBack(150.33f);

	for (int i = 0; i < arrFloat.GetSize(); i++)
	{
		cout << arrFloat[i] << endl;
	}
	cout << endl;

	arraySample<const char*> arrStr;
	arrStr.pushBack("개랑 오리");
	arrStr.pushBack("돼지불백");
	arrStr.pushBack("라멘");
	arrStr.pushBack("도시락");
	arrStr.pushBack("4딸라버거킹");

	for (int i = 0; i < arrStr.GetSize(); i++)
	{
		cout << arrStr[i] << endl;
	}
}