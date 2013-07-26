#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackFaceFX.FaceFXTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FaceFXTrackKey
	{
	public:
		ADD_VAR(::StrProperty, FaceFXSeqName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FaceFXGroupName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
