#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAward." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAward : public Object
	{
	public:
		ADD_VAR(::StrProperty, Units, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TitleTier3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TitleTier2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TitleTier1, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TierLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DatabaseId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
