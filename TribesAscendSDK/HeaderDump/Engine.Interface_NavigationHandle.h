#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class Interface_NavigationHandle : public Interface
	{
	public:
		void NotifyPathChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18349);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
