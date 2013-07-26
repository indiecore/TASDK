#pragma once
#include "Engine.SoundCue.h"
#include "UTGame.UTInventory.h"
#include "Core.Object.Vector.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "UTGame.UTHUD.h"
#include "Engine.Canvas.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTimedPowerup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTimedPowerup : public UTInventory
	{
	public:
		ADD_VAR(::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, IconCoords, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PowerupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PowerupOverSound)
		ADD_VAR(::IntProperty, HudIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeRemaining, 0xFFFFFFFF)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.GivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientGivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustPPEffects(class Pawn* P, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.AdjustPPEffects");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(bool*)(params + 4) = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientLostItem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetTimeRemaining(float NewTimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.ClientSetTimeRemaining");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewTimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TimeRemaingUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.TimeRemaingUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPowerup(class Canvas* Canvas, class UTHUD* HUD, float ResolutionScale, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DisplayPowerup");
			byte* params = (byte*)malloc(16);
			*(class Canvas**)params = Canvas;
			*(class UTHUD**)(params + 4) = HUD;
			*(float*)(params + 8) = ResolutionScale;
			*(float*)(params + 12) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YPos = *(float*)(params + 12);
			free(params);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void TimeExpired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.TimeExpired");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.BotDesireability");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)(params + 4) = P;
			*(class Controller**)(params + 8) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetPowerupStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTimedPowerup.GetPowerupStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
