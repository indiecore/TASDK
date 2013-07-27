#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
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
namespace UnrealScript
{
	class TrCollisionProxy : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<class Pawn*>, m_NearByPawns, 476)
		ADD_BOOL(m_bTrackLocallyControlledPawnsOnly, 488, 0x20)
		ADD_BOOL(m_bForwardOwnerOnly, 488, 0x10)
		ADD_BOOL(m_bIgnoreInvulnerablePlayers, 488, 0x8)
		ADD_BOOL(m_bIgnoreHackedPawns, 488, 0x4)
		ADD_BOOL(m_bIgnoreNonPlayers, 488, 0x2)
		ADD_BOOL(m_bIgnoreStealthPlayers, 488, 0x1)
		void TouchOther(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74500);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceProximityScan(float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74503);
			byte params[4] = { NULL };
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74506);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74512);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldIgnoreActor(class Actor* Actor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74515);
			byte params[8] = { NULL };
			*(class Actor**)params = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ForceClearNearByPawnsList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74518);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74520);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckNearByPawns(class Pawn* aPawn, bool bAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74521);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			*(bool*)&params[4] = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74527);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74529);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNearByPawns(bool bOnlyValid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74531);
			byte params[8] = { NULL };
			*(bool*)params = bOnlyValid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74537);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
