#pragma once
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureFlipBook." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TextureFlipBook." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureFlipBook : public Texture2D
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ReleaseResourcesFence'!
		ADD_VAR(::FloatProperty, RenderOffsetV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RenderOffsetU, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentColumn, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentRow, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrameTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrameRate, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FBMethod, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
		ADD_VAR(::IntProperty, VerticalImages, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HorizontalImages, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x8)
		ADD_VAR(::BoolProperty, bLooping, 0x4)
		ADD_VAR(::BoolProperty, bStopped, 0x2)
		ADD_VAR(::BoolProperty, bPaused, 0x1)
		ADD_VAR(::FloatProperty, VerticalScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HorizontalScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSinceLastFrame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeIntoMovie, 0xFFFFFFFF)
		void Play()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureFlipBook.Play");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureFlipBook.Pause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureFlipBook.Stop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentFrame(int Row, int Col)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureFlipBook.SetCurrentFrame");
			byte* params = (byte*)malloc(8);
			*(int*)params = Row;
			*(int*)(params + 4) = Col;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
