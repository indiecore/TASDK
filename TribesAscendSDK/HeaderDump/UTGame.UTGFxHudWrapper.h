#pragma once
#include "UTGame.UTHUDBase.h"
#include "UTGame.GFxMinimapHud.h"
#include "UTGame.GFxProjectedUI.h"
#include "Core.Object.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTGFxHudWrapper : public UTHUDBase
	{
	public:
		ADD_OBJECT(ScriptClass, MinimapHUDClass, 1532)
		ADD_OBJECT(GFxProjectedUI, InventoryMovie, 1528)
		ADD_OBJECT(GFxMinimapHud, HudMovie, 1524)
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47814);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47815);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47816);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateHUDMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47817);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLocalPlayerOwnerIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47818);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SetVisible(bool bNewVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47820);
			byte params[4] = { NULL };
			*(bool*)params = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47822);
			byte params[20] = { NULL };
			*(Vector*)params = HitDir;
			*(int*)&params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseOtherMenus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47826);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47827);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47829);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, ScriptString* CriticalString, int Switch, float Position, float Lifetime, int FontSize, Object::Color DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47836);
			byte params[48] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			*(ScriptString**)&params[12] = CriticalString;
			*(int*)&params[24] = Switch;
			*(float*)&params[28] = Position;
			*(float*)&params[32] = Lifetime;
			*(int*)&params[36] = FontSize;
			*(Object::Color*)&params[40] = DrawColor;
			*(class Object**)&params[44] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddConsoleMessage(ScriptString* M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47848);
			byte params[24] = { NULL };
			*(ScriptString**)params = M;
			*(ScriptClass**)&params[12] = InMessageClass;
			*(class PlayerReplicationInfo**)&params[16] = PRI;
			*(float*)&params[20] = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CompleteCloseInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47853);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteCloseTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47854);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
