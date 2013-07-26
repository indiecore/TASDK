#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.PawnClassEventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PawnClassEventData
	{
	public:
		ADD_VAR(::StrProperty, PawnClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
