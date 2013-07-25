#pragma once
#include "Engine__MorphNodeBase.h"
#include "Engine__MorphTarget.h"
namespace UnrealScript
{
	class MorphNodeMultiPose : public MorphNodeBase
	{
	public:
		bool AddMorphTarget(ScriptName MorphTargetName, float InWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodeMultiPose.AddMorphTarget");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = MorphTargetName;
			*(float*)(params + 8) = InWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void RemoveMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodeMultiPose.RemoveMorphTarget");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UpdateMorphTarget(class MorphTarget* Target, float InWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodeMultiPose.UpdateMorphTarget");
			byte* params = (byte*)malloc(12);
			*(class MorphTarget**)params = Target;
			*(float*)(params + 4) = InWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
