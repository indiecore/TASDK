#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LevelStreaming." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LevelStreaming." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LevelStreaming." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LevelStreaming : public Object
	{
	public:
			ADD_VAR( ::NameProperty, PackageName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasLoadRequestPending, 0x2 )
			ADD_VAR( ::BoolProperty, bShouldBeLoaded, 0x80 )
			ADD_VAR( ::BoolProperty, bShouldBeVisible, 0x100 )
			ADD_VAR( ::BoolProperty, bShouldBlockOnLoad, 0x200 )
			ADD_VAR( ::IntProperty, GridPosition, 0xFFFFFFFF )
			ADD_OBJECT( LevelGridVolume, EditorGridVolume )
			ADD_VAR( ::FloatProperty, LastVolumeUnloadRequestTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinTimeBetweenVolumeUnloadRequests, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsRequestingUnloadAndRemoval, 0x800 )
			ADD_VAR( ::BoolProperty, bDrawOnLevelStatusMap, 0x400 )
			ADD_VAR( ::BoolProperty, bIsFullyStatic, 0x40 )
			ADD_VAR( ::BoolProperty, bLocked, 0x20 )
			ADD_VAR( ::BoolProperty, bBoundingBoxVisible, 0x10 )
			ADD_VAR( ::BoolProperty, bShouldBeVisibleInEditor, 0x8 )
			ADD_VAR( ::BoolProperty, bHasUnloadRequestPending, 0x4 )
			ADD_VAR( ::BoolProperty, bIsVisible, 0x1 )
			ADD_STRUCT( ::VectorProperty, OldOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Offset, 0xFFFFFFFF )
			ADD_OBJECT( Level, LoadedLevel )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
