#pragma once

#include <windows.h>

// �X���b�h�Ǘ��N���X.
// �r������͍s��Ȃ�.
class Thread
{
public:
	Thread();
	virtual ~Thread();

public:
	void start();								// run���\�b�h���X���b�h���s.
	virtual void run() = 0;						// ���s�������e.
	// TODO �X���b�h�̏I���������K�v�H.

private:
	static void threadMethod(void * arg);		// �X���b�h�Ɏw�肷�郁�\�b�h.
};
