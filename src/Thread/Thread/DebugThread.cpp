// Thread�N���X�e�X�g�p.
#include "DebugThread.h"
#include <stdio.h>

DebugThread::DebugThread(const std::string _name)
:name(_name)
{
}

DebugThread::~DebugThread()
{
}

// �X���b�h�������e.
void DebugThread::run()
{
	for (long i = 0; i < 20; i++)
	{
		printf("%s:%d\n", name.c_str(), i);
	}
}
