#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrack.SupportedSubTrackInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InterpTrack.SupportedSubTrackInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SupportedSubTrackInfo
	{
	public:
		ADD_VAR(::IntProperty, GroupIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SubTrackName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SupportedClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
