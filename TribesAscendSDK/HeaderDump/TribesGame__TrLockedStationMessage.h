#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrLockedStationMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrLockedStationMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrLockedStationMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundCue, DeniedSound)
		ADD_VAR(::StrProperty, Second, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Seconds, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StationLocked, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
