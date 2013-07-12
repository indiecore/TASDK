#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTGameObjective." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTGameObjective." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTGameObjective." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameObjective : public UDKGameObjective
	{
	public:
			ADD_VAR( ::BoolProperty, bAllowRemoteUse, 0x2 )
			ADD_VAR( ::FloatProperty, MaxBeaconDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinimapIconScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighlightSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxHighlightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighlightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraViewDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSensorRange, 0xFFFFFFFF )
			ADD_OBJECT( Material, HudMaterial )
			ADD_VAR( ::FloatProperty, IconExtentY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconExtentX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconPosY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconPosX, 0xFFFFFFFF )
			ADD_OBJECT( UTGameObjective, NextObjective )
			ADD_VAR( ::IntProperty, Score, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseRadius, 0xFFFFFFFF )
			ADD_OBJECT( Volume, MyBaseVolume )
			ADD_VAR( ::StrProperty, ObjectiveName, 0xFFFFFFFF )
			ADD_OBJECT( UTDefensePoint, DefensePoints )
			ADD_OBJECT( UTSquadAI, DefenseSquad )
			ADD_VAR( ::ByteProperty, DefensePriority, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StartTeam, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bScriptRenderAdditionalMinimap, 0x200 )
			ADD_VAR( ::BoolProperty, bHasLocationSpeech, 0x100 )
			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x80 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x40 )
			ADD_VAR( ::BoolProperty, bIsDisabled, 0x20 )
			ADD_VAR( ::BoolProperty, bIsConstructing, 0x10 )
			ADD_VAR( ::BoolProperty, bHasSensor, 0x8 )
			ADD_VAR( ::BoolProperty, bFirstObjective, 0x4 )
			ADD_VAR( ::BoolProperty, bAlreadyRendered, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
