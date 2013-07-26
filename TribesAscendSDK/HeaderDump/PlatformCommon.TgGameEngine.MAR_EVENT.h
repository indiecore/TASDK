#pragma once
#include "Core.Object.Pointer.h"
#include "Core.Object.QWord.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TgGameEngine.MAR_EVENT." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TgGameEngine.MAR_EVENT." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MAR_EVENT
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, pMarshal, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, fsMessage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nStmMsgId, 0xFFFFFFFF)
		ADD_STRUCT(::QWordProperty, qwInfo, 0xFFFFFFFF)
		ADD_STRUCT(::QWordProperty, qwId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nFunction, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSuccess, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
