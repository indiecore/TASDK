#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeSequence.h"
namespace UnrealScript
{
	class AnimNodeSynch : public AnimNodeBlendBase
	{
	public:
		void AddNodeToGroup(class AnimNodeSequence* SeqNode, ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.AddNodeToGroup");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)(params + 4) = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveNodeFromGroup(class AnimNodeSequence* SeqNode, ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.RemoveNodeFromGroup");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)(params + 4) = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class AnimNodeSequence* GetMasterNodeOfGroup(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.GetMasterNodeOfGroup");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)(params + 8);
			free(params);
			return returnVal;
		}
		void ForceRelativePosition(ScriptName GroupName, float RelativePosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.ForceRelativePosition");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			*(float*)(params + 8) = RelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetRelativePosition(ScriptName GroupName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.GetRelativePosition");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetGroupRateScale(ScriptName GroupName, float NewRateScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSynch.SetGroupRateScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			*(float*)(params + 8) = NewRateScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
