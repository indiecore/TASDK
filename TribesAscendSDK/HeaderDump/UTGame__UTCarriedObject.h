#pragma once
#include "Engine__SoundCue.h"
#include "UDKBase__UDKCarriedObject.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#include "Engine__Texture2D.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UTGame__UTMapInfo.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__Actor.h"
#include "UDKBase__UDKGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCarriedObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCarriedObject : public UDKCarriedObject
	{
	public:
		ADD_VAR(::NameProperty, GameObjBone3P, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, GameObjRot3P, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, GameObjOffset3P, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, GameObjRot1P, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, GameObjOffset1P, 0xFFFFFFFF
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'GoldColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BlueColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'RedColor'!
		ADD_VAR(::IntProperty, LastSeeMessageIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFlagSeeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxHighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultRadius, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, OldHolder)
		ADD_OBJECT(SoundCue, ReturnedSound)
		ADD_OBJECT(SoundCue, DroppedSound)
		ADD_OBJECT(SoundCue, PickupSound)
		ADD_OBJECT(Texture2D, IconTexture)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_OBJECT(Controller, FirstTouch)
		ADD_VAR(::FloatProperty, MaxDropTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TakenTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Holder)
		ADD_OBJECT(UTPlayerReplicationInfo, HolderPRI)
		ADD_VAR(::FloatProperty, TossDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseTeamColorForIcon, 0x4)
		ADD_VAR(::BoolProperty, bLeavingDroppedState, 0x2)
		ADD_VAR(::BoolProperty, bLastSecondSave, 0x1)
		// Here lies the not-yet-implemented method 'FlagUse'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ShouldMinimapRenderFor'
		// Here lies the not-yet-implemented method 'HighlightOnMinimap'
		// Here lies the not-yet-implemented method 'GetIconTexture'
		// Here lies the not-yet-implemented method 'DrawIcon'
		// Here lies the not-yet-implemented method 'RenderMapIcon'
		// Here lies the not-yet-implemented method 'RenderEnemyMapIcon'
		// Here lies the not-yet-implemented method 'SetHolder'
		// Here lies the not-yet-implemented method 'SendFlagMessage'
		// Here lies the not-yet-implemented method 'Score'
		// Here lies the not-yet-implemented method 'Drop'
		// Here lies the not-yet-implemented method 'SendHome'
		// Here lies the not-yet-implemented method 'KismetSendHome'
		// Here lies the not-yet-implemented method 'BroadcastReturnedMessage'
		// Here lies the not-yet-implemented method 'BroadcastDroppedMessage'
		// Here lies the not-yet-implemented method 'BroadcastTakenFromBaseMessage'
		// Here lies the not-yet-implemented method 'BroadcastTakenDroppedMessage'
		// Here lies the not-yet-implemented method 'CalcSetHome'
		// Here lies the not-yet-implemented method 'ClearHolder'
		// Here lies the not-yet-implemented method 'Position'
		// Here lies the not-yet-implemented method 'ValidHolder'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ClientReturnedHome'
		// Here lies the not-yet-implemented method 'NotReachableBy'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'GetKismetEventObjective'
		// Here lies the not-yet-implemented method 'LogTaken'
		// Here lies the not-yet-implemented method 'LogReturned'
		// Here lies the not-yet-implemented method 'LogDropped'
		// Here lies the not-yet-implemented method 'CheckTouching'
		// Here lies the not-yet-implemented method 'AutoSendHome'
		// Here lies the not-yet-implemented method 'CheckFit'
		// Here lies the not-yet-implemented method 'CheckPain'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
