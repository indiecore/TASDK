#pragma once
#include "Engine__AnimNodeBlendBase.h"
namespace UnrealScript
{
	class AnimNodeBlendMultiBone : public AnimNodeBlendBase
	{
	public:
		void SetTargetStartBone(int TargetIdx, ScriptName StartBoneName, float PerBoneIncrease)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendMultiBone.SetTargetStartBone");
			byte* params = (byte*)malloc(16);
			*(int*)params = TargetIdx;
			*(ScriptName*)(params + 4) = StartBoneName;
			*(float*)(params + 12) = PerBoneIncrease;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
