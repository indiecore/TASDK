#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.SkelControlBase.h"
#include "Core.Object.Vector.h"
#include "Engine.SkeletalMesh.h"
#include "Core.Object.Rotator.h"
#include "Engine.StaticMesh.h"
#include "Engine.MorphNodeBase.h"
#include "Engine.AnimNodeSequence.h"
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
		ADD_STRUCT(::VectorProperty, PreviewFloorPos, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, PreviewCamRot, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreviewCamPos, 0xFFFFFFFF)
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
		class SkelControlBase* FindSkelControl(ScriptName InControlName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.FindSkelControl");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InControlName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkelControlBase**)(params + 8);
			free(params);
			return returnVal;
		}
		class MorphNodeBase* FindMorphNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.FindMorphNode");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MorphNodeBase**)(params + 8);
			free(params);
			return returnVal;
		}
		void SetUseSavedPose(bool bUseSaved)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.SetUseSavedPose");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUseSaved;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetAnimGroupForNode(class AnimNodeSequence* SeqNode, ScriptName GroupName, bool bCreateIfNotFound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.SetAnimGroupForNode");
			byte* params = (byte*)malloc(20);
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)(params + 4) = GroupName;
			*(bool*)(params + 12) = bCreateIfNotFound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		class AnimNodeSequence* GetGroupSynchMaster(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.GetGroupSynchMaster");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)(params + 8);
			free(params);
			return returnVal;
		}
		class AnimNodeSequence* GetGroupNotifyMaster(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.GetGroupNotifyMaster");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)(params + 8);
			free(params);
			return returnVal;
		}
		void ForceGroupRelativePosition(ScriptName GroupName, float RelativePosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.ForceGroupRelativePosition");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			*(float*)(params + 8) = RelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetGroupRelativePosition(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.GetGroupRelativePosition");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetGroupRateScale(ScriptName GroupName, float NewRateScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.SetGroupRateScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			*(float*)(params + 8) = NewRateScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetGroupRateScale(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.GetGroupRateScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetGroupIndex(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimTree.GetGroupIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
