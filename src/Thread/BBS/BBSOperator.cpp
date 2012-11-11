#include "BBSOperator.h"
#include "WaiWaiStrategy.h"

BBSOperator::BBSOperator(const std::string &url)
:strategy(NULL)
{
	// TODO �܂��́AYY�Œ��.
	strategy = new WaiwaiStrategy(url);
}

BBSOperator::~BBSOperator()
{
}

/* ========================================================================= */
/* �֐���: GetBoardName														 */
/* ���e: �f�����擾														 */
/* ���l: 																	 */
/* ========================================================================= */
bool BBSOperator::GetBoardName(std::string &boardName)
{
	return strategy->GetBoardName(boardName);
}
