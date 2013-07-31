#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrInventory.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "Engine.Pawn.h"
#include "Engine.Canvas.h"
#include "Engine.HUD.h"
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
	class TrTimedPowerup : public TrInventory
	{
	public:
		ADD_STRUCT(float, PP_Scene_Desaturation, 620)
		ADD_STRUCT(Vector, PP_Scene_HighLights, 608)
		ADD_STRUCT(float, WarningTime, 604)
		ADD_STRUCT(float, TransitionDuration, 600)
		ADD_STRUCT(float, TransitionTime, 596)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 580)
		ADD_STRUCT(ScriptName, PowerupStatName, 572)
		ADD_OBJECT(SoundCue, PowerupOverSound, 568)
		ADD_STRUCT(int, HudIndex, 564)
		ADD_STRUCT(float, TimeRemaining, 560)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113186);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113188);
			byte params[8] = { NULL };
			*(class Pawn**)params = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113191);
			byte params[8] = { NULL };
			*(class Pawn**)params = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustPPEffects(class Pawn* P, bool bRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113194);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			*(bool*)&params[4] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113197);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetTimeRemaining(float NewTimeRemaining)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113198);
			byte params[4] = { NULL };
			*(float*)params = NewTimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TimeRemaingUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113200);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPowerup(class Canvas* Canvas, class HUD* HUD, float ResolutionScale, float& YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113201);
			byte params[16] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class HUD**)&params[4] = HUD;
			*(float*)&params[8] = ResolutionScale;
			*(float*)&params[12] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YPos = *(float*)&params[12];
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113206);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void TimeExpired()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113212);
			byte params[16] = { NULL };
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)&params[4] = P;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113217);
			byte params[12] = { NULL };
			*(class Pawn**)params = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		ScriptName GetPowerupStatName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113221);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
