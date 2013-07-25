#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponAttachment : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeapAnimType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AltFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FireAnim, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DistFactorForRefPose, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDecalRangeSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, BulletWhip)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultAltImpactEffect'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultImpactEffect'!
		ADD_VAR(::NameProperty, AttachmentSocket, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMakeSplash, 0x8)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x4)
		ADD_VAR(::BoolProperty, bAlignToSurfaceNormal, 0x2)
		ADD_VAR(::BoolProperty, bMuzzleFlashPSCLoops, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'MuzzleFlashColor'!
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate)
		ADD_VAR(::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
