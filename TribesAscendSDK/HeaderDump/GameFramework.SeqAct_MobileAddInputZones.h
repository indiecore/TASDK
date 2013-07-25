#pragma once
#include "Engine.SequenceAction.h"
#include "GameFramework.MobileInputZone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_MobileAddInputZones." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqAct_MobileAddInputZones." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_MobileAddInputZones : public SequenceAction
	{
	public:
		ADD_OBJECT(MobileInputZone, NewZone)
		ADD_VAR(::NameProperty, ZoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
