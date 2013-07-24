#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrReticules." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrReticules." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_nCurrentReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bVisible, 0x1)
		ADD_VAR(::FloatProperty, LastReticuleDepth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAccuracy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastCrossMode, 0xFFFFFFFF)
		ADD_OBJECT(Weapon, LastWeapon)
		ADD_OBJECT(GFxObject, ActiveReticule)
		ADD_OBJECT(GFxObject, ReticulesMC)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GfxTrHud, HUD)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
