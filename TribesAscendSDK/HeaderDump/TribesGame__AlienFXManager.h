#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.AlienFXManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AlienFXManager : public Object
	{
	public:
		ADD_VAR(::ByteProperty, eLastOverlay, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, eCurrOverlay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fIntervalCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fBoundsPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fHighBounds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fLowBounds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fDamages, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fObjectiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fDamageTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBrighten, 0x8)
		ADD_VAR(::BoolProperty, bMenuOpen, 0x4)
		ADD_VAR(::BoolProperty, bLoaded, 0x2)
		ADD_VAR(::BoolProperty, bShowFX, 0x1)
		ADD_VAR(::IntProperty, nHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nTeam, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
