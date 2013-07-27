#pragma once
#include "TribesGame.TrObject.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrStation.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrVehiclePad.h"
#include "TribesGame.TrPawn.h"
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
	class TrVehicleStation : public TrStation
	{
	public:
		static const auto SPAWNED_VEHICLE_LIST_MASK = 0xF;
		class VehicleSpawnInfo
		{
		public:
			ADD_STRUCT(Object::Rotator, m_rSpawnRotOffset, 20)
			ADD_STRUCT(Object::Vector, m_vSpawnLocOffset, 8)
			ADD_STRUCT(int, m_nMaxCount, 4)
			ADD_OBJECT(ScriptClass, m_VehicleClass, 0)
		};
		ADD_OBJECT(TrAnimNodeBlendList, m_VehicleStationBlendNode, 1596)
		ADD_STRUCT(float, m_fTimeToSpawnVehicleAfterRequest, 1592)
		ADD_STRUCT(float, m_fInstigatorTeleportTime, 1588)
		ADD_OBJECT(TrPawn, m_PawnRequestingVehicle, 1584)
		ADD_OBJECT(TrVehicle, m_LastSpawnedVehicle, 1580)
		ADD_STRUCT(float, m_fSpawnTimeStamp, 1576)
		ADD_STRUCT(float, m_fPostSpawnLockoutTime, 1572)
		ADD_STRUCT(TrObject::EVehicleTypes, m_LastRequestedVehicleType, 1569)
		ADD_STRUCT(byte, r_nSpawnSequenceEnded, 1568)
		ADD_BOOL(r_bSpawnSequenceStarted, 1564, 0x2)
		ADD_BOOL(r_bIsLocked, 1564, 0x1)
		ADD_STRUCT(int, r_nSpawnedVehicles, 1560)
		ADD_OBJECT(TrVehiclePad, m_VehiclePad, 1556)
		ADD_STRUCT(TrVehicleStation::VehicleSpawnInfo, m_SpawnList, 1396)
		bool RequestSpawnVehicle(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.RequestSpawnVehicle");
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)&params[0] = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetNumVehiclesSpawnedByType(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetNumVehiclesSpawnedByType");
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)&params[0] = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetMaxVehicleCountAllowed(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetMaxVehicleCountAllowed");
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)&params[0] = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PawnEnteredStation");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.PawnLeftStation");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		bool AbleToSpawnVehicleType(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.AbleToSpawnVehicleType");
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)&params[0] = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddVehicleToPackedList(TrObject::EVehicleTypes VehicleType, int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.AddVehicleToPackedList");
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)&params[0] = VehicleType;
			*(int*)&params[4] = Num;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleStation.ShouldPostRenderForCaH");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
