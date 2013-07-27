#pragma once
#include "UDKBase.UDKVehicleFactory.h"
#include "Core.Object.h"
#include "UTGame.UTMapInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Canvas.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTVehicle.h"
#include "Engine.SeqAct_Toggle.h"
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
	class UTVehicleFactory : public UDKVehicleFactory
	{
	public:
		ADD_BOOL(bStartNeutral, 740, 0x2)
		ADD_BOOL(bKeyVehicle, 740, 0x8)
		ADD_STRUCT(ScriptArray<Object::Rotator>, InitialGunRotations, 748)
		ADD_OBJECT(UTGameObjective, ReverseObjective, 744)
		ADD_BOOL(bForceAvoidReversing, 740, 0x10)
		ADD_BOOL(bDisabled, 740, 0x4)
		ADD_BOOL(bMayReverseSpawnDirection, 740, 0x1)
		ADD_STRUCT(float, SpawnZOffset, 736)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToClosestObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.AddToClosestObjective");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.RenderMapIcon");
			byte params[28] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Activate(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.Activate");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Deactivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.Deactivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleTaken()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.VehicleTaken");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleDestroyed(class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.VehicleDestroyed");
			byte params[4] = { NULL };
			*(class UTVehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerSpawnedEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.TriggerSpawnedEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetSpawnRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.GetSpawnRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
