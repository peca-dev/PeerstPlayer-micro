#include <iostream>
#include "BBSOperator.h"

int main()
{
	BBSOperator bbs("http://yy33.kakiko.com/test/read.cgi/peercast/1350753291/");

	// �f�����擾.
	std::string boardName = "";
	bbs.GetBoardName(boardName);
	printf("�f����: %s", boardName.c_str());
}
