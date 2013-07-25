#pragma once
#include "TribesGame.TrStation.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrPawn.h"
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
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStation.PawnEnteredStation");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStation.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStation.PlayStationEnteredEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStation.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStation.GetMarker");
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
#undef ADD_OBJECT
