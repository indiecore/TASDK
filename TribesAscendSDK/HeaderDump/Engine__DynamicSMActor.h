#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInterface.h"
#include "Engine__SeqAct_SetMesh.h"
#include "Engine__StaticMesh.h"
#include "Engine__SeqAct_SetMaterial.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicSMActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DynamicSMActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DynamicSMActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DynamicSMActor : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, ReplicatedMeshScale3D, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, ReplicatedMeshRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ReplicatedMeshTranslation, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bSafeBaseIfAsleep, 0x4)
		ADD_VAR(::BoolProperty, bPawnCanBaseOn, 0x2)
		ADD_VAR(::BoolProperty, bForceStaticDecals, 0x1)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial)
		ADD_OBJECT(StaticMesh, ReplicatedMesh)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnSetMesh'
		// Here lies the not-yet-implemented method 'OnSetMaterial'
		// Here lies the not-yet-implemented method 'SetStaticMesh'
		// Here lies the not-yet-implemented method 'CanBasePawn'
		// Here lies the not-yet-implemented method 'Attach'
		// Here lies the not-yet-implemented method 'Detach'
		// Here lies the not-yet-implemented method 'SetLightEnvironmentToNotBeDynamic'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
