#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendMultiBone : public AnimNodeBlendBase
	{
	public:
		class ChildBoneBlendInfo
		{
		public:
			ADD_STRUCT(ScriptArray<float>, TargetPerBoneWeight, 0)
			ADD_STRUCT(ScriptArray<byte>, TargetRequiredBones, 36)
			ADD_STRUCT(float, OldBoneIncrease, 32)
			ADD_STRUCT(ScriptName, OldStartBone, 24)
			ADD_STRUCT(float, InitPerBoneIncrease, 20)
			ADD_STRUCT(ScriptName, InitTargetStartBone, 12)
		};
		ADD_STRUCT(ScriptArray<AnimNodeBlendMultiBone::ChildBoneBlendInfo>, BlendTargetList, 244)
		ADD_STRUCT(ScriptArray<byte>, SourceRequiredBones, 256)
		void SetTargetStartBone(int TargetIdx, ScriptName StartBoneName, float PerBoneIncrease)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendMultiBone.SetTargetStartBone");
			byte params[16] = { NULL };
			*(int*)&params[0] = TargetIdx;
			*(ScriptName*)&params[4] = StartBoneName;
			*(float*)&params[12] = PerBoneIncrease;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
