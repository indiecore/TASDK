#pragma once
#include "Engine.OnlineSubsystem.OnlineRegistrant.h"
#include "Core.Object.QWord.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlineArbitrationRegistrant." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlineArbitrationRegistrant." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineArbitrationRegistrant : public OnlineRegistrant
	{
	public:
		ADD_STRUCT(::QWordProperty, MachineId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Trustworthiness, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
