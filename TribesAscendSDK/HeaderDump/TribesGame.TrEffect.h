#pragma once
#include "Engine.Actor.ImpactInfo.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffect : public Object
	{
	public:
		ADD_OBJECT(ScriptClass, m_EffectFormClass)
		ADD_VAR(::FloatProperty, m_fValue, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRemovable, 0x1)
		ADD_VAR(::ByteProperty, m_eCalcMethodCode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nEffectInstanceId, 0xFFFFFFFF)
		void Apply(class Actor* Target, ImpactInfo Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(ImpactInfo*)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect.Remove");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanBeApplied(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect.CanBeApplied");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
