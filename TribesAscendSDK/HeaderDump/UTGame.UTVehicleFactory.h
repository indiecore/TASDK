#pragma once
#include "UDKBase.UDKVehicleFactory.h"
#include "UTGame.UTMapInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Canvas.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTVehicle.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicleFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicleFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicleFactory : public UDKVehicleFactory
	{
	public:
		ADD_VAR(::BoolProperty, bStartNeutral, 0x2)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x8)
		ADD_OBJECT(UTGameObjective, ReverseObjective)
		ADD_VAR(::BoolProperty, bForceAvoidReversing, 0x10)
		ADD_VAR(::BoolProperty, bDisabled, 0x4)
		ADD_VAR(::BoolProperty, bMayReverseSpawnDirection, 0x1)
		ADD_VAR(::FloatProperty, SpawnZOffset, 0xFFFFFFFF)
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
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* FinalColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.RenderMapIcon");
			byte* params = (byte*)malloc(28);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 12) = FinalColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Activate(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.Activate");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TriggerSpawnedEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.TriggerSpawnedEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetSpawnRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleFactory.GetSpawnRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
