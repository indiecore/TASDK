#pragma once
#include "Engine.CameraActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCamera_SpectatorBookmark." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCamera_SpectatorBookmark : public CameraActor
	{
	public:
		ADD_VAR(::ByteProperty, m_BookmarkDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BEBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GenericCamera, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BTTunnelWest, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BTTunnelEast, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BTBaseInterior, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BTBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NKMountainSide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NKMountainView, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NKWhalebones, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NKTunnel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NKTower, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFDSCRoom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFBECRoom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFDSBackstop, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFBEBackstop, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFDSBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFBEBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFDSRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFBERed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFRSW, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, XFBSW, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DNFish, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDSBackEntrance, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdBEBackEntrance, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDSBunker, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdBEBunker, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDockLow, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDockHigh, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDSWide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdBEWide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDryLow, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DdDryHigh, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMMapOverhead, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMCenter, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMSouth, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMNorth, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMWest, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TDMEast, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSBackRoute, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBEBackRoute, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSTurretC, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSTurretB, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSTurretA, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBETurretC, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBETurretB, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBETurretA, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSSensor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBESensor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSSpawn, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBESpawn, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSVehiclePad, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBEVehiclePad, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSMidfield, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBEMidfield, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFMapOverhead, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFDSGeneratorRoom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CTFBEGeneratorRoom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DSBase, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_SpectatorBookmark.GetDescription");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_SpectatorBookmark.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
