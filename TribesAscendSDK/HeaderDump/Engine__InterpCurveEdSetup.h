#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpCurveEdSetup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpCurveEdSetup : public Object
	{
	public:
		ADD_VAR(::IntProperty, ActiveTab, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
