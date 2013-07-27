#pragma once
#include "Engine.K2Node_Code.h"
#include "Engine.K2Connector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2Node_MemberVar : public K2Node_Code
	{
	public:
		ADD_STRUCT(ScriptString*, VarName, 96)
		ADD_STRUCT(K2Connector::EK2ConnectorType, VarType, 92)
	};
}
#undef ADD_STRUCT
