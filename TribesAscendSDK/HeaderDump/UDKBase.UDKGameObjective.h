#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.UIRoot.h"
#include "Engine.Texture2D.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.AIController.h"
#include "Engine.Canvas.h"
#include "UDKBase.UDKPlayerController.h"
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
	class UDKGameObjective : public NavigationPoint
	{
	public:
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, ShootSpots, 692)
		ADD_STRUCT(byte, DefenderTeamIndex, 740)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 724)
		ADD_OBJECT(Texture2D, IconHudTexture, 720)
		ADD_STRUCT(Vector, HUDLocation, 708)
		ADD_BOOL(bUnderAttack, 704, 0x2)
		ADD_BOOL(bAllowOnlyShootable, 704, 0x1)
		void ObjectiveChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetBestViewTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34877);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		bool BotNearObjective(class AIController* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34879);
			byte params[8] = { NULL };
			*(class AIController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void TriggerFlagEvent(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34882);
			byte params[12] = { NULL };
			*(ScriptName*)params = EventType;
			*(class Controller**)&params[8] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34885);
			byte params[12] = { NULL };
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawIcon(class Canvas* Canvas, Vector IconLocation, float IconWidth, float IconAlpha, class UDKPlayerController* PlayerOwner, Object::LinearColor DrawColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34887);
			byte params[44] = { NULL };
			*(class Canvas**)params = Canvas;
			*(Vector*)&params[4] = IconLocation;
			*(float*)&params[16] = IconWidth;
			*(float*)&params[20] = IconAlpha;
			*(class UDKPlayerController**)&params[24] = PlayerOwner;
			*(Object::LinearColor*)&params[28] = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34894);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
