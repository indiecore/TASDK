#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleWeapon_HavocPilot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon_HavocPilot : public TrVehicleWeapon_BurstShot
	{
	public:
		ADD_OBJECT(TrEffect_MovableDecal, m_BombMarkerDecal)
		ADD_OBJECT(MaterialInstanceConstant, m_BombMarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_BombMarkerTemplate)
	};
}
#undef ADD_OBJECT
