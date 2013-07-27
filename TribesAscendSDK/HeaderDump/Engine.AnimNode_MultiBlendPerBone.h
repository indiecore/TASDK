#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.Pawn.h"
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
	class AnimNode_MultiBlendPerBone : public AnimNodeBlendBase
	{
	public:
		enum EWeightCheck : byte
		{
			EWC_AnimNodeSlotNotPlaying = 0,
			EWC_MAX = 1,
		};
		enum EBlendType : byte
		{
			EBT_ParentBoneSpace = 0,
			EBT_MeshSpace = 1,
			EBT_MAX = 2,
		};
		class BranchInfo
		{
		public:
			ADD_STRUCT(float, PerBoneWeightIncrease, 8)
			ADD_STRUCT(ScriptName, BoneName, 0)
		};
		class WeightNodeRule
		{
		public:
			ADD_STRUCT(int, ChildIndex, 20)
			ADD_STRUCT(AnimNode_MultiBlendPerBone::EWeightCheck, WeightCheck, 16)
			ADD_OBJECT(AnimNodeSlot, CachedSlotNode, 12)
			ADD_OBJECT(AnimNodeBlendBase, CachedNode, 8)
			ADD_STRUCT(ScriptName, NodeName, 0)
		};
		class WeightRule
		{
		public:
			ADD_STRUCT(AnimNode_MultiBlendPerBone::WeightNodeRule, SecondNode, 24)
			ADD_STRUCT(AnimNode_MultiBlendPerBone::WeightNodeRule, FirstNode, 0)
		};
		class PerBoneMaskInfo
		{
		public:
			ADD_STRUCT(ScriptArray<AnimNode_MultiBlendPerBone::BranchInfo>, BranchList, 0)
			ADD_STRUCT(ScriptArray<AnimNode_MultiBlendPerBone::WeightRule>, WeightRuleList, 20)
			ADD_STRUCT(ScriptArray<float>, PerBoneWeights, 36)
			ADD_STRUCT(ScriptArray<byte>, TransformReqBone, 48)
			ADD_STRUCT(int, TransformReqBoneIndex, 60)
			ADD_BOOL(bPendingBlend, 32, 0x4)
			ADD_BOOL(bDisableForNonLocalHumanPlayers, 32, 0x2)
			ADD_BOOL(bWeightBasedOnNodeRules, 32, 0x1)
			ADD_STRUCT(float, BlendTimeToGo, 16)
			ADD_STRUCT(float, DesiredWeight, 12)
		};
		ADD_OBJECT(Pawn, PawnOwner, 244)
		ADD_STRUCT(ScriptArray<AnimNode_MultiBlendPerBone::PerBoneMaskInfo>, MaskList, 248)
		ADD_STRUCT(AnimNode_MultiBlendPerBone::EBlendType, RotationBlendType, 260)
		void SetMaskWeight(int MaskIndex, float DesiredWeight, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode_MultiBlendPerBone.SetMaskWeight");
			byte params[12] = { NULL };
			*(int*)&params[0] = MaskIndex;
			*(float*)&params[4] = DesiredWeight;
			*(float*)&params[8] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
