#pragma once
#include "Engine.K2Node_Code.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Node_MemberVar." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2Node_MemberVar : public K2Node_Code
	{
	public:
		ADD_VAR(::StrProperty, VarName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, VarType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
