#pragma once
#include "UTGame.UTHUDBase.h"
#include "UTGame.GFxMinimapHud.h"
#include "UTGame.GFxProjectedUI.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGFxHudWrapper." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGFxHudWrapper : public UTHUDBase
	{
	public:
		ADD_OBJECT(ScriptClass, MinimapHUDClass)
		ADD_OBJECT(GFxProjectedUI, InventoryMovie)
		ADD_OBJECT(GFxMinimapHud, HudMovie)
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.RemoveMovies");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateHUDMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.CreateHUDMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLocalPlayerOwnerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.GetLocalPlayerOwnerIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetVisible(bool bNewVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.SetVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.DisplayHit");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitDir;
			*(int*)(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CloseOtherMenus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.CloseOtherMenus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.ResolutionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.DrawHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, ScriptArray<wchar_t> CriticalString, int Switch, float Position, float Lifetime, int FontSize, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.LocalizedMessage");
			byte* params = (byte*)malloc(48);
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(ScriptArray<wchar_t>*)(params + 12) = CriticalString;
			*(int*)(params + 24) = Switch;
			*(float*)(params + 28) = Position;
			*(float*)(params + 32) = Lifetime;
			*(int*)(params + 36) = FontSize;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 40) = DrawColor;
			*(class Object**)(params + 44) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddConsoleMessage(ScriptArray<wchar_t> M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.AddConsoleMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = M;
			*(ScriptClass**)(params + 12) = InMessageClass;
			*(class PlayerReplicationInfo**)(params + 16) = PRI;
			*(float*)(params + 20) = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CompleteCloseInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.CompleteCloseInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteCloseTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxHudWrapper.CompleteCloseTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
