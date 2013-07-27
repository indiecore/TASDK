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
		ADD_STRUCT(ScriptArray<Rotator>, InitialGunRotations, 748)
		ADD_OBJECT(UTGameObjective, ReverseObjective, 744)
		ADD_BOOL(bForceAvoidReversing, 740, 0x10)
		ADD_BOOL(bDisabled, 740, 0x4)
		ADD_BOOL(bMayReverseSpawnDirection, 740, 0x1)
		ADD_STRUCT(float, SpawnZOffset, 736)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49688);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToClosestObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49689);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49694);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, Object::LinearColor FinalColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49695);
			byte params[28] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(Object::LinearColor*)&params[12] = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Activate(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49701);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Deactivate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49703);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleTaken()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49706);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehicleDestroyed(class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49707);
			byte params[4] = { NULL };
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerSpawnedEvent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49709);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49710);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetSpawnRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49713);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
