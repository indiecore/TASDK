#pragma once
#include "Engine__Interaction.h"
#include "Engine__GameUISceneClient.h"
#include "Engine__LocalPlayer.h"
#include "Engine__DataStoreClient.h"
#include "Engine__UIManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIInteraction." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIInteraction : public Interaction
	{
	public:
		ADD_OBJECT(GameUISceneClient, SceneClient)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIAxisEmulationData' for the property named 'AxisInputEmulation'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIKeyRepeatData' for the property named 'MouseButtonRepeatInfo'!
		ADD_VAR(::IntProperty, DoubleClickPixelTolerance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleClickTriggerSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MouseButtonRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AxisRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIAxisMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIJoystickDeadZone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bProcessInput, 0x1)
		ADD_OBJECT(DataStoreClient, DataStoreManager)
		ADD_OBJECT(ScriptClass, SceneClientClass)
		ADD_OBJECT(ScriptClass, UIManagerClass)
		ADD_OBJECT(UIManager, UIManager)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FCallbackEventDevice'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FGlobalDataStoreClientManager'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		// Here lies the not-yet-implemented method 'GetDataStoreClient'
		// Here lies the not-yet-implemented method 'IsLoggedIn'
		// Here lies the not-yet-implemented method 'IsGamepadConnected'
		// Here lies the not-yet-implemented method 'GetPlayerCount'
		// Here lies the not-yet-implemented method 'GetPlayerIndex'
		// Here lies the not-yet-implemented method 'GetPlayerControllerId'
		// Here lies the not-yet-implemented method 'GetLocalPlayer'
		// Here lies the not-yet-implemented method 'NotifyPlayerAdded'
		// Here lies the not-yet-implemented method 'NotifyPlayerRemoved'
		// Here lies the not-yet-implemented method 'GetLoginStatus'
		// Here lies the not-yet-implemented method 'GetLowestLoginStatusOfControllers'
		// Here lies the not-yet-implemented method 'HasLinkConnection'
		// Here lies the not-yet-implemented method 'GetLoggedInPlayerCount'
		// Here lies the not-yet-implemented method 'GetNumGuestsLoggedIn'
		// Here lies the not-yet-implemented method 'GetConnectedGamepadCount'
		// Here lies the not-yet-implemented method 'GetNATType'
		// Here lies the not-yet-implemented method 'NotifyGameSessionEnded'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
