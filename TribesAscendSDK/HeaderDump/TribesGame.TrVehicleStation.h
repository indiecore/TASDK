#pragma once
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrStation.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrVehiclePad.h"
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicleStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleStation : public TrStation
	{
	public:
		ADD_OBJECT(TrAnimNodeBlendList, m_VehicleStationBlendNode)
		ADD_VAR(::FloatProperty, m_fTimeToSpawnVehicleAfterRequest, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInstigatorTeleportTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_PawnRequestingVehicle)
		ADD_OBJECT(TrVehicle, m_LastSpawnedVehicle)
		ADD_VAR(::FloatProperty, m_fSpawnTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPostSpawnLockoutTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_LastRequestedVehicleType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nSpawnSequenceEnded, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bSpawnSequenceStarted, 0x2)
		ADD_VAR(::BoolProperty, r_bIsLocked, 0x1)
		ADD_VAR(::IntProperty, r_nSpawnedVehicles, 0xFFFFFFFF)
		ADD_OBJECT(TrVehiclePad, m_VehiclePad)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrVehicleStation.VehicleSpawnInfo' for the property named 'm_SpawnList'!
		bool RequestSpawnVehicle(byte VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.RequestSpawnVehicle");
			byte* params = (byte*)malloc(5);
			*params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNumVehiclesSpawnedByType(byte VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetNumVehiclesSpawnedByType");
			byte* params = (byte*)malloc(5);
			*params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetMaxVehicleCountAllowed(byte VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetMaxVehicleCountAllowed");
			byte* params = (byte*)malloc(5);
			*params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PawnEnteredStation");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeftStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PawnLeftStation");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PlayStationEnteredEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PlayStationLeftEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRetractAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PlayRetractAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayVehiclePadDeployAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PlayVehiclePadDeployAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayVehiclePadCollapseAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PlayVehiclePadCollapseAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.SpawnVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeleportDriverToVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.TeleportDriverToVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Unlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.Unlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AbleToSpawnVehicleType(byte VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.AbleToSpawnVehicleType");
			byte* params = (byte*)malloc(5);
			*params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddVehicleToPackedList(byte VehicleType, int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.AddVehicleToPackedList");
			byte* params = (byte*)malloc(5);
			*params = VehicleType;
			*(int*)(params + 4) = Num;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.ShouldPostRenderForCaH");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
