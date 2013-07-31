#pragma once
#include "TribesGame.TrStationCollision.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrRepairStationCollision : public TrStationCollision
	{
	public:
		ADD_STRUCT(ScriptArray<class Pawn*>, m_NearByPawns, 484)
		int GetPawnsInStation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110595);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void CheckNearByPawns(class TrPawn* aPawn, bool bAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110597);
			byte params[8] = { NULL };
			*(class TrPawn**)params = aPawn;
			*(bool*)&params[4] = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110604);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110611);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
