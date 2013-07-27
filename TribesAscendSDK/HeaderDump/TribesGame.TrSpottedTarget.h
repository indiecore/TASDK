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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSpottedActor(class Actor* NewSpottedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.SetSpottedActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewSpottedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldRenderMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.ShouldRenderMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
		Object::LinearColor GetMarkerColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget.GetMarkerColor");
			byte params[16] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
