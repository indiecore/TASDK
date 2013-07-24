#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_DummyWeaponFire : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x1)
		ADD_OBJECT(Actor, Target)
		ADD_STRUCT(::RotatorProperty, MaxSpread, 0xFFFFFFFF
		ADD_OBJECT(Actor, Origin)
		ADD_VAR(::IntProperty, ShotsFired, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FireMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ShotsToFire, 0xFFFFFFFF)
		ADD_OBJECT(UTDummyPawn, DummyPawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
