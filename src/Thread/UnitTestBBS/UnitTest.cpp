#include "stdafx.h"
#include "CppUnitTest.h"
#include "BBSOperator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBBS
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �e�X�g �R�[�h�������ɑ}�����܂�
			Assert::AreEqual(1, 1);
			BBSOperator bbs("");
			std::string name;
			bbs.GetBoardName(name);
 
			Assert::IsFalse((name != ""));
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: �e�X�g �R�[�h�������ɑ}�����܂�
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: �e�X�g �R�[�h�������ɑ}�����܂�
			Assert::AreEqual(1, 1);
		}
	};
}
