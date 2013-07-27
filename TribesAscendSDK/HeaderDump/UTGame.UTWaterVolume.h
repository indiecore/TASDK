#pragma once
#include "Engine.WaterVolume.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTWaterVolume : public WaterVolume
	{
	public:
		ADD_OBJECT(ParticleSystem, ProjectileEntryEffect, 608)
		ADD_OBJECT(ParticleSystem, PS_EnterWaterEffect_Vehicle, 604)
		ADD_OBJECT(ParticleSystem, PS_EnterWaterEffect_Pawn, 600)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWaterVolume.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayEntrySplash(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWaterVolume.PlayEntrySplash");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
