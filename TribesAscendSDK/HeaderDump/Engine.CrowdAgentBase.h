#pragma once
#include "Engine.Actor.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CrowdAgentBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CrowdAgentBase : public Actor
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IInterface_NavigationHandle, 0xFFFFFFFF)
		void NotifyPathChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CrowdAgentBase.NotifyPathChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
