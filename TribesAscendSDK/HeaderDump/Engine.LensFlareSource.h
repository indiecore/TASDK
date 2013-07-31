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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19323);
			byte params[4] = { NULL };
			*(class LensFlare**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19325);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19326);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19328);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19330);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19333);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Vector*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorParameter(ScriptName ParameterName, Object::LinearColor Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19336);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::LinearColor*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExtColorParameter(ScriptName ParameterName, float Red, float Green, float Blue, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19339);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Red;
			*(float*)&params[12] = Green;
			*(float*)&params[16] = Blue;
			*(float*)&params[20] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19345);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Actor**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
