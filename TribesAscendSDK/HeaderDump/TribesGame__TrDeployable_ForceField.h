#pragma once
#include "TribesGame__TrDeployable.h"
#include "Engine__Actor.h"
#include "Engine__Texture2D.h"
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
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'OnHealthChanged'
		// Here lies the not-yet-implemented method 'PlayDamageHealthEffects'
		// Here lies the not-yet-implemented method 'PlayHitOtherEffects'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'GetMarker'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
