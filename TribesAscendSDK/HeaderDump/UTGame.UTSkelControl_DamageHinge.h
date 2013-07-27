#pragma once
#include "UDKBase.UDKSkelControl_DamageHinge.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_DamageHinge : public UDKSkelControl_DamageHinge
	{
	public:
		void BreakApart(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageHinge.BreakApart");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageHinge.BreakApartOnDeath");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
