#pragma once
#include "Engine__BookMark2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KismetBookMark." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KismetBookMark : public BookMark2D
	{
	public:
		ADD_VAR(::StrProperty, BookMarkSequencePathName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
