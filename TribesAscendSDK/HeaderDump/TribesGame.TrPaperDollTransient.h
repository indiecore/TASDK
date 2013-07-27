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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollTransient.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInBackdrop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollTransient.FadeInBackdrop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollTransient.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPosition(Object::Vector ViewPos, Object::Rotator ViewRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollTransient.SetPosition");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = ViewPos;
			*(Object::Rotator*)&params[12] = ViewRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
