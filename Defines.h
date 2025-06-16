#pragma once
#define SAFE_DELETE(p) if (m_inst != nullptr){delete p; p = nullptr;}