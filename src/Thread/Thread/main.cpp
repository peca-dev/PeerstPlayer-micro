#include <stdio.h>
#include "DebugThread.h"
#include <windows.h>

int main()
{
	// TODO �X���b�h�̏I���������K�v�H.

	// �X���b�h�N���X�̊m�F.
	DebugThread *threadA = new DebugThread("threadA");
	DebugThread *threadB = new DebugThread("threadB");
	DebugThread *threadC = new DebugThread("threadC");
	DebugThread *threadD = new DebugThread("threadD");
	DebugThread *threadE = new DebugThread("threadE");

	threadA->start();
	threadB->start();
	threadC->start();
	threadD->start();
	threadE->start();

	// �X���b�h���s�҂����[�v.
	while (true)
	{
		Sleep(1);
	}

	delete threadA;
	delete threadB;
	delete threadC;
	delete threadD;
	delete threadE;

	return 0;
}
