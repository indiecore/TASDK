#pragma once
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2DDynamic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2DDynamic : public Texture
	{
	public:
		ADD_VAR(::BoolProperty, bIsResolveTarget, 0x1)
		ADD_VAR(::IntProperty, NumMips, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		void Init(int InSizeX, int InSizeY, byte InFormat, bool InIsResolveTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DDynamic.Init");
			byte* params = (byte*)malloc(13);
			*(int*)params = InSizeX;
			*(int*)(params + 4) = InSizeY;
			*(params + 8) = InFormat;
			*(bool*)(params + 12) = InIsResolveTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2DDynamic* Create(int InSizeX, int InSizeY, byte InFormat, bool InIsResolveTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DDynamic.Create");
			byte* params = (byte*)malloc(17);
			*(int*)params = InSizeX;
			*(int*)(params + 4) = InSizeY;
			*(params + 8) = InFormat;
			*(bool*)(params + 12) = InIsResolveTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2DDynamic**)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
