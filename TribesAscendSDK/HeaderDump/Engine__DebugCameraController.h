#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DebugCameraController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DebugCameraController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DebugCameraController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DebugCameraController : public PlayerController
	{
	public:
			ADD_OBJECT( Player, OryginalPlayer )
			ADD_OBJECT( PlayerController, OryginalControllerRef )
			ADD_OBJECT( Actor, SelectedActor )
			ADD_VAR( ::BoolProperty, bIsFrozenRendering, 0x2 )
			ADD_VAR( ::BoolProperty, bShowSelectedInfo, 0x1 )
			ADD_VAR( ::NameProperty, UnselectKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SecondaryKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PrimaryKey, 0xFFFFFFFF )
			void PrimarySelect( Vector HitLoc, Vector HitNormal, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.PrimarySelect" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( Vector* )params = HitLoc;
				*( Vector* )( params + 12 ) = HitNormal;
				*( void** )( params + 24 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SecondarySelect( Vector HitLoc, Vector HitNormal, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.SecondarySelect" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( Vector* )params = HitLoc;
				*( Vector* )( params + 12 ) = HitNormal;
				*( void** )( params + 24 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Unselect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.Unselect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnActivate( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.OnActivate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ConsoleCommand( ScriptArray< wchar_t > Command, bool bWriteToLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( bool* )( params + 12 ) = bWriteToLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void OnDeactivate( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.OnDeactivate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableDebugCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.DisableDebugCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NativeInputKey( int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraController.NativeInputKey" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )params = ControllerId;
				*( ScriptName* )( params + 4 ) = Key;
				*( byte* )( params + 12 ) = Event;
				*( float* )( params + 16 ) = AmountDepressed;
				*( bool* )( params + 20 ) = bGamepad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
