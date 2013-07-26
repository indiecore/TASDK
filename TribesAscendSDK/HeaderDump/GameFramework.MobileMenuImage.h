#pragma once
#include "GameFramework.MobileMenuObject.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobileMenuObject.UVCoords.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileMenuImage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobileMenuImage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuImage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuImage : public MobileMenuObject
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ImageColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UVCoords>, ImageUVs, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ImageDrawStyle, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, Image)
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuImage.RenderObject");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
