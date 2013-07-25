#pragma once
#include "Engine.AnimNodeBlend.h"
namespace UnrealScript
{
	class UDKAnimBlendByDriving : public AnimNodeBlend
	{
	public:
		void UpdateDrivingState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByDriving.UpdateDrivingState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
