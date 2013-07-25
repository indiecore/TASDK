#pragma once
#include "Engine__AnimObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNode : public AnimObject
	{
	public:
		ADD_VAR(::IntProperty, SearchTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bCachedHasRootMotion, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoneAtom' for the property named 'CachedRootMotionDelta'!
		ADD_VAR(::ByteProperty, CachedNumDesiredBones, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, NodeName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NodeTotalWeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodeCachedAtomsTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TickArrayIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodeInitTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodeTickTag, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCallScriptEventOnCeaseRelevant, 0x40)
		ADD_VAR(::BoolProperty, bCallScriptEventOnBecomeRelevant, 0x20)
		ADD_VAR(::BoolProperty, bCallScriptEventOnInit, 0x10)
		ADD_VAR(::BoolProperty, bDisableCaching, 0x8)
		ADD_VAR(::BoolProperty, bTickDuringPausedAnims, 0x4)
		ADD_VAR(::BoolProperty, bJustBecameRelevant, 0x2)
		ADD_VAR(::BoolProperty, bRelevant, 0x1)
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
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNode**)(params + 8);
			free(params);
			return returnVal;
		}
		void PlayAnim(bool bLoop, float Rate, float StartTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNode.PlayAnim");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bLoop;
			*(float*)(params + 4) = Rate;
			*(float*)(params + 8) = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_STRUCT
