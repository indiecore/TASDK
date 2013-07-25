#pragma once
#include "TribesGame.TrEffect.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect_Managed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffect_Managed." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffect_Managed : public TrEffect
	{
	public:
		ADD_VAR(::FloatProperty, m_fLifeTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_PawnTarget)
		void Apply(class Actor* Target, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Managed.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Managed.RemoveEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Managed.Remove");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
