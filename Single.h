#pragma once  
#include "defines.h"  

class Single  
{  
protected:  
	Single();
virtual ~Single() = default;
public:  
static Single* GetInst()  
{  
	if (m_inst == nullptr)  
		m_inst = new Single;  
	return m_inst;  
}  
static void DestoryInst()  
{  
	if (m_inst != nullptr)  
	{  
		delete m_inst;  
		m_inst = nullptr;  
	}  
}  
private:  
static Single* m_inst;  
};
