#pragma once
#include "Engine.NxCylindricalForceField.h"
namespace UnrealScript
{
	class NxCylindricalForceFieldCapsule : public NxCylindricalForceField
	{
	public:
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxCylindricalForceFieldCapsule.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
