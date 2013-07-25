#pragma once
#include "UDKBase.UDKSkelControl_DamageHinge.h"
namespace UnrealScript
{
	class UTSkelControl_DamageHinge : public UDKSkelControl_DamageHinge
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageHinge.BreakApart");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageHinge.BreakApartOnDeath");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
