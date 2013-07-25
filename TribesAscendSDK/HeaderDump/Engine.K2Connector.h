#pragma once
#include "Core.Object.h"
#include "Engine.K2NodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Connector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.K2Connector." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class K2Connector : public Object
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ConnName, 0xFFFFFFFF)
		ADD_OBJECT(K2NodeBase, OwningNode)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
