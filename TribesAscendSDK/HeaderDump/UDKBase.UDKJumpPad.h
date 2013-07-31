#pragma once
#include "Engine.PathNode.h"
#include "Engine.SoundCue.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
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
	class UDKJumpPad : public NavigationPoint
	{
	public:
		ADD_STRUCT(float, JumpAirControl, 716)
		ADD_STRUCT(float, JumpTime, 712)
		ADD_OBJECT(SoundCue, JumpSound, 708)
		ADD_OBJECT(PathNode, JumpTarget, 704)
		ADD_STRUCT(Vector, JumpVelocity, 692)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34933);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34938);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34943);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
