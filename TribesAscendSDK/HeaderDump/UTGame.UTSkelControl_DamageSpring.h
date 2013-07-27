#pragma once
#include "UDKBase.UDKSkelControl_DamageSpring.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_DamageSpring : public UDKSkelControl_DamageSpring
	{
	public:
		void BreakApart(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageSpring.BreakApart");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Object::Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_DamageSpring.BreakApartOnDeath");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
