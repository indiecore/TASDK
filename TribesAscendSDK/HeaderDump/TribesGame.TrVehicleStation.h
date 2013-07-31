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
		struct VehicleSpawnInfo
		{
		public:
			ADD_STRUCT(Rotator, m_rSpawnRotOffset, 20)
			ADD_STRUCT(Vector, m_vSpawnLocOffset, 8)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76897);
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetNumVehiclesSpawnedByType(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77814);
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetMaxVehicleCountAllowed(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77816);
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114999);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115001);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115003);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftStation(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115007);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115009);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115011);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRetractAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115012);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayVehiclePadDeployAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayVehiclePadCollapseAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115017);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeleportDriverToVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115020);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Unlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AbleToSpawnVehicleType(TrObject::EVehicleTypes VehicleType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115022);
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)params = VehicleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddVehicleToPackedList(TrObject::EVehicleTypes VehicleType, int Num)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115029);
			byte params[5] = { NULL };
			*(TrObject::EVehicleTypes*)params = VehicleType;
			*(int*)&params[4] = Num;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115034);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115036);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
