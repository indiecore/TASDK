#pragma once
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Texture2D.TextureLinkedListMirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureLinkedListMirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, PrevLink, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Next, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Element, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
