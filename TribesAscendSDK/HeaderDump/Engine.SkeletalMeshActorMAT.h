#pragma once
#include "Engine.SkeletalMeshCinematicActor.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.Actor.h"
#include "Engine.InterpGroup.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkeletalMeshActorMAT : public SkeletalMeshCinematicActor
	{
	public:
		ADD_STRUCT(ScriptArray<class AnimNodeSlot*>, SlotNodes, 536)
		void MAT_SetAnimWeights(ScriptArray<Actor::AnimSlotInfo> SlotInfos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26761);
			byte params[12] = { NULL };
			*(ScriptArray<Actor::AnimSlotInfo>*)params = SlotInfos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26764);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26767);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26770);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26771);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CacheAnimNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26773);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearAnimNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26775);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26776);
			byte params[36] = { NULL };
			*(ScriptName*)params = SlotName;
			*(int*)&params[8] = ChannelIndex;
			*(ScriptName*)&params[12] = InAnimSeqName;
			*(float*)&params[20] = InPosition;
			*(bool*)&params[24] = bFireNotifies;
			*(bool*)&params[28] = bLooping;
			*(bool*)&params[32] = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26784);
			byte params[36] = { NULL };
			*(ScriptName*)params = SlotName;
			*(int*)&params[8] = ChannelIndex;
			*(ScriptName*)&params[12] = InAnimSeqName;
			*(float*)&params[20] = InPosition;
			*(bool*)&params[24] = bFireNotifies;
			*(bool*)&params[28] = bLooping;
			*(bool*)&params[32] = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26792);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26794);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26797);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
