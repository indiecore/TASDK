#pragma once
#include "Engine__SkeletalMeshActorSpawnable.h"
#include "Engine__MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployableHologram." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployableHologram." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableHologram : public SkeletalMeshActorSpawnable
	{
	public:
		ADD_VAR(::IntProperty, m_nOldInvalidDeployReason, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_RuntimeMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HologramMaterial)
		// Here lies the not-yet-implemented method 'SetValidDeployableLocation'
		// Here lies the not-yet-implemented method 'ClearAllMessages'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'Init'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
