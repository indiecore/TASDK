#pragma once
#include "Engine.CameraActor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrCamera_SpectatorBookmark : public CameraActor
	{
	public:
		enum ESpectatorBookmark : byte
		{
			Bookmark_BEBase = 0,
			Bookmark_DSBase = 1,
			Bookmark_CTFBEGeneratorRoom = 2,
			Bookmark_CTFDSGeneratorRoom = 3,
			Bookmark_CTFBEMidfield = 4,
			Bookmark_CTFDSMidfield = 5,
			Bookmark_CTFMapOverhead = 6,
			Bookmark_CTFBEVehiclePad = 7,
			Bookmark_CTFDSVehiclePad = 8,
			Bookmark_CTFBESpawn = 9,
			Bookmark_CTFDSSpawn = 10,
			Bookmark_CTFBESensor = 11,
			Bookmark_CTFDSSensor = 12,
			Bookmark_CTFBETurretA = 13,
			Bookmark_CTFBETurretB = 14,
			Bookmark_CTFBETurretC = 15,
			Bookmark_CTFDSTurretA = 16,
			Bookmark_CTFDSTurretB = 17,
			Bookmark_CTFDSTurretC = 18,
			Bookmark_CTFBEBackRoute = 19,
			Bookmark_CTFDSBackRoute = 20,
			Bookmark_TDMEast = 21,
			Bookmark_TDMWest = 22,
			Bookmark_TDMNorth = 23,
			Bookmark_TDMSouth = 24,
			Bookmark_TDMCenter = 25,
			Bookmark_TDMMapOverhead = 26,
			Bookmark_DdDryHigh = 27,
			Bookmark_DdDryLow = 28,
			Bookmark_DdBEWide = 29,
			Bookmark_DdDSWide = 30,
			Bookmark_DdDockHigh = 31,
			Bookmark_DdDockLow = 32,
			Bookmark_DdBEBunker = 33,
			Bookmark_DdDSBunker = 34,
			Bookmark_DdBEBackEntrance = 35,
			Bookmark_DdDSBackEntrance = 36,
			Bookmark_DNFish = 37,
			Bookmark_XFBSW = 38,
			Bookmark_XFRSW = 39,
			Bookmark_XFBERed = 40,
			Bookmark_XFDSRed = 41,
			Bookmark_XFBEBlue = 42,
			Bookmark_XFDSBlue = 43,
			Bookmark_XFBEBackstop = 44,
			Bookmark_XFDSBackstop = 45,
			Bookmark_XFBECRoom = 46,
			Bookmark_XFDSCRoom = 47,
			Bookmark_NKTower = 48,
			Bookmark_NKTunnel = 49,
			Bookmark_NKWhalebones = 50,
			Bookmark_NKMountainView = 51,
			Bookmark_NKMountainSide = 52,
			Bookmark_BTBase = 53,
			Bookmark_BTBaseInterior = 54,
			Bookmark_BTTunnelEast = 55,
			Bookmark_BTTunnelWest = 56,
			Bookmark_GenericCamera = 57,
			Bookmark_MAX = 58,
		};
		ADD_STRUCT(TrCamera_SpectatorBookmark::ESpectatorBookmark, m_BookmarkDescription, 1416)
		ADD_STRUCT(ScriptString*, BEBase, 720)
		ADD_STRUCT(ScriptString*, GenericCamera, 1404)
		ADD_STRUCT(ScriptString*, BTTunnelWest, 1392)
		ADD_STRUCT(ScriptString*, BTTunnelEast, 1380)
		ADD_STRUCT(ScriptString*, BTBaseInterior, 1368)
		ADD_STRUCT(ScriptString*, BTBase, 1356)
		ADD_STRUCT(ScriptString*, NKMountainSide, 1344)
		ADD_STRUCT(ScriptString*, NKMountainView, 1332)
		ADD_STRUCT(ScriptString*, NKWhalebones, 1320)
		ADD_STRUCT(ScriptString*, NKTunnel, 1308)
		ADD_STRUCT(ScriptString*, NKTower, 1296)
		ADD_STRUCT(ScriptString*, XFDSCRoom, 1284)
		ADD_STRUCT(ScriptString*, XFBECRoom, 1272)
		ADD_STRUCT(ScriptString*, XFDSBackstop, 1260)
		ADD_STRUCT(ScriptString*, XFBEBackstop, 1248)
		ADD_STRUCT(ScriptString*, XFDSBlue, 1236)
		ADD_STRUCT(ScriptString*, XFBEBlue, 1224)
		ADD_STRUCT(ScriptString*, XFDSRed, 1212)
		ADD_STRUCT(ScriptString*, XFBERed, 1200)
		ADD_STRUCT(ScriptString*, XFRSW, 1188)
		ADD_STRUCT(ScriptString*, XFBSW, 1176)
		ADD_STRUCT(ScriptString*, DNFish, 1164)
		ADD_STRUCT(ScriptString*, DdDSBackEntrance, 1152)
		ADD_STRUCT(ScriptString*, DdBEBackEntrance, 1140)
		ADD_STRUCT(ScriptString*, DdDSBunker, 1128)
		ADD_STRUCT(ScriptString*, DdBEBunker, 1116)
		ADD_STRUCT(ScriptString*, DdDockLow, 1104)
		ADD_STRUCT(ScriptString*, DdDockHigh, 1092)
		ADD_STRUCT(ScriptString*, DdDSWide, 1080)
		ADD_STRUCT(ScriptString*, DdBEWide, 1068)
		ADD_STRUCT(ScriptString*, DdDryLow, 1056)
		ADD_STRUCT(ScriptString*, DdDryHigh, 1044)
		ADD_STRUCT(ScriptString*, TDMMapOverhead, 1032)
		ADD_STRUCT(ScriptString*, TDMCenter, 1020)
		ADD_STRUCT(ScriptString*, TDMSouth, 1008)
		ADD_STRUCT(ScriptString*, TDMNorth, 996)
		ADD_STRUCT(ScriptString*, TDMWest, 984)
		ADD_STRUCT(ScriptString*, TDMEast, 972)
		ADD_STRUCT(ScriptString*, CTFDSBackRoute, 960)
		ADD_STRUCT(ScriptString*, CTFBEBackRoute, 948)
		ADD_STRUCT(ScriptString*, CTFDSTurretC, 936)
		ADD_STRUCT(ScriptString*, CTFDSTurretB, 924)
		ADD_STRUCT(ScriptString*, CTFDSTurretA, 912)
		ADD_STRUCT(ScriptString*, CTFBETurretC, 900)
		ADD_STRUCT(ScriptString*, CTFBETurretB, 888)
		ADD_STRUCT(ScriptString*, CTFBETurretA, 876)
		ADD_STRUCT(ScriptString*, CTFDSSensor, 864)
		ADD_STRUCT(ScriptString*, CTFBESensor, 852)
		ADD_STRUCT(ScriptString*, CTFDSSpawn, 840)
		ADD_STRUCT(ScriptString*, CTFBESpawn, 828)
		ADD_STRUCT(ScriptString*, CTFDSVehiclePad, 816)
		ADD_STRUCT(ScriptString*, CTFBEVehiclePad, 804)
		ADD_STRUCT(ScriptString*, CTFDSMidfield, 792)
		ADD_STRUCT(ScriptString*, CTFBEMidfield, 780)
		ADD_STRUCT(ScriptString*, CTFMapOverhead, 768)
		ADD_STRUCT(ScriptString*, CTFDSGeneratorRoom, 756)
		ADD_STRUCT(ScriptString*, CTFBEGeneratorRoom, 744)
		ADD_STRUCT(ScriptString*, DSBase, 732)
		ScriptString* GetDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_SpectatorBookmark.GetDescription");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_SpectatorBookmark.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_STRUCT
