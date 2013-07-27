#pragma once
#include "Engine.SoundCue.h"
#include "UTGame.UTInventory.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "Engine.Pawn.h"
#include "UTGame.UTHUD.h"
#include "Engine.Canvas.h"
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
	class UTTimedPowerup : public UTInventory
	{
	public:
		ADD_STRUCT(float, PP_Scene_Desaturation, 616)
		ADD_STRUCT(Object::Vector, PP_Scene_HighLights, 604)
		ADD_STRUCT(float, WarningTime, 600)
		ADD_STRUCT(float, TransitionDuration, 596)
		ADD_STRUCT(float, TransitionTime, 592)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 576)
		ADD_STRUCT(ScriptName, PowerupStatName, 568)
		ADD_OBJECT(SoundCue, PowerupOverSound, 564)
		ADD_STRUCT(int, HudIndex, 560)
		ADD_STRUCT(float, TimeRemaining, 556)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.GivenTo");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientGivenTo");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustPPEffects(class Pawn* P, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.AdjustPPEffects");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(bool*)&params[4] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientLostItem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetTimeRemaining(float NewTimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientSetTimeRemaining");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewTimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TimeRemaingUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.TimeRemaingUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPowerup(class Canvas* Canvas, class UTHUD* HUD, float ResolutionScale, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DisplayPowerup");
			byte params[16] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(class UTHUD**)&params[4] = HUD;
			*(float*)&params[8] = ResolutionScale;
			*(float*)&params[12] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YPos = *(float*)&params[12];
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DenyPickupQuery");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void TimeExpired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.TimeExpired");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.BotDesireability");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = PickupHolder;
			*(class Pawn**)&params[4] = P;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DetourWeight");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		ScriptName GetPowerupStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.GetPowerupStatName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
