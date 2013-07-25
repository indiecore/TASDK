#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimObject : public Object
	{
	public:
		ADD_VAR(::StrProperty, CategoryDesc, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OutDrawY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawWidth, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
