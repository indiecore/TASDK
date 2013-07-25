#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__Material.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffectForm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffectForm." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffectForm : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsManaged, 0x2)
		ADD_OBJECT(Material, m_BodyMat)
		ADD_VAR(::ByteProperty, m_ePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bApplied, 0x1)
		ADD_OBJECT(SoundCue, m_SoundCue)
		ADD_OBJECT(ParticleSystem, m_PSC)
		ADD_VAR(::ByteProperty, m_eMatType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBodyMatFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBodyMatFadeInTime, 0xFFFFFFFF)
		class Material* GetOverwriteMat(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffectForm.GetOverwriteMat");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Material**)(params + 12);
			free(params);
			return returnVal;
		}
		class Material* GetMatApplyToPawn(ScriptClass* PawnClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffectForm.GetMatApplyToPawn");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = PawnClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Material**)(params + 4);
			free(params);
			return returnVal;
		}
		class Material* GetMatApplyToWeapon(ScriptClass* devClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffectForm.GetMatApplyToWeapon");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = devClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Material**)(params + 4);
			free(params);
			return returnVal;
		}
		class Material* GetMatApplyToAttachment(ScriptClass* attClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffectForm.GetMatApplyToAttachment");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = attClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Material**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
