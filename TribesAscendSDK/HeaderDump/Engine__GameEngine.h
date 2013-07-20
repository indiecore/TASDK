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
			class OnlineSubsystem* GetOnlineSubsystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.GetOnlineSubsystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineSubsystem** )( params + function->return_val_offset() );
			}

			class DownloadableContentManager* GetDLCManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.GetDLCManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class DownloadableContentManager** )( params + function->return_val_offset() );
			}

			class DownloadableContentEnumerator* GetDLCEnumerator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.GetDLCEnumerator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class DownloadableContentEnumerator** )( params + function->return_val_offset() );
			}

			bool CreateNamedNetDriver( ScriptName NetDriverName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.CreateNamedNetDriver" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NetDriverName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DestroyNamedNetDriver( ScriptName NetDriverName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.DestroyNamedNetDriver" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NetDriverName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class InGameAdManager* GetAdManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameEngine.GetAdManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class InGameAdManager** )( params + function->return_val_offset() );
			}

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
