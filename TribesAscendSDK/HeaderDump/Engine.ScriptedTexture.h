#pragma once
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ScriptedTexture." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScriptedTexture : public TextureRenderTarget2D
	{
	public:
		ADD_VAR(::BoolProperty, bSkipNextClear, 0x2)
		ADD_VAR(::BoolProperty, bNeedsUpdate, 0x1)
		void Render(class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ScriptedTexture.Render");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
