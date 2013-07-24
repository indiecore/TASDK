#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileZoneBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileZoneBase : public SeqEvent_MobileBase
	{
	public:
		ADD_VAR(::StrProperty, TargetZoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
