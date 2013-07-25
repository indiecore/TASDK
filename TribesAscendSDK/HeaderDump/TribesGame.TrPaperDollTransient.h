#pragma once
#include "TribesGame.TrPaperDoll.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDollTransient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPaperDollTransient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPaperDollTransient : public TrPaperDoll
	{
	public:
		ADD_VAR(::FloatProperty, m_fBackdropFadeRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropFadeTime, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_BackdropMIC)
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
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPosition(Vector ViewPos, Rotator ViewRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollTransient.SetPosition");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = ViewPos;
			*(Rotator*)(params + 12) = ViewRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
