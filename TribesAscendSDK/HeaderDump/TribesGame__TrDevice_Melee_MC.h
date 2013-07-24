#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Melee_MC." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Melee_MC : public TrDevice_Melee
	{
	public:
		ADD_VAR(::StrProperty, ContentDeviceClassString, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
