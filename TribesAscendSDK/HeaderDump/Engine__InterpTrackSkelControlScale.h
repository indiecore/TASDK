#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackSkelControlScale." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackSkelControlScale : public InterpTrackFloatBase
	{
	public:
		ADD_VAR(::NameProperty, SkelControlName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
