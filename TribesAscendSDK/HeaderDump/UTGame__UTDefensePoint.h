#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDefensePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDefensePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDefensePoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDefensePoint : public UDKScriptedNavigationPoint
	{
	public:
			ADD_OBJECT( ScriptClass, WeaponPreference )
			class Actor* GetMoveTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.GetMoveTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bSniping, 0x2 )
			ADD_VAR( ::BoolProperty, bFirstScript, 0x1 )
			ADD_OBJECT( UDKGameObjective, DefendedObjective )
			ADD_VAR( ::BoolProperty, bOnlyOnFoot, 0x4 )
			ADD_VAR( ::NameProperty, DefenseGroup, 0xFFFFFFFF )
			bool HigherPriorityThan( class UTDefensePoint* S, class UTBot* B, bool bAutoPointsInUse, bool bPrioritizeSameGroup, int &NumChecked )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.HigherPriorityThan" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UTDefensePoint** )params = S;
				*( class UTBot** )( params + 4 ) = B;
				*( bool* )( params + 8 ) = bAutoPointsInUse;
				*( bool* )( params + 12 ) = bPrioritizeSameGroup;
				*( int* )( params + 16 ) = NumChecked;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NumChecked = *( int* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTDefensePoint, NextDefensePoint )
			ADD_OBJECT( Controller, CurrentUser )
			ADD_VAR( ::ByteProperty, DefensePriority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlySkilled, 0x8 )
			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FreePoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.FreePoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckForErrors(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.CheckForErrors" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDefensePoint.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
