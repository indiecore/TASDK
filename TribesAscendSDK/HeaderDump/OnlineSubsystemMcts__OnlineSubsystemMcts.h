#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystemMcts : public OnlineSubsystemCommonImpl
	{
	public:
		ADD_VAR(::FloatProperty, ConnectionPresenceElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConnectionPresenceTimeInterval, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct OnlineSubsystemMcts.OnlineSubsystemMcts.ControllerConnectionState' for the property named 'ControllerStates'!
		ADD_VAR(::BoolProperty, bShouldUseMcp, 0x4)
		ADD_VAR(::BoolProperty, bLastHasConnection, 0x2)
		ADD_VAR(::BoolProperty, bNeedsKeyboardTicking, 0x1)
		ADD_VAR(::StrProperty, KeyboardResultsString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileDataExtension, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileDataDirectory, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentNotificationPosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bWasKeyboardInputCanceled, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LoggedInStatus, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoggedInPlayerNum, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId' for the property named 'LoggedInPlayerId'!
		ADD_VAR(::StrProperty, LoggedInPlayerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LocalProfileName, 0xFFFFFFFF)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(OnlineGameInterfaceMcts, MctsGameInt)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
