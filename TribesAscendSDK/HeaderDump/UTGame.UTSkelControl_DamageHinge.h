#pragma once
#include "UDKBase.UDKSkelControl_DamageHinge.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_DamageHinge : public UDKSkelControl_DamageHinge
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49321);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49325);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
