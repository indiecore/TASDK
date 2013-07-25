#pragma once
#include "Engine.SkeletalMeshCinematicActor.h"
#include "Engine.InterpGroup.h"
namespace UnrealScript
{
	class SkeletalMeshActorMAT : public SkeletalMeshCinematicActor
	{
	public:
		void MAT_SetAnimWeights(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* SlotInfos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.MAT_SetAnimWeights");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = SlotInfos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.MAT_SetMorphWeight");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphNodeName;
			*(float*)(params + 8) = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.MAT_SetSkelControlScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SkelControlName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CacheAnimNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.CacheAnimNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearAnimNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.ClearAnimNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.MAT_SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.SetMorphWeight");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphNodeName;
			*(float*)(params + 8) = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorMAT.SetSkelControlScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SkelControlName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
