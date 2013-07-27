#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_ForceField : public TrDeployable
	{
	public:
		ADD_STRUCT(float, m_LightFlashBrightness, 1564)
		ADD_STRUCT(Object::Color, m_LightFlashColor, 1560)
		ADD_STRUCT(float, m_fOutHitOtherFlashRemainingTime, 1552)
		ADD_STRUCT(float, m_fInHitOtherFlashRemainingTime, 1548)
		ADD_STRUCT(float, m_fOutHitOtherFlashTimeLength, 1544)
		ADD_STRUCT(float, m_fInHitOtherFlashTimeLength, 1540)
		ADD_STRUCT(float, m_fOutTakeHitFlashRemainingTime, 1536)
		ADD_STRUCT(float, m_fInTakeHitFlashRemainingTime, 1532)
		ADD_STRUCT(float, m_fOutTakeHitFlashTimeLength, 1528)
		ADD_STRUCT(float, m_fInTakeHitFlashTimeLength, 1524)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnHealthChanged(bool wasDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.OnHealthChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = wasDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDamageHealthEffects(int DamageAmount, int HitBoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.PlayDamageHealthEffects");
			byte params[8] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(int*)&params[4] = HitBoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayHitOtherEffects(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.PlayHitOtherEffects");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_ForceField.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
	};
}
#undef ADD_STRUCT
