#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrLaserTarget : public Actor
	{
	public:
		ADD_STRUCT(byte, m_nTeamId, 476)
		void SetTeamNum(byte TeamID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98506);
			byte params[1] = { NULL };
			*params = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98508);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void UpdateLocation(Vector NewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98510);
			byte params[12] = { NULL };
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98512);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98514);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98516);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderForOwner(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir, float Distance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98522);
			byte params[36] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			*(float*)&params[32] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderForTeammate(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir, float Distance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98533);
			byte params[36] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			*(float*)&params[32] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
