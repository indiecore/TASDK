#pragma once
#include "Engine__Actor.h"
#include "UTGame__UTInventory.h"
#include "Engine__SoundCue.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "UTGame__UTHUD.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTimedPowerup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTimedPowerup : public UTInventory
	{
	public:
		ADD_VAR(::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::NameProperty, PowerupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PowerupOverSound)
		ADD_VAR(::IntProperty, HudIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeRemaining, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'GivenTo'
		// Here lies the not-yet-implemented method 'ClientGivenTo'
		// Here lies the not-yet-implemented method 'AdjustPPEffects'
		// Here lies the not-yet-implemented method 'ClientLostItem'
		// Here lies the not-yet-implemented method 'ClientSetTimeRemaining'
		// Here lies the not-yet-implemented method 'TimeRemaingUpdated'
		// Here lies the not-yet-implemented method 'DisplayPowerup'
		// Here lies the not-yet-implemented method 'DenyPickupQuery'
		// Here lies the not-yet-implemented method 'TimeExpired'
		// Here lies the not-yet-implemented method 'BotDesireability'
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'GetPowerupStatName'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
