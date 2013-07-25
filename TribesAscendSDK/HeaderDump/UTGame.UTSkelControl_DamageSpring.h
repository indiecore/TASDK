#pragma once
#include "UDKBase.UDKSkelControl_DamageSpring.h"
namespace UnrealScript
{
	class UTSkelControl_DamageSpring : public UDKSkelControl_DamageSpring
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageSpring.BreakApart");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageSpring.BreakApartOnDeath");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
