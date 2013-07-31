#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "GFxUI.GFxObject.h"
#include "Engine.WorldInfo.h"
#include "UTGame.UTWeapon.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTVehicle.h"
#include "Engine.Weapon.h"
#include "UTGame.GFxMinimap.h"
#include "Engine.LocalPlayer.h"
#include "Core.Object.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxMinimapHud : public GFxMoviePlayer
	{
	public:
		struct MessageRow
		{
		public:
			ADD_STRUCT(int, Y, 12)
			ADD_STRUCT(float, StartFadeTime, 8)
			ADD_OBJECT(GFxObject, TF, 4)
			ADD_OBJECT(GFxObject, MC, 0)
		};
		struct HeEnDisplay
		{
		public:
			ADD_OBJECT(GFxObject, EnergyBarMC, 32)
			ADD_OBJECT(GFxObject, EnergyTF, 28)
			ADD_BOOL(HealthNormOn, 24, 0x1)
			ADD_OBJECT(GFxObject, HealthCritMC, 20)
			ADD_OBJECT(GFxObject, HealthNormMC, 16)
			ADD_OBJECT(GFxObject, HealthBarMC, 12)
			ADD_OBJECT(GFxObject, HealthTF, 8)
			ADD_STRUCT(float, LastEnergy, 4)
			ADD_STRUCT(float, LastHealth, 0)
		};
		ADD_BOOL(bIsTeamHUD, 632, 0x1)
		ADD_STRUCT(float, Radius, 388)
		ADD_STRUCT(float, NormalZoomf, 396)
		ADD_STRUCT(float, CurZoomf, 392)
		ADD_STRUCT(ScriptArray<GFxMinimapHud::MessageRow>, Messages, 484)
		ADD_STRUCT(ScriptArray<GFxMinimapHud::MessageRow>, FreeMessages, 496)
		ADD_BOOL(bDrawWeaponCrosshairs, 632, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, GRI, 628)
		ADD_OBJECT(UTPlayerReplicationInfo, LastFlagCarrier, 620)
		ADD_OBJECT(UTPlayerReplicationInfo, LastEnemy, 616)
		ADD_STRUCT(byte, LastFlagHome, 612)
		ADD_STRUCT(int, LastScore, 604)
		ADD_STRUCT(int, LastAmmoCount, 600)
		ADD_OBJECT(UTWeapon, LastWeapon, 596)
		ADD_OBJECT(UTVehicle, LastVehicle, 592)
		ADD_OBJECT(GFxObject, MultiKillMC, 588)
		ADD_OBJECT(GFxObject, MultiKillMsg_TF, 584)
		ADD_OBJECT(GFxObject, MultiKillN_TF, 580)
		ADD_OBJECT(GFxObject, HitLocMC, 548)
		ADD_OBJECT(GFxObject, CreditsAndStreaksMC, 544)
		ADD_OBJECT(GFxObject, OffhandsAndFlagMC, 540)
		ADD_OBJECT(GFxObject, EnemyNameTF, 536)
		ADD_OBJECT(GFxObject, CenterTextTF, 532)
		ADD_OBJECT(GFxObject, CenterTextMC, 528)
		ADD_OBJECT(GFxObject, TimeTF, 524)
		ADD_OBJECT(GFxObject, TeamStatsMC, 520)
		ADD_OBJECT(GFxObject, PlayerStatsMC, 516)
		ADD_STRUCT(int, NumMessages, 512)
		ADD_STRUCT(float, MessageHeight, 508)
		ADD_OBJECT(GFxObject, LogMC, 480)
		ADD_STRUCT(GFxMinimapHud::HeEnDisplay, VehicleHE, 444)
		ADD_STRUCT(GFxMinimapHud::HeEnDisplay, PlayerHE, 408)
		ADD_STRUCT(float, MinZoomf, 404)
		ADD_STRUCT(float, MaxZoomf, 400)
		ADD_OBJECT(GFxMinimap, Minimap, 384)
		ADD_OBJECT(WorldInfo, ThisWorld, 380)
		void registerMiniMapView(class GFxMinimap* MC, float R)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37442);
			byte params[8] = { NULL };
			*(class GFxMinimap**)params = MC;
			*(float*)&params[4] = R;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAmmoCountTF(class Weapon* Wep, ScriptString* Ammo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37445);
			byte params[16] = { NULL };
			*(class Weapon**)params = Wep;
			*(ScriptString**)&params[4] = Ammo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* CreateMessageRow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37448);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		class GFxObject* InitMessageRow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37450);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37453);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadHeEn(GFxMinimapHud::HeEnDisplay& Info, ScriptString* Base)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37457);
			byte params[48] = { NULL };
			*(GFxMinimapHud::HeEnDisplay*)params = Info;
			*(ScriptString**)&params[36] = Base;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Info = *(GFxMinimapHud::HeEnDisplay*)params;
		}
		void UpdateHealth(GFxMinimapHud::HeEnDisplay& Info, float NewHealth, float HealthMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37460);
			byte params[44] = { NULL };
			*(GFxMinimapHud::HeEnDisplay*)params = Info;
			*(float*)&params[36] = NewHealth;
			*(float*)&params[40] = HealthMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Info = *(GFxMinimapHud::HeEnDisplay*)params;
		}
		void UpdateEnergy(GFxMinimapHud::HeEnDisplay& Info, float NewEnergy, float EnergyMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37465);
			byte params[44] = { NULL };
			*(GFxMinimapHud::HeEnDisplay*)params = Info;
			*(float*)&params[36] = NewEnergy;
			*(float*)&params[40] = EnergyMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Info = *(GFxMinimapHud::HeEnDisplay*)params;
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37470);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37476);
			byte params[4] = { NULL };
			*(bool*)params = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37479);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddMessage(ScriptString* Type, ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37480);
			byte params[24] = { NULL };
			*(ScriptString**)params = Type;
			*(ScriptString**)&params[12] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameHUD(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37486);
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TickHud(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37491);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleCrosshair(bool bToggle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37503);
			byte params[4] = { NULL };
			*(bool*)params = bToggle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MinimapZoomOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37507);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MinimapZoomIn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37508);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37509);
			byte params[20] = { NULL };
			*(Vector*)params = HitDir;
			*(int*)&params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMultiKill(int N, ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37523);
			byte params[16] = { NULL };
			*(int*)params = N;
			*(ScriptString**)&params[4] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCenterText(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37526);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetRank(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37528);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void AddDeathMessage(class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Killed, ScriptClass* Dmg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37533);
			byte params[12] = { NULL };
			*(class PlayerReplicationInfo**)params = Killer;
			*(class PlayerReplicationInfo**)&params[4] = Killed;
			*(ScriptClass**)&params[8] = Dmg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
