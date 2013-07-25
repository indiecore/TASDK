#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class Interface_NavigationHandle : public Interface
	{
	public:
		void NotifyPathChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interface_NavigationHandle.NotifyPathChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
