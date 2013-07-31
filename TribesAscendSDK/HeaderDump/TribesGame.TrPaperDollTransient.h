#pragma once
#include "TribesGame.TrPaperDoll.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrPaperDollTransient : public TrPaperDoll
	{
	public:
		ADD_STRUCT(float, m_fBackdropFadeRemainingTime, 916)
		ADD_STRUCT(float, m_fBackdropFadeTime, 912)
		ADD_OBJECT(MaterialInstanceConstant, m_BackdropMIC, 908)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100548);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInBackdrop()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100551);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100552);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPosition(Vector ViewPos, Rotator ViewRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100556);
			byte params[24] = { NULL };
			*(Vector*)params = ViewPos;
			*(Rotator*)&params[12] = ViewRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
