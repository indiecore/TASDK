#pragma once
#include "UDKBase.UDKSkelControl_DamageSpring.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_DamageSpring : public UDKSkelControl_DamageSpring
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49331);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49335);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
