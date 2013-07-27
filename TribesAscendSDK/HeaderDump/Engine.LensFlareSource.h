#pragma once
#include "Core.Object.h"
#include "Engine.LensFlare.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
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
namespace UnrealScript
{
	class LensFlareSource : public Actor
	{
	public:
		ADD_BOOL(bCurrentlyActive, 480, 0x1)
		void SetTemplate(class LensFlare* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetTemplate");
			byte params[4] = { NULL };
			*(class LensFlare**)&params[0] = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetFloatParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(float*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameter(ScriptName ParameterName, Object::Vector Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetVectorParameter");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(Object::Vector*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorParameter(ScriptName ParameterName, Object::LinearColor Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetColorParameter");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(Object::LinearColor*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExtColorParameter(ScriptName ParameterName, float Red, float Green, float Blue, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetExtColorParameter");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(float*)&params[8] = Red;
			*(float*)&params[12] = Green;
			*(float*)&params[16] = Blue;
			*(float*)&params[20] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareSource.SetActorParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(class Actor**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
