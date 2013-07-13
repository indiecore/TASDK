#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameEngine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameEngine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameEngine." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameEngine : public Engine
	{
	public:
			ADD_OBJECT( PendingLevel, GPendingLevel )
			ADD_VAR( ::StrProperty, PendingLevelPlayerControllerClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TravelURL, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TravelType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWorldWasLoadedThisTick, 0x1 )
			ADD_VAR( ::BoolProperty, bShouldCommitPendingMapChange, 0x2 )
			ADD_VAR( ::BoolProperty, bClearAnimSetLinkupCachesOnLoadMap, 0x4 )
			ADD_OBJECT( OnlineSubsystem, OnlineSubsystem )
			ADD_OBJECT( DownloadableContentEnumerator, DLCEnumerator )
			ADD_VAR( ::StrProperty, DownloadableContentEnumeratorClassName, 0xFFFFFFFF )
			ADD_OBJECT( DownloadableContentManager, DLCManager )
			ADD_VAR( ::StrProperty, DownloadableContentManagerClassName, 0xFFFFFFFF )
			ADD_OBJECT( InGameAdManager, AdManager )
			ADD_VAR( ::StrProperty, InGameAdManagerClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PendingMapChangeFailureDescription, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDeltaTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
