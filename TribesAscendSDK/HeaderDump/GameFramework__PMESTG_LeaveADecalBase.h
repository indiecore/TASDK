#pragma once
#include "Engine__ParticleModuleEventSendToGame.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.PMESTG_LeaveADecalBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PMESTG_LeaveADecalBase : public ParticleModuleEventSendToGame
	{
	public:
		ADD_OBJECT(ScriptClass, PhysicalMaterialPropertyClass)
	};
}
#undef ADD_OBJECT
