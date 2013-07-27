#pragma once
#include "Engine.AnimObject.h"
#include "Engine.AnimNodeBlendBase.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class AnimNode : public AnimObject
	{
	public:
		enum ESliderType : byte
		{
			ST_1D = 0,
			ST_2D = 1,
			ST_MAX = 2,
		};
		class CurveKey
		{
		public:
			ADD_STRUCT(float, Weight, 8)
			ADD_STRUCT(ScriptName, CurveName, 0)
		};
		ADD_STRUCT(ScriptArray<class AnimNodeBlendBase*>, ParentNodes, 120)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, CachedBoneAtoms, 140)
		ADD_STRUCT(ScriptArray<AnimNode::CurveKey>, CachedCurveKeys, 196)
		ADD_STRUCT(ScriptArray<AnimNode::CurveKey>, LastUpdatedAnimMorphKeys, 212)
		ADD_STRUCT(int, SearchTag, 208)
		ADD_STRUCT(int, bCachedHasRootMotion, 192)
		ADD_STRUCT(Object::BoneAtom, CachedRootMotionDelta, 160)
		ADD_STRUCT(byte, CachedNumDesiredBones, 152)
		ADD_STRUCT(ScriptName, NodeName, 132)
		ADD_STRUCT(float, NodeTotalWeight, 116)
		ADD_STRUCT(int, NodeCachedAtomsTag, 112)
		ADD_STRUCT(int, TickArrayIndex, 108)
		ADD_STRUCT(int, NodeInitTag, 104)
		ADD_STRUCT(int, NodeTickTag, 100)
		ADD_BOOL(bCallScriptEventOnCeaseRelevant, 96, 0x40)
		ADD_BOOL(bCallScriptEventOnBecomeRelevant, 96, 0x20)
		ADD_BOOL(bCallScriptEventOnInit, 96, 0x10)
		ADD_BOOL(bDisableCaching, 96, 0x8)
		ADD_BOOL(bTickDuringPausedAnims, 96, 0x4)
		ADD_BOOL(bJustBecameRelevant, 96, 0x2)
		ADD_BOOL(bRelevant, 96, 0x1)
		void OnInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.OnInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnBecomeRelevant()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.OnBecomeRelevant");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCeaseRelevant()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.OnCeaseRelevant");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimNode* FindAnimNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.FindAnimNode");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNode**)&params[8];
		}
		void PlayAnim(bool bLoop, float Rate, float StartTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.PlayAnim");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bLoop;
			*(float*)&params[4] = Rate;
			*(float*)&params[8] = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplayAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.ReplayAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
