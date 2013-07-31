#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Texture2D.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
	class TrSpottedTarget : public Actor
	{
	public:
		ADD_OBJECT(Actor, m_SpottedActor, 476)
		ADD_STRUCT(float, m_fLastSpottedTimestamp, 484)
		ADD_STRUCT(float, m_fSpottedActorDuration, 496)
		ADD_STRUCT(Object::Vector2D, m_MarkerSize, 504)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC, 500)
		ADD_STRUCT(float, m_fMarkerOpacity, 492)
		ADD_STRUCT(float, m_fMarkerZOffset, 488)
		ADD_STRUCT(byte, m_CachedTeamIndex, 480)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112559);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSpottedActor(class Actor* NewSpottedActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112561);
			byte params[4] = { NULL };
			*(class Actor**)params = NewSpottedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112563);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldRenderMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112572);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112574);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		Object::LinearColor GetMarkerColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112576);
			byte params[16] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
