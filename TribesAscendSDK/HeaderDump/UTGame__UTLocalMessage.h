#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTLocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTLocalMessage : public LocalMessage
	{
	public:
		ADD_VAR(::FloatProperty, AnnouncementVolume, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowPortrait, 0x1)
		ADD_VAR(::FloatProperty, AnnouncementDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AnnouncementPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MessageArea, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
