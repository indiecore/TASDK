#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2NodeBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2NodeBase : public Object
	{
	public:
		ADD_VAR(::IntProperty, NodePosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
