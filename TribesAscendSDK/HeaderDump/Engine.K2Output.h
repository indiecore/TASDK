#pragma once
#include "Engine.K2Connector.h"
#include "Engine.K2Input.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2Output : public K2Connector
	{
	public:
		ADD_STRUCT(ScriptArray<class K2Input*>, ToInputs, 80)
	};
}
#undef ADD_STRUCT
