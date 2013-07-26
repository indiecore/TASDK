#pragma once
#include "Engine.PhysicsAsset.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGib.StaticMeshDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGib.StaticMeshDatum." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StaticMeshDatum
	{
	public:
		ADD_VAR(::BoolProperty, bUseSecondaryGibMeshMITV, 0x1)
		ADD_VAR(::FloatProperty, DrawScale, 0xFFFFFFFF)
		ADD_OBJECT(PhysicsAsset, ThePhysAsset)
		ADD_OBJECT(SkeletalMesh, TheSkelMesh)
		ADD_OBJECT(StaticMesh, TheStaticMesh)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
