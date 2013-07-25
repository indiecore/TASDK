#pragma once
#include "Core__Object.h"
#include "Engine__IniLocPatcher.h"
#include "Engine__OnlineGameSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.OnlineSubsystem." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
		ADD_VAR(::StrProperty, IniLocPatcherClassName, 0xFFFFFFFF)
		ADD_OBJECT(IniLocPatcher, Patcher)
		ADD_VAR(::BoolProperty, bUseBuildIdOverride, 0x1)
		ADD_VAR(::IntProperty, BuildIdOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AsyncMinCompletionTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetDebugSpewLevel'
		// Here lies the not-yet-implemented method 'DumpVoiceRegistration'
		// Here lies the not-yet-implemented method 'DumpSessionState'
		// Here lies the not-yet-implemented method 'DumpGameSettings'
		// Here lies the not-yet-implemented method 'GetNumSupportedLogins'
		// Here lies the not-yet-implemented method 'GetBuildUniqueId'
		// Here lies the not-yet-implemented method 'StringToUniqueNetId'
		// Here lies the not-yet-implemented method 'UniqueNetIdToString'
		// Here lies the not-yet-implemented method 'GetNamedInterface'
		// Here lies the not-yet-implemented method 'SetNamedInterface'
		// Here lies the not-yet-implemented method 'SetGameChatInterface'
		// Here lies the not-yet-implemented method 'SetTitleFileInterface'
		// Here lies the not-yet-implemented method 'SetPartyChatInterface'
		// Here lies the not-yet-implemented method 'SetNewsInterface'
		// Here lies the not-yet-implemented method 'SetStatsInterface'
		// Here lies the not-yet-implemented method 'SetVoiceInterface'
		// Here lies the not-yet-implemented method 'SetContentInterface'
		// Here lies the not-yet-implemented method 'SetGameInterface'
		// Here lies the not-yet-implemented method 'SetSystemInterface'
		// Here lies the not-yet-implemented method 'SetPlayerInterfaceEx'
		// Here lies the not-yet-implemented method 'SetPlayerInterface'
		// Here lies the not-yet-implemented method 'SetAccountInterface'
		// Here lies the not-yet-implemented method 'Exit'
		// Here lies the not-yet-implemented method 'PostInit'
		// Here lies the not-yet-implemented method 'Init'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
