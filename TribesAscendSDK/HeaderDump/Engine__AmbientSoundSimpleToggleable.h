#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AmbientSoundSimpleToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AmbientSoundSimpleToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AmbientSoundSimpleToggleable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AmbientSoundSimpleToggleable : public AmbientSoundSimple
	{
	public:
			ADD_VAR( ::FloatProperty, FadeOutVolumeLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInVolumeLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIgnoreAutoPlay, 0x4 )
			ADD_VAR( ::BoolProperty, bFadeOnToggle, 0x2 )
			ADD_VAR( ::BoolProperty, bCurrentlyPlaying, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartPlaying(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.StartPlaying" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopPlaying(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.StopPlaying" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AmbientSoundSimpleToggleable.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
