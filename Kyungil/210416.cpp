#include <iostream>
#include "210416 1.mainGame.h"
#include "210416 2.CardGame.h"
#include "210416 3.BowlingGame.h"
// 공용 라이브러리는 < >를 사용하고, 사용자가 만든 라이브러리는 " "를 사용한다.

using namespace std;

int main()
{
	// 클래스 == 객체
	mainGame mg;

	// C++에서의 클래스와 구조체의 차이점
	// C++에 클래스는 기본 선언이 private이며, 구조체는 public이다.
	// C#에서의 클래스와 구조체의 차이점

	// 정적할당 - 메모리가 스택 영역에 잡힌다
	// 컴파일 이전단계에서부터 메모리 공간을 확보하고 들어온다.
	// 런타임(실행도중) 중에 삭제가 불가능하다
	// 선언방법은 아래와 같다.
	mainGame mg2;

	// 동적할당 - 메모리가 힙(heap) 영역에 잡힌다.
	// 컴파일 이후에 메모리 공간을 대여한다.
	// 그렇게 때문에 런타임 중에 삭제가 가능하다.
	mainGame* mg3 = new mainGame;
	delete mg3;

	// 실습
	int user_game_choice;
	cout << "1. 카드게임 2. 볼링게임 " << endl;
	cout << "무슨 게임을 하고 싶으신가요 ? " << endl;
	cin >> user_game_choice;

	switch (user_game_choice)
	{
		// 1번 카드게임
		case 1:
		{
			CardGame CG;
			break;
		}

		// 2번 볼링게임
		case 2:
		{
			BowlingGame BG;
			break;
		}

		// 그외 
		default:
		{
			cout << "잘못입력하셨습니다! " << endl;
			break;
		}
	}
}