#pragma once

#include <windows.h>
#include <process.h>

// �X���b�h�Ǘ��N���X.
// �N���e�B�J���Z�N�V�����ɂĔr��������s��.
class SynchronizedThread
{
public:
	SynchronizedThread();
	virtual ~SynchronizedThread();

public:
	void start();								// run���\�b�h���X���b�h���s.
	virtual void run() = 0;						// ���s�������e.

private:
	static void threadMethod(void * arg);		// �X���b�h�Ɏw�肷�郁�\�b�h.
	static CRITICAL_SECTION criticalSection;	// �N���e�B�J���Z�N�V����.
};
