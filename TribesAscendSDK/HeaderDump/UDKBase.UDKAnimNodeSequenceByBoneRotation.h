#pragma once
#include "Engine.AnimNodeSequence.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequenceByBoneRotation : public AnimNodeSequence
	{
	public:
		class AnimByRotation
		{
		public:
			ADD_STRUCT(ScriptName, AnimName, 12)
			ADD_STRUCT(Object::Rotator, DesiredRotation, 0)
		};
		ADD_STRUCT(ScriptArray<UDKAnimNodeSequenceByBoneRotation::AnimByRotation>, AnimList, 332)
		ADD_STRUCT(Object::EAxis, BoneAxis, 328)
		ADD_STRUCT(ScriptName, BoneName, 320)
		void OnBecomeRelevant()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequenceByBoneRotation.OnBecomeRelevant");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
