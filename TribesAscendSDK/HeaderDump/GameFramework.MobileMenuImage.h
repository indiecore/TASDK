#pragma once
#include "Core.Object.h"
#include "GameFramework.MobileMenuObject.h"
#include "Engine.Texture2D.h"
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
	class MobileMenuImage : public MobileMenuObject
	{
	public:
		enum MenuImageDrawStyle : byte
		{
			IDS_Normal = 0,
			IDS_Stretched = 1,
			IDS_Tile = 2,
			IDS_MAX = 3,
		};
		ADD_STRUCT(Object::LinearColor, ImageColor, 160)
		ADD_STRUCT(MobileMenuObject::UVCoords, ImageUVs, 140)
		ADD_STRUCT(MobileMenuImage::MenuImageDrawStyle, ImageDrawStyle, 136)
		ADD_OBJECT(Texture2D, Image, 132)
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuImage.RenderObject");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
