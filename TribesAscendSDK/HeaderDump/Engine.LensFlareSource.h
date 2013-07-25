#pragma once
#include "Engine.LensFlare.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlareSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LensFlareSource : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x1)
		void SetTemplate(class LensFlare* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetTemplate");
			byte* params = (byte*)malloc(4);
			*(class LensFlare**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetFloatParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetVectorParameter");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParameterName;
			*(Vector*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetColorParameter(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetColorParameter");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetExtColorParameter(ScriptName ParameterName, float Red, float Green, float Blue, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetExtColorParameter");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Red;
			*(float*)(params + 12) = Green;
			*(float*)(params + 16) = Blue;
			*(float*)(params + 20) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetActorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Actor**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
