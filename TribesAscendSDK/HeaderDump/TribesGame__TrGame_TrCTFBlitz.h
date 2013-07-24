#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrCTFBlitz." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TrCTFBlitz." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TrCTFBlitz : public TrGame_TRCTF
	{
	public:
		ADD_VAR(::BoolProperty, m_bRotateBothFlagsOnCapture, 0x1)
		ADD_OBJECT(TrCTFBase_DiamondSword, DiamondSwordFlagStands)
		ADD_OBJECT(TrCTFBase_BloodEagle, BloodEagleFlagStands)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
