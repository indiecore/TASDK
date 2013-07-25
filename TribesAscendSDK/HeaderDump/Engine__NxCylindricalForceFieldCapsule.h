#pragma once
#include "Engine__NxCylindricalForceField.h"
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
