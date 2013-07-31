#pragma once
#include "Engine.AnimNodeBlend.h"
namespace UnrealScript
{
	class UDKAnimBlendByDriving : public AnimNodeBlend
	{
	public:
		void UpdateDrivingState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34491);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
