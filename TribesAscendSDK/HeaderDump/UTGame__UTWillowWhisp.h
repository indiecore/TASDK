#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWillowWhisp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWillowWhisp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTWillowWhisp : public UTReplicatedEmitter
	{
	public:
		ADD_VAR(::IntProperty, Position, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumPoints, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WayPoints, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
