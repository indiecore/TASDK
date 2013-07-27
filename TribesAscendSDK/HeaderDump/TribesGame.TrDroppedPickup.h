#pragma once
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Pawn.h"
#include "UTGame.UTDroppedPickup.h"
#include "Engine.Canvas.h"
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.SoundCue.h"
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
	class TrDroppedPickup : public UTDroppedPickup
	{
	public:
		ADD_BOOL(m_bHasHitObjective, 556, 0x1)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxy, 552)
		ADD_STRUCT(float, m_fMarkerOpacity, 548)
		ADD_STRUCT(float, m_fCurrentMarkerTime, 544)
		ADD_STRUCT(Rotator, m_rMarkerRot, 532)
		ADD_STRUCT(float, m_fMarkerBlinkSpeed, 528)
		ADD_STRUCT(float, m_fMarkerScale, 524)
		ADD_STRUCT(float, m_fMarkerZOffset, 520)
		ADD_STRUCT(float, m_PctAmmoToRefill, 516)
		ADD_OBJECT(SoundCue, m_AmmoPickupSound, 512)
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87023);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87024);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87026);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoBounce(class Actor* Other, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87028);
			byte params[16] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87031);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCollisionProxyTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87035);
			byte params[4] = { NULL };
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87060);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87062);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
