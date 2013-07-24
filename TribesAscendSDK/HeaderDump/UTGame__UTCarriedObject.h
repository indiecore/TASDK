#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
