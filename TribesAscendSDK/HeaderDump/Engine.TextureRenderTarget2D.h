#pragma once
#include "Engine.TextureRenderTarget.h"
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureRenderTarget2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TextureRenderTarget2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTarget2D : public TextureRenderTarget
	{
	public:
		ADD_VAR(::BoolProperty, bForceLinearGamma, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ClearColor, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressY, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressX, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		class TextureRenderTarget2D* Create(int InSizeX, int InSizeY, byte InFormat, LinearColor InClearColor, bool bOnlyRenderOnce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureRenderTarget2D.Create");
			byte* params = (byte*)malloc(33);
			*(int*)params = InSizeX;
			*(int*)(params + 4) = InSizeY;
			*(params + 8) = InFormat;
			*(LinearColor*)(params + 12) = InClearColor;
			*(bool*)(params + 28) = bOnlyRenderOnce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TextureRenderTarget2D**)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
