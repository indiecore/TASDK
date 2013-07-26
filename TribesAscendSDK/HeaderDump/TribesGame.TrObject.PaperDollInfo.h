#pragma once
#include "Core.Object.Rotator.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.AnimSet.h"
#include "Engine.AnimTree.h"
#include "Engine.PhysicsAsset.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.PaperDollInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrObject.PaperDollInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrObject.PaperDollInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PaperDollInfo
	{
	public:
		ADD_VAR(::BoolProperty, bIsLoading, 0x2)
		ADD_VAR(::BoolProperty, bIsStreaming, 0x1)
		ADD_VAR(::FloatProperty, CharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlySelfShadow, 0x1)
		ADD_OBJECT(AnimSet, AnimSet)
		ADD_OBJECT(AnimTree, AnimTreeTemplate)
		ADD_OBJECT(PhysicsAsset, PhysAsset)
		ADD_OBJECT(SkeletalMesh, SkelMesh)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
