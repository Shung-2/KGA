// ############################################
// ## 210527 수업 내용 Save&Load, Loop Render ##
// ############################################

#pragma once
#include "gameNode.h"

class saveLoadTest : public gameNode
{
public:
	saveLoadTest();
	~saveLoadTest();

	void update();
	void save();
	void load();
};