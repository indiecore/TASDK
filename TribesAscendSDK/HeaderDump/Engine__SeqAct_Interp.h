#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_Interp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_Interp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_Interp." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_Interp : public SeqAct_Latent
	{
	public:
			void AddPlayerToDirectorTracks( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_Interp.AddPlayerToDirectorTracks" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bReversePlayback, 0x80 )
			ADD_VAR( ::BoolProperty, bNoResetOnRewind, 0x20 )
			ADD_VAR( ::BoolProperty, bRewindOnPlay, 0x10 )
			ADD_VAR( ::BoolProperty, bIsPlaying, 0x1 )
			ADD_VAR( ::BoolProperty, bPaused, 0x2 )
			ADD_VAR( ::FloatProperty, PlayRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Position, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TerminationTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreferredSplitScreenNum, 0xFFFFFFFF )
			ADD_OBJECT( MatineeActor, ReplicatedActor )
			ADD_OBJECT( ScriptClass, ReplicatedActorClass )
			ADD_OBJECT( InterpData, InterpData )
			ADD_VAR( ::BoolProperty, bShouldShowGore, 0x4000 )
			ADD_VAR( ::BoolProperty, bIsSkippable, 0x2000 )
			ADD_VAR( ::BoolProperty, bSkipUpdateIfNotVisible, 0x1000 )
			ADD_VAR( ::BoolProperty, bClientSideOnly, 0x800 )
			ADD_VAR( ::BoolProperty, bDisableRadioFilter, 0x400 )
			ADD_VAR( ::BoolProperty, bForceStartPos, 0x200 )
			ADD_VAR( ::BoolProperty, bInterpForPathBuilding, 0x100 )
			ADD_VAR( ::BoolProperty, bRewindIfAlreadyPlaying, 0x40 )
			ADD_VAR( ::BoolProperty, bLooping, 0x8 )
			ADD_VAR( ::BoolProperty, bIsBeingEdited, 0x4 )
			ADD_VAR( ::FloatProperty, ForceStartPosition, 0xFFFFFFFF )
			void SetPosition( float NewPosition, bool bJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_Interp.SetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = NewPosition;
				*( bool* )( params + 4 ) = bJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Stop(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_Interp.Stop" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_Interp.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_Interp.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
