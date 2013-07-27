#pragma once
#include "Engine.NetConnection.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ChildConnection : public NetConnection
	{
	public:
		ADD_OBJECT(NetConnection, Parent, 20472)
	};
}
#undef ADD_OBJECT
