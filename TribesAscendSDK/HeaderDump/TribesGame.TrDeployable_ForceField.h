#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.Actor.h"
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_ForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_ForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_ForceField : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_LightFlashBrightness, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_LightFlashColor'!
		ADD_VAR(::FloatProperty, m_fOutHitOtherFlashRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInHitOtherFlashRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOutHitOtherFlashTimeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInHitOtherFlashTimeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOutTakeHitFlashRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInTakeHitFlashRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOutTakeHitFlashTimeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInTakeHitFlashTimeLength, 0xFFFFFFFF)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnHealthChanged(bool wasDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.OnHealthChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = wasDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDamageHealthEffects(int DamageAmount, int HitBoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.PlayDamageHealthEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = DamageAmount;
			*(int*)(params + 4) = HitBoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayHitOtherEffects(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.PlayHitOtherEffects");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
