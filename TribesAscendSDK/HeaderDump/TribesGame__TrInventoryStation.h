#pragma once
#include "Engine__Texture2D.h"
#include "TribesGame__TrStation.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrInventoryStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrInventoryStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrInventoryStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrInventoryStation : public TrStation
	{
	public:
		ADD_OBJECT(TrPawn, m_PawnToRefresh)
		ADD_VAR(::BoolProperty, m_bForceHealthRegen, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_PowerOffColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_PowerOnColor'!
		ADD_VAR(::FloatProperty, m_fStationReleaseTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStationAnimTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PawnEnteredStation'
		// Here lies the not-yet-implemented method 'OnPowerStatusChanged'
		// Here lies the not-yet-implemented method 'PlayStationEnteredEffects'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'GetMarker'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
