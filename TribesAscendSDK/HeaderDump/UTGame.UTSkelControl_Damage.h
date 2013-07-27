#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_Damage : public UDKSkelControl_Damage
	{
	public:
		void BreakApart(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_Damage.BreakApart");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_Damage.BreakApartOnDeath");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
