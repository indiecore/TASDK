#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#include "Core.Object.Vector.h"
namespace UnrealScript
{
	class UTSkelControl_Damage : public UDKSkelControl_Damage
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_Damage.BreakApart");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_Damage.BreakApartOnDeath");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = PartLocation;
			*(bool*)(params + 12) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
