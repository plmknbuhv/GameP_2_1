#include "Single.h"
Single* Single::m_inst = nullptr;

Single::Single()
{
	Single::m_inst = this;
}
