#pragma once
#include "Engine__SkelControlBase.h"
namespace UnrealScript
{
	class UDKSkelControl_MassBoneScaling : public SkelControlBase
	{
	public:
		void SetBoneScale(ScriptName BoneName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKSkelControl_MassBoneScaling.SetBoneScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetBoneScale(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKSkelControl_MassBoneScaling.GetBoneScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
