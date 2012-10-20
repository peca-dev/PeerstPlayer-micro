#include "SynchronizedThread.h"

CRITICAL_SECTION SynchronizedThread::criticalSection = {};

SynchronizedThread::SynchronizedThread()
{
	InitializeCriticalSection(&criticalSection);
}

SynchronizedThread::~SynchronizedThread()
{
}

// �X���b�h�����s.
void SynchronizedThread::start()
{
	// �X���b�h�n���h���͎����ŉ�������.
	_beginthread(&SynchronizedThread::threadMethod, 0, this);
}

// ��ۃN���X�ɂĎ�������run���\�b�h���Ăяo��.
void SynchronizedThread::threadMethod(void * arg)
{
	SynchronizedThread * thread = reinterpret_cast<SynchronizedThread*>(arg);

	if (NULL != thread)
	{
		// �N���e�B�J���Z�N�V���� / �X���b�h���s.
		EnterCriticalSection(&criticalSection);
		thread->run();
		LeaveCriticalSection(&criticalSection);
	}
}
