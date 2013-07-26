#pragma once
#include "Core.Object.UntypedBulkData_Mirror.h"
#include "Engine.Texture.h"
#include "Core.Object.Pointer.h"
#include "Engine.CodecMovie.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TextureMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TextureMovie." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TextureMovie : public Texture
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ReleaseCodecFence, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UntypedBulkData_Mirror>, Data, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, AutoPlay, 0x8)
		ADD_VAR(::BoolProperty, Looping, 0x4)
		ADD_VAR(::BoolProperty, Stopped, 0x2)
		ADD_VAR(::BoolProperty, Paused, 0x1)
		ADD_OBJECT(CodecMovie, Decoder)
		ADD_OBJECT(ScriptClass, DecoderClass)
		ADD_VAR(::ByteProperty, MovieStreamSource, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressY, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressX, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		void Play()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureMovie.Play");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureMovie.Pause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TextureMovie.Stop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
