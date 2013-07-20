#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamHUD." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamHUD : public UTHUD
	{
	public:
			ADD_VAR( ::FloatProperty, TeamScaleModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldRightScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldLeftScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RightTeamPulseTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftTeamPulseTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ScoreTransitionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastScores, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowDirectional, 0x1 )
			void DisplayScoring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.DisplayScoring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayTeamScore(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.DisplayTeamScore" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetTeamScore( byte TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.GetTeamScore" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class Actor* GetDirectionalDest( byte TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.GetDirectionalDest" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void DisplayTeamLogos( byte TeamIndex, void* pos, float DestScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.DisplayTeamLogos" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = TeamIndex;
				*( void** )( params + 4 ) = pos;
				*( float* )( params + 12 ) = DestScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDirectionIndicator( byte TeamIndex, void* pos, class Actor* destActor, float DestScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamHUD.DisplayDirectionIndicator" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )params = TeamIndex;
				*( void** )( params + 4 ) = pos;
				*( class Actor** )( params + 12 ) = destActor;
				*( float* )( params + 16 ) = DestScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
