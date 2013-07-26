#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlineRegistrant." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineRegistrant
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerNetId, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
