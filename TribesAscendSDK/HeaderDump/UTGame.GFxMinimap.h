#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GFxUI.GFxObject.h"
#include "UTGame.UTMapInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.WorldInfo.h"
#include "UTGame.GFxMinimapHud.h"
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
	class GFxMinimap : public GFxObject
	{
	public:
		ADD_STRUCT(ScriptArray<class GFxObject*>, EnemyIcons, 152)
		ADD_STRUCT(ScriptArray<class GFxObject*>, MyTeamIcons, 164)
		ADD_STRUCT(ScriptArray<class GFxObject*>, FlagIcons, 176)
		ADD_STRUCT(ScriptArray<class GFxObject*>, ObjectiveIcons, 188)
		ADD_STRUCT(ScriptArray<class UTGameObjective*>, Objectives, 296)
		ADD_STRUCT(int, IconsFlagCount, 292)
		ADD_STRUCT(int, IconsBlueCount, 288)
		ADD_STRUCT(int, IconsRedCount, 284)
		ADD_OBJECT(GFxObject, IconsFlagMC, 280)
		ADD_OBJECT(GFxObject, IconsBlueMC, 276)
		ADD_OBJECT(GFxObject, IconsRedMC, 272)
		ADD_STRUCT(Object::Matrix, IconMatrix, 208)
		ADD_OBJECT(GFxObject, MapMC, 148)
		ADD_OBJECT(GFxObject, CompassIcon, 144)
		ADD_OBJECT(GFxObject, PlayerIcon, 140)
		ADD_BOOL(bNeedsUpdateData, 136, 0x1)
		ADD_STRUCT(int, MapTexSize, 132)
		ADD_OBJECT(UTMapInfo, MapInfo, 128)
		ADD_OBJECT(WorldInfo, ThisWorld, 124)
		ADD_OBJECT(GFxMinimapHud, HUD, 120)
		void Init(class GFxMinimapHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.Init");
			byte params[4] = { NULL };
			*(class GFxMinimapHud**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.UpdateData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<class GFxObject*> GenFriendIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenFriendIcons");
			byte params[16] = { NULL };
			*(int*)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class GFxObject*>*)&params[4];
		}
		ScriptArray<class GFxObject*> GenEnemyIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenEnemyIcons");
			byte params[16] = { NULL };
			*(int*)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class GFxObject*>*)&params[4];
		}
		ScriptArray<class GFxObject*> GenFlagIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenFlagIcons");
			byte params[16] = { NULL };
			*(int*)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class GFxObject*>*)&params[4];
		}
		void UpdateIcons(ScriptArray<class Actor*>& Actors, ScriptArray<class GFxObject*>& ActorIcons, bool bIsRedIconType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.UpdateIcons");
			byte params[28] = { NULL };
			*(ScriptArray<class Actor*>*)&params[0] = Actors;
			*(ScriptArray<class GFxObject*>*)&params[12] = ActorIcons;
			*(bool*)&params[24] = bIsRedIconType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actors = *(ScriptArray<class Actor*>*)&params[0];
			ActorIcons = *(ScriptArray<class GFxObject*>*)&params[12];
		}
		void Update(float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.Update");
			byte params[4] = { NULL };
			*(float*)&params[0] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
