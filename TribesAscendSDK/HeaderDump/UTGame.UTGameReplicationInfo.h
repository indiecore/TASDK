#pragma once
#include "Engine.GameReplicationInfo.h"
#include "Engine.MaterialInterface.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPlayerController.h"
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
	class UTGameReplicationInfo : public GameReplicationInfo
	{
	public:
		enum EFlagState : byte
		{
			FLAG_Home = 0,
			FLAG_HeldFriendly = 1,
			FLAG_HeldEnemy = 2,
			FLAG_Down = 3,
			FLAG_MAX = 4,
		};
		struct MeshEffect
		{
		public:
			ADD_OBJECT(StaticMesh, Mesh, 0)
			ADD_OBJECT(MaterialInterface, Material, 4)
		};
		ADD_BOOL(bStoryMode, 568, 0x4)
		ADD_BOOL(bAnnouncementsDisabled, 568, 0x20)
		ADD_STRUCT(ScriptString*, MessageOfTheDay, 624)
		ADD_STRUCT(ScriptArray<UTGameReplicationInfo::MeshEffect>, VehicleWeaponEffects, 612)
		ADD_BOOL(bConsoleServer, 568, 0x8)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, WeaponOverlays, 600)
		ADD_BOOL(bAllowKeyboardAndMouse, 568, 0x10)
		ADD_STRUCT(int, BotDifficulty, 564)
		ADD_STRUCT(int, MinNetPlayers, 560)
		ADD_BOOL(bRequireReady, 568, 0x40)
		ADD_STRUCT(ScriptString*, MutatorList, 576)
		ADD_STRUCT(ScriptString*, RulesString, 588)
		ADD_BOOL(bWarmupRound, 568, 0x1)
		ADD_STRUCT(UTGameReplicationInfo::EFlagState, FlagState, 572)
		ADD_STRUCT(float, WeaponBerserk, 556)
		ADD_BOOL(bForceDefaultCharacter, 568, 0x2)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46039);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InOrder(class PlayerReplicationInfo* P1, class PlayerReplicationInfo* P2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46048);
			byte params[12] = { NULL };
			*(class PlayerReplicationInfo**)params = P1;
			*(class PlayerReplicationInfo**)&params[4] = P2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SortPRIArray()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46054);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CharacterProcessingComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46059);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlagHome(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46061);
			byte params[4] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FlagIsHome(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46064);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FlagsAreHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46067);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetFlagHeldFriendly(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46069);
			byte params[4] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FlagIsHeldFriendly(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46071);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetFlagHeldEnemy(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46074);
			byte params[4] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FlagIsHeldEnemy(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46076);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetFlagDown(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46079);
			byte params[4] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FlagIsDown(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46081);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46084);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMidGameMenu(class UTPlayerController* InstigatorPC, ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46087);
			byte params[16] = { NULL };
			*(class UTPlayerController**)params = InstigatorPC;
			*(ScriptName*)&params[4] = TabTag;
			*(bool*)&params[12] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHudShowScores(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46091);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddGameRule(ScriptString* Rule)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46094);
			byte params[12] = { NULL };
			*(ScriptString**)params = Rule;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
