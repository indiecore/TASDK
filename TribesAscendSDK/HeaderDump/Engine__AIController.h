#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AIController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AIController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AIController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AIController : public Controller
	{
	public:
			ADD_OBJECT( Actor, ScriptedFocus )
			ADD_VAR( ::IntProperty, ScriptedRouteIndex, 0xFFFFFFFF )
			ADD_OBJECT( Route, ScriptedRoute )
			ADD_OBJECT( Actor, ScriptedMoveTarget )
			ADD_VAR( ::FloatProperty, Skill, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bReverseScriptedRoute, 0x2 )
			ADD_VAR( ::BoolProperty, bAdjustFromWalls, 0x1 )
			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void SetTeam( int inTeamIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.SetTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = inTeamIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayerViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )params;
				out_Rotation = *( Rotator* )( params + 12 );
			}

			void OnAIMoveToActor( class SeqAct_AIMoveToActor* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.OnAIMoveToActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_AIMoveToActor** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyWeaponFired( class Weapon* W, byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.NotifyWeaponFired" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )params = W;
				*( byte* )( params + 4 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyWeaponFinishedFiring( class Weapon* W, byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.NotifyWeaponFinishedFiring" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )params = W;
				*( byte* )( params + 4 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanFireWeapon( class Weapon* Wpn, byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AIController.CanFireWeapon" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )params = Wpn;
				*( byte* )( params + 4 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
