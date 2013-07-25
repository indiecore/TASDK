#pragma once
#include "Core__Object.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrGameSettingsCommon.h"
#include "TribesGame__TrGameSearchCommon.h"
#include "Engine__OnlineSubsystem.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMakeQuickMatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMakeQuickMatch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMakeQuickMatch : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bProcessingJoin, 0x2)
		ADD_VAR(::BoolProperty, bIssuedInitialQuery, 0x1)
		ADD_OBJECT(TrGameSettingsCommon, GameSettings)
		ADD_OBJECT(TrGameSearchCommon, SearchSettings)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::FloatProperty, SearchStarted, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ControllerId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'Launch'
		// Here lies the not-yet-implemented method 'Cleanup'
		// Here lies the not-yet-implemented method 'SubmitGameSearch'
		// Here lies the not-yet-implemented method 'GetLP'
		// Here lies the not-yet-implemented method 'GetPC'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'BuildJoinURL'
		// Here lies the not-yet-implemented method 'RequestJoin'
		// Here lies the not-yet-implemented method 'OnSearchComplete'
		// Here lies the not-yet-implemented method 'OnJoinGameComplete'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
