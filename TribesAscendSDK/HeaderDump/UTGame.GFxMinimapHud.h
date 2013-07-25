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
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxMinimapHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.GFxMinimapHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxMinimapHud." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMinimapHud : public GFxMoviePlayer
	{
	public:
		ADD_VAR(::BoolProperty, bIsTeamHUD, 0x1)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NormalZoomf, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurZoomf, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDrawWeaponCrosshairs, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, GRI)
		ADD_OBJECT(UTPlayerReplicationInfo, LastFlagCarrier)
		ADD_OBJECT(UTPlayerReplicationInfo, LastEnemy)
		ADD_VAR(::ByteProperty, LastFlagHome, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastAmmoCount, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, LastWeapon)
		ADD_OBJECT(UTVehicle, LastVehicle)
		ADD_OBJECT(GFxObject, MultiKillMC)
		ADD_OBJECT(GFxObject, MultiKillMsg_TF)
		ADD_OBJECT(GFxObject, MultiKillN_TF)
		ADD_OBJECT(GFxObject, HitLocMC)
		ADD_OBJECT(GFxObject, CreditsAndStreaksMC)
		ADD_OBJECT(GFxObject, OffhandsAndFlagMC)
		ADD_OBJECT(GFxObject, EnemyNameTF)
		ADD_OBJECT(GFxObject, CenterTextTF)
		ADD_OBJECT(GFxObject, CenterTextMC)
		ADD_OBJECT(GFxObject, TimeTF)
		ADD_OBJECT(GFxObject, TeamStatsMC)
		ADD_OBJECT(GFxObject, PlayerStatsMC)
		ADD_VAR(::IntProperty, NumMessages, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MessageHeight, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, LogMC)
		// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay' for the property named 'VehicleHE'!
		// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay' for the property named 'PlayerHE'!
		ADD_VAR(::FloatProperty, MinZoomf, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxZoomf, 0xFFFFFFFF)
		ADD_OBJECT(GFxMinimap, Minimap)
		ADD_OBJECT(WorldInfo, ThisWorld)
		void registerMiniMapView(class GFxMinimap* MC, float R)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.registerMiniMapView");
			byte* params = (byte*)malloc(8);
			*(class GFxMinimap**)params = MC;
			*(float*)(params + 4) = R;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAmmoCountTF(class Weapon* Wep, ScriptArray<wchar_t> Ammo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.SetAmmoCountTF");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = Wep;
			*(ScriptArray<wchar_t>*)(params + 4) = Ammo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* CreateMessageRow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.CreateMessageRow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		class GFxObject* InitMessageRow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.InitMessageRow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadHeEn(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void*& Info, ScriptArray<wchar_t> Base)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.LoadHeEn");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params = Info;
			*(ScriptArray<wchar_t>*)(params + 36) = Base;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Info = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params;
			free(params);
		}
		void UpdateHealth(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void*& Info, float NewHealth, float HealthMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.UpdateHealth");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params = Info;
			*(float*)(params + 36) = NewHealth;
			*(float*)(params + 40) = HealthMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Info = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params;
			free(params);
		}
		void UpdateEnergy(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void*& Info, float NewEnergy, float EnergyMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.UpdateEnergy");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params = Info;
			*(float*)(params + 36) = NewEnergy;
			*(float*)(params + 40) = EnergyMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Info = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params;
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.ClearStats");
			byte* params = (byte*)malloc(4);
			*(bool*)params = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.RemoveMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddMessage(ScriptArray<wchar_t> Type, ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.AddMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Type;
			*(ScriptArray<wchar_t>*)(params + 12) = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameHUD(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.UpdateGameHUD");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TickHud(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.TickHud");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleCrosshair(bool bToggle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.ToggleCrosshair");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bToggle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MinimapZoomOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.MinimapZoomOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MinimapZoomIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.MinimapZoomIn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.DisplayHit");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitDir;
			*(int*)(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowMultiKill(int N, ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.ShowMultiKill");
			byte* params = (byte*)malloc(16);
			*(int*)params = N;
			*(ScriptArray<wchar_t>*)(params + 4) = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCenterText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.SetCenterText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetRank(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.GetRank");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddDeathMessage(class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Killed, ScriptClass* Dmg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimapHud.AddDeathMessage");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = Killer;
			*(class PlayerReplicationInfo**)(params + 4) = Killed;
			*(ScriptClass**)(params + 8) = Dmg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
