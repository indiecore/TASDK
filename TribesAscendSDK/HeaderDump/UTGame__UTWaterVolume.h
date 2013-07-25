#pragma once
#include "Engine__WaterVolume.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWaterVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWaterVolume : public WaterVolume
	{
	public:
		ADD_OBJECT(ParticleSystem, ProjectileEntryEffect)
		ADD_OBJECT(ParticleSystem, PS_EnterWaterEffect_Vehicle)
		ADD_OBJECT(ParticleSystem, PS_EnterWaterEffect_Pawn)
	};
}
#undef ADD_OBJECT
