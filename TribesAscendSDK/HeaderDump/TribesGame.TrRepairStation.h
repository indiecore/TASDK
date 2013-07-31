#pragma once
#include "TribesGame.TrStation.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.Texture2D.h"
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
	class TrRepairStation : public TrStation
	{
	public:
		ADD_OBJECT(SkelControlSingleBone, m_RepairGunControl, 1408)
		ADD_OBJECT(TrAnimNodeBlendList, m_RepairStationBlendList, 1404)
		ADD_STRUCT(float, m_fStationOpenDelay, 1400)
		ADD_BOOL(m_bIsStationOpen, 1396, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110525);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110526);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110528);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110532);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110533);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnGrabbedRepairTool()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110534);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CloseStation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110536);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
