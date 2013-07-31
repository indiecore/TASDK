#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.MorphNodeBase.h"
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.AnimSet.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.AnimNode.h"
#include "Engine.StaticMesh.h"
#include "Engine.SkelControlBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AnimTree : public AnimNodeBlendBase
	{
	public:
		struct AnimGroup
		{
		public:
			ADD_STRUCT(ScriptArray<class AnimNodeSequence*>, SeqNodes, 0)
			ADD_STRUCT(float, SynchPctPosition, 32)
			ADD_STRUCT(float, RateScale, 28)
			ADD_STRUCT(ScriptName, GroupName, 20)
			ADD_OBJECT(AnimNodeSequence, NotifyMaster, 16)
			ADD_OBJECT(AnimNodeSequence, SynchMaster, 12)
		};
		struct SkelControlListHead
		{
		public:
			ADD_STRUCT(int, DrawY, 12)
			ADD_OBJECT(SkelControlBase, ControlHead, 8)
			ADD_STRUCT(ScriptName, BoneName, 0)
		};
		struct PreviewSkelMeshStruct
		{
		public:
			ADD_STRUCT(ScriptArray<class MorphTargetSet*>, PreviewMorphSets, 12)
			ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 8)
			ADD_STRUCT(ScriptName, DisplayName, 0)
		};
		struct PreviewSocketStruct
		{
		public:
			ADD_OBJECT(StaticMesh, PreviewStaticMesh, 20)
			ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 16)
			ADD_STRUCT(ScriptName, SocketName, 8)
			ADD_STRUCT(ScriptName, DisplayName, 0)
		};
		struct PreviewAnimSetsStruct
		{
		public:
			ADD_STRUCT(ScriptArray<class AnimSet*>, PreviewAnimSets, 8)
			ADD_STRUCT(ScriptName, DisplayName, 0)
		};
		ADD_STRUCT(ScriptArray<AnimTree::AnimGroup>, AnimGroups, 244)
		ADD_STRUCT(ScriptArray<ScriptName>, PrioritizedSkelBranches, 256)
		ADD_STRUCT(ScriptArray<ScriptName>, ComposePrePassBoneNames, 268)
		ADD_STRUCT(ScriptArray<ScriptName>, ComposePostPassBoneNames, 280)
		ADD_STRUCT(ScriptArray<class MorphNodeBase*>, RootMorphNodes, 292)
		ADD_STRUCT(ScriptArray<AnimTree::SkelControlListHead>, SkelControlLists, 304)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, SavedPose, 316)
		ADD_STRUCT(ScriptArray<class AnimSet*>, PreviewAnimSets, 360)
		ADD_STRUCT(ScriptArray<class MorphTargetSet*>, PreviewMorphSets, 372)
		ADD_STRUCT(ScriptArray<AnimTree::PreviewSkelMeshStruct>, PreviewMeshList, 384)
		ADD_STRUCT(ScriptArray<AnimTree::PreviewSocketStruct>, PreviewSocketList, 400)
		ADD_STRUCT(ScriptArray<AnimTree::PreviewAnimSetsStruct>, PreviewAnimSetList, 416)
		ADD_STRUCT(ScriptArray<class AnimNode*>, AnimTickArray, 476)
		ADD_STRUCT(int, PreviewFloorYaw, 472)
		ADD_STRUCT(Vector, PreviewFloorPos, 460)
		ADD_STRUCT(Rotator, PreviewCamRot, 448)
		ADD_STRUCT(Vector, PreviewCamPos, 436)
		ADD_STRUCT(int, PreviewAnimSetIndex, 432)
		ADD_STRUCT(int, PreviewAnimSetListIndex, 428)
		ADD_STRUCT(int, PreviewSocketIndex, 412)
		ADD_STRUCT(int, PreviewMeshIndex, 396)
		ADD_STRUCT(ScriptName, SocketName, 352)
		ADD_OBJECT(StaticMesh, SocketStaticMesh, 348)
		ADD_OBJECT(SkeletalMesh, SocketSkelMesh, 344)
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 340)
		ADD_STRUCT(float, PreviewPlayRate, 336)
		ADD_STRUCT(int, MorphConnDrawY, 332)
		ADD_BOOL(bRebuildAnimTickArray, 328, 0x8)
		ADD_BOOL(bParentNodeArrayBuilt, 328, 0x4)
		ADD_BOOL(bBeingEdited, 328, 0x2)
		ADD_BOOL(bUseSavedPose, 328, 0x1)
		class SkelControlBase* FindSkelControl(ScriptName InControlName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11570);
			byte params[12] = { NULL };
			*(ScriptName*)params = InControlName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkelControlBase**)&params[8];
		}
		class MorphNodeBase* FindMorphNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11573);
			byte params[12] = { NULL };
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphNodeBase**)&params[8];
		}
		void SetUseSavedPose(bool bUseSaved)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11576);
			byte params[4] = { NULL };
			*(bool*)params = bUseSaved;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetAnimGroupForNode(class AnimNodeSequence* SeqNode, ScriptName GroupName, bool bCreateIfNotFound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11578);
			byte params[20] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)&params[4] = GroupName;
			*(bool*)&params[12] = bCreateIfNotFound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class AnimNodeSequence* GetGroupSynchMaster(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11583);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[8];
		}
		class AnimNodeSequence* GetGroupNotifyMaster(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11586);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[8];
		}
		void ForceGroupRelativePosition(ScriptName GroupName, float RelativePosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11589);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			*(float*)&params[8] = RelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetGroupRelativePosition(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11592);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SetGroupRateScale(ScriptName GroupName, float NewRateScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11595);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			*(float*)&params[8] = NewRateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetGroupRateScale(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11598);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		int GetGroupIndex(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11601);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
