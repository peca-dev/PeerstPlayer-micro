#include "Thread.h"
#include <process.h>

Thread::Thread()
{
}

Thread::~Thread()
{
}

// �X���b�h�����s.
void Thread::start()
{
	// �X���b�h�n���h���͎����ŉ�������.
	_beginthread(&Thread::threadMethod, 0, this);
}

// ��ۃN���X�ɂĎ�������run���\�b�h���Ăяo��.
void Thread::threadMethod(void * arg)
{
	Thread * thread = reinterpret_cast<Thread*>(arg);

	if (NULL != thread)
	{
		// �X���b�h���s.
		thread->run();
	}
}
