#pragma once
#include "Engine.Player.h"
#include "Engine.ChildConnection.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NetConnection : public Player
	{
	public:
		ADD_STRUCT(ScriptArray<class ChildConnection*>, Children, 20416)
	};
}
#undef ADD_STRUCT
