#pragma once
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty LocalPlayer.SynchronizedActorVisibilityHistory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SynchronizedActorVisibilityHistory
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, CriticalSection, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, State, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
