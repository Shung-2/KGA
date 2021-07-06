#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{

}

playGround::~playGround()
{

}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init();
	
	setBoard();
	setPlayer();
	setBall();
	setScore();
	
	_isStart = _isEnd = false;

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();
}

//여기에다 연산하세요 제에발
void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown('R'))
		this->init();

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		_isStart = !_isStart;

	if (_isStart && !_isEnd)
	{
		Player_Key(P1);
		Player_Key(P2);

		if (!_ball.onBoard)
			makeBall();

		MoveBall();

		colWithBoard();
		colWithPlayer();

		if (isEnd())
			_isEnd = true;
	}
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	
	drawBoard(backDC);
	drawPlayer(backDC);
	drawBall(backDC);
	drawScore(backDC);
	drawResult(backDC);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::setBoard()
{
	_board.img = new image();
	_board.img->init("resource/Board.bmp", BOARDW + 2 * ERRORW, BOARDH + 2 * ERRORH, true, RGB(255, 0, 255));
	_board.x = WINSIZEX / 2;
	_board.y = WINSIZEY / 2;
	_board.body = RectMakeCenter(_board.x, _board.y, BOARDW, BOARDH);
	_board.friction = FRICT;
	_board.goalpost = GOAL;
}

void playGround::setPlayer()
{
	_player1.img = new image();
	_player1.img->init("resource/Player1.bmp", PSIZE, PSIZE, true, RGB(255, 0, 255));
	_player1.x = _board.body.left + PSIZE * 2;
	_player1.y = (_board.body.top + _board.body.bottom) / 2;
	_player1.body = RectMakeCenter(_player1.x, _player1.y, PSIZE, PSIZE);
	_player1.speed = PSPEED;
	_player1.score = 0;

	_player2.img = new image();
	_player2.img->init("resource/Player2.bmp", PSIZE, PSIZE, true, RGB(255, 0, 255));
	_player2.x = _board.body.right - PSIZE * 2;
	_player2.y = (_board.body.top + _board.body.bottom) / 2;
	_player2.body = RectMakeCenter(_player2.x, _player2.y, PSIZE, PSIZE);
	_player2.speed = PSPEED;
	_player2.score = 0;
}

void playGround::setBall()
{
	_ball.img = new image();
	_ball.img->init("resource/ball.bmp", BSIZE, BSIZE, true, RGB(255, 0, 255));
	_ball.x = 0;
	_ball.y = 0;
	_ball.body = RectMakeCenter(_ball.x, _ball.y, BSIZE, BSIZE);
	_ball.speed = 0;
	_ball.angle = 0;
	_ball.onBoard = false;
}

void playGround::setScore()
{
	_score1 = new image;
	_score2 = new image;
	_score1->init("resource/0.bmp", SCOREW, SCOREH, true, RGB(255, 0, 255));
	_score2->init("resource/0.bmp", SCOREW, SCOREH, true, RGB(255, 0, 255));
}

void playGround::Player_Key(int player)
{
	switch (player)
	{
	case P1:

		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_player1.x -= _player1.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_player1.x += _player1.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_player1.y -= _player1.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_player1.y += _player1.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		onBoard(P1);
		_player1.body = RectMakeCenter(_player1.x, _player1.y, PSIZE, PSIZE);
		break;

	case P2:

		if (KEYMANAGER->isStayKeyDown(VK_LEFT)) 
		{
			_player2.x -= _player2.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player2.x += _player2.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_player2.y -= _player2.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_player2.y += _player2.speed;
			if (colWithPlayer())
				_ball.speed = BSPEED;
		}

		onBoard(P2);
		_player2.body = RectMakeCenter(_player2.x, _player2.y, PSIZE, PSIZE);
		break;
	}
}

void playGround::makeBall()
{
	_ball.x = WINSIZEX / 2;
	_ball.y = WINSIZEY / 2;
	_ball.body = RectMakeCenter(_ball.x, _ball.y, BSIZE, BSIZE);
	_ball.speed = BSPEED / 3;
	_ball.angle = RND->getFloat(PI2);
	_ball.onBoard = true;
}

void playGround::MoveBall()
{
	_ball.x += cosf(_ball.angle) * _ball.speed;
	_ball.y -= sinf(_ball.angle) * _ball.speed;
	_ball.body = RectMakeCenter(_ball.x, _ball.y, BSIZE, BSIZE);
	_ball.speed = _ball.speed - _board.friction <= 0 ? 0 : _ball.speed - _board.friction;
}

void playGround::colWithBoard()
{
	if (_ball.body.left < _board.body.left) {
		if (_board.y - _board.goalpost / 2 + BSIZE / 2 < _ball.y &&
			_ball.y < _board.y + _board.goalpost / 2 - BSIZE / 2)
		{
			_player2.score++;
			_ball.onBoard = false;
		}
		else
		{
			_ball.x = _board.body.left + BSIZE / 2;
			_ball.angle = PI - _ball.angle;
		}
	}
	else if (_ball.body.right > _board.body.right)
	{
		if (_board.y - _board.goalpost / 2 + BSIZE / 2 < _ball.y &&
			_ball.y < _board.y + _board.goalpost / 2 - BSIZE / 2)
		{
			_player1.score++;
			_ball.onBoard = false;
		}
		else
		{
			_ball.x = _board.body.right - BSIZE / 2;
			_ball.angle = PI - _ball.angle;
		}
	}

	if (_ball.body.top < _board.body.top)
	{
		_ball.y = _board.body.top + BSIZE / 2;
		_ball.angle = PI2 - _ball.angle;
	}

	else if (_ball.body.bottom > _board.body.bottom)
	{
		_ball.y = _board.body.bottom - BSIZE / 2;
		_ball.angle = PI2 - _ball.angle;
	}
}

bool playGround::colWithPlayer()
{
	if (getDistance(_ball.x, _ball.y, _player1.x, _player1.y) <= (BSIZE / 2 + PSIZE / 2))
	{
		_ball.angle = getAngle(_player1.x, _player1.y, _ball.x, _ball.y);
		return true;
	}
	else if (getDistance(_ball.x, _ball.y, _player2.x, _player2.y) <= (BSIZE / 2 + PSIZE / 2))
	{
		_ball.angle = getAngle(_player2.x, _player2.y, _ball.x, _ball.y);
		return true;
	}
	return false;
}

bool playGround::isEnd()
{
	if (_player1.score >= 5 || _player2.score >= 5)
		return true;

	return false;
}

void playGround::drawBoard(HDC hdc)
{
	_board.img->render(hdc, _board.body.left - ERRORW, _board.body.top - ERRORH);
}

void playGround::drawPlayer(HDC hdc)
{
	_player1.img->render(hdc, _player1.x - PSIZE / 2, _player1.y - PSIZE / 2);
	_player2.img->render(hdc, _player2.x - PSIZE / 2, _player2.y - PSIZE / 2);
}

void playGround::drawBall(HDC hdc)
{
	if (_ball.onBoard)
		_ball.img->render(hdc, _ball.x - BSIZE / 2, _ball.y - BSIZE / 2);
}

void playGround::drawScore(HDC hdc)
{
	char str[128];

	_player1.score = _player1.score < 5 ? _player1.score : _player1.score - 1;
	sprintf_s(str, "resource/%d.bmp", _player1.score);
	_score1->init(str, SCOREW, SCOREH, true, RGB(255, 0, 255));

	_player2.score = _player2.score < 5 ? _player2.score : _player2.score - 1;
	sprintf_s(str, "resource/%d.bmp", _player2.score);
	_score2->init(str, SCOREW, SCOREH, true, RGB(255, 0, 255));

	_score1->render(hdc, _board.body.left + BOARDW / 4 - SCOREW / 2, _board.body.top - SCOREH - ERRORH - 10);
	_score2->render(hdc, _board.body.right - BOARDW / 4 - SCOREW / 2, _board.body.top - SCOREH - ERRORH - 10);
}

void playGround::drawResult(HDC hdc)
{
	if (_isEnd) {
		if (_player1.score >= 5) 
		{

		}
		else if (_player2.score >= 5) 
		{

		}
	}
}

void playGround::onBoard(int player)
{
	switch (player) 
	{
	case P1:

		if (_player1.x - PSIZE / 2 < _board.body.left)
			_player1.x = _board.body.left + PSIZE / 2;

		else if (_player1.x + PSIZE / 2 >= _board.body.right - BOARDW / 2)
			_player1.x = _board.body.right - BOARDW / 2 - PSIZE / 2;

		if (_player1.y - PSIZE / 2 <= _board.body.top)
			_player1.y = _board.body.top + PSIZE / 2;

		else if (_player1.y + PSIZE / 2 >= _board.body.bottom)
			_player1.y = _board.body.bottom - PSIZE / 2;

		break;

	case P2:

		if (_player2.x - PSIZE / 2 <= _board.body.left + BOARDW / 2)
			_player2.x = _board.body.left + BOARDW / 2 + PSIZE / 2;

		else if (_player2.x + PSIZE / 2 >= _board.body.right)
			_player2.x = _board.body.right - PSIZE / 2;

		if (_player2.y - PSIZE / 2 <= _board.body.top)
			_player2.y = _board.body.top + PSIZE / 2;

		else if (_player2.y + PSIZE / 2 >= _board.body.bottom)
			_player2.y = _board.body.bottom - PSIZE / 2;

		break;
	}
}
