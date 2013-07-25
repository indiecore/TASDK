#pragma once
#include "Engine__AnimNodeBlendBase.h"
#include "Engine__StaticMesh.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__SkelControlBase.h"
#include "Engine__MorphNodeBase.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimTree." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimTree." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimTree." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimTree : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::IntProperty, PreviewFloorYaw, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreviewFloorPos, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, PreviewCamRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PreviewCamPos, 0xFFFFFFFF
		ADD_VAR(::IntProperty, PreviewAnimSetIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviewAnimSetListIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviewSocketIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviewMeshIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SocketName, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, SocketStaticMesh)
		ADD_OBJECT(SkeletalMesh, SocketSkelMesh)
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh)
		ADD_VAR(::FloatProperty, PreviewPlayRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MorphConnDrawY, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRebuildAnimTickArray, 0x8)
		ADD_VAR(::BoolProperty, bParentNodeArrayBuilt, 0x4)
		ADD_VAR(::BoolProperty, bBeingEdited, 0x2)
		ADD_VAR(::BoolProperty, bUseSavedPose, 0x1)
		// Here lies the not-yet-implemented method 'FindSkelControl'
		// Here lies the not-yet-implemented method 'FindMorphNode'
		// Here lies the not-yet-implemented method 'SetUseSavedPose'
		// Here lies the not-yet-implemented method 'SetAnimGroupForNode'
		// Here lies the not-yet-implemented method 'GetGroupSynchMaster'
		// Here lies the not-yet-implemented method 'GetGroupNotifyMaster'
		// Here lies the not-yet-implemented method 'ForceGroupRelativePosition'
		// Here lies the not-yet-implemented method 'GetGroupRelativePosition'
		// Here lies the not-yet-implemented method 'SetGroupRateScale'
		// Here lies the not-yet-implemented method 'GetGroupRateScale'
		// Here lies the not-yet-implemented method 'GetGroupIndex'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
