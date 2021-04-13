// 1일차 수업 (21.04.08)

// 주석
// 주석은 컴퓨터가 못 읽는다. 

// main 함수는 꼭 1개 있어야한다.

// 메인 함수의 유형
// 1. 
//int main()
//{
//	return 0;
//}
//
// 2.
//void main()
//{
//
//}

// 콘솔용 폰트
// MS - Consolas
// Apple - Monaco, Menlo

#include <iostream>
// 컴파일러 지시기
// C++ 입출력 입력 방식 > iostream
// C 언어 입출력도 포함하고 있다.

using namespace std;

int main()
{	
	std::cout << "Hello World !" << std::endl;
	std::cout << "무야호~" << std::endl;
	std::cout << "그만큼 신나시는다는 거겠지~ \n\n";

	// using namespace std;을 사용하면
	// std를 귀찮게 안붙여도 된다.
	cout << "Hello World !" << endl;
	cout << "무야호~" << endl;
	cout << "그만큼 신나시는다는 거겠지~" << endl << endl;

	// endl은 개행을 의미한다.
	cout << "개행 테스트~" << endl << endl << endl << endl << endl;
	cout << "개행 끝!" << endl << endl;

	// 문자열 출력할땐 ""
	// 문자를 출력할땐 ''
	cout << "나는 문자~ 'A' " << endl;
	cout << "나는 문자열~ 밥은 잘 먹고 다니니?" << " 응애 나 애기 코린이 코딩 못해 알려줘" << endl << endl;

	cout << "안녕하세요 저는 고길동입니다." << endl;
	cout << 'Z' << endl;

	cout << "코코코자로 시작하는 말은~ 코로나 코스믹보이 코골이 코털" << endl;
	cout << 'H' << endl << endl;

	cout << "까치 까치 설날은 어저께고요" << endl;
	cout << "지엔장~ 믿고 있었다고" << endl;
	cout << "준비됐어 신?" << "물론이지 이" << endl;

	cout << "가나다라마바사 아자차카타파하" << endl;
	cout << 'A' << ',' << ' ' << 'B' << 'C' << 'D' << endl;
	cout << 'A' << 'B' << 'C' << 'D' << endl;
	cout << "기억나? " << "응? " << "? " << "호랑나비 " << "키보드 마우스" << endl << endl;

	// '변하는 수'이기 때문에 변수라고 한다.
	// 변수
	
	// 정수형 변수
	// 변수타입				크기			   		 범위
	// int					4byte		약 -22억 ~ 21억까지의 범위
	// unsigned int			4byte		약 0 ~ 43억까지의 범위
	// long					4byte		약 ~22억 ~ 21억까지의 범위
	// unsigned long		4byte		약 0 ~ 43억까지의 범위
	// short				2byte		-32768 ~ 32767 정수를 담는다.
	// unsigned short		2byte		0 ~ 65535 정수를 담는다.

	// int와 long의 차이는? 답 - 너비다.
	// int는 32비트의 너비를 가지고, long은 64비트 너비의 가지를 가진다.

	// 실수형 변수
	// 변수타입				크기			   		 범위
	// float				4byte		소수점 6자리까지의 실수를 담음
	// double				8byte		소수점 15자리까지의 실수를 담음

	// 문자형 변수
	// 변수타입				크기			   		 범위
	// cahr (차 X 캐릭터)	1byte		정수를 담는다 (문자)
	// unsigned char		1byte		양의 정수를 담는다 (문자)

	// 참 거짓
	// 변수타입				크기			   		 범위
	// bool					1byte		참(1), 거짓(0)

	// 변수의 선언 방법
	// 헝가리안, 카멜, 파스칼, 언더

	// 헝가리안 표기법
	// 마소에서 금지 권고를 때렸다.
	// 함수, 변수명 앞에 형을 구분할 접두사를 쓴다
	// nint, fspeed, bresult 등..

	// 카멜 표기법
	// 단어와 단어사이를 대문자로 구분하는 방법
	// int selectNumber, choiceNumber 등..

	// 변수 선언시 주의사항
	// 1. 알아먹을 수 있는 이름으로 선언한다.
	// 1-예)
	// int a, int b, 등과 같은 변수는 나중에 알 수 없으니 지양하자.

	// 2. 변수명 앞에 숫자는 올 수 없다. 뒤는 가능	
	// 2-예)
	// int 1Player_HP
	// 위와 같은 경우는 사용할 수 없다.

	// 3. 예약어는 사용할 수 없다.
	// 3-예)
	// int, float 같은 MS에서 사용하는 예약어는 변수명을 가질 수 없다.

	// 4. 변수명은 중복을 허용하지 않는다.
	// 4-예)
	// int HP;
	// int HP; 
	// HP를 2번 정의하였으므로 실행되지 않음.

	// 5. 변수 선언 시 초기화를 하자. 
	// 5-예)
	// int humanHP;
	// cout << humanHP << endl;
	// 실행되지 않음.

	short Tree_Hp = 30;

	int Human_Hp = 200;
	int Human_Atk = 10;

	float Elf_Hp = 250.0;
	int Elf_Atk = 150;

	double Dragon_Hp = 1500.0;
	int Dragon_Atk = 225;

	cout << "현재 나무의 체력은? : " << Tree_Hp << endl;
	cout << "지나가는 사람이 나무를 때렸다! " << endl;
	cout << "지나가는 사람의 공격력은 " << Human_Atk << " 이다! " << endl;
	Tree_Hp -= Human_Atk;
	cout << "나무의 체력 : " << Tree_Hp << endl << endl;

	cout << "이 때 한쪽에서 엘프가 드래곤을 때렸다!" << endl;
	cout << "드래곤의 체력은 : " << Dragon_Hp << endl;
	cout << "엘프의 공격력은 : " << Elf_Atk << endl;
	Dragon_Hp -= Elf_Atk;
	cout << "드래곤의 체력은 엘프의 공격을 받아 " << Dragon_Hp << "이 되었다. 어림 판분어치도 없는 공격!" << endl << endl;

	cout << "잠자코 있던 드래곤이 엘프를 때렸다!" << endl;
	cout << "엘프의 체력은 : " << Elf_Hp<< endl;
	cout << "드래곤의 공격력은 : " << Dragon_Atk << endl;
	Elf_Hp -= Dragon_Atk;
	cout << "엘프의 체력은 드래곤의 공격을 받아 " << Elf_Hp << "이 되었다. 엘프는 놀라 도망갔다!" << endl;
		   	
	return 0;
}