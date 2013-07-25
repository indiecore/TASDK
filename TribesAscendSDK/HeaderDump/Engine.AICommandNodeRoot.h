#pragma once
#include "Engine.AICommandNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AICommandNodeRoot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AICommandNodeRoot : public AICommandNodeBase
	{
	public:
		ADD_VAR(::NameProperty, RootName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
