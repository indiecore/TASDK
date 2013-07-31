#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTSkelControl_Damage : public UDKSkelControl_Damage
	{
	public:
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49311);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49315);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
