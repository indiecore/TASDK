#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn : public Actor
	{
	public:
			ADD_OBJECT( TrPlayerController, OwningController )
			ADD_OBJECT( ScriptClass, ExtentTemplateClass )
			ADD_VAR( ::BoolProperty, IsInProgress, 0x4 )
			ADD_VAR( ::BoolProperty, PendingDelete, 0x2 )
			ADD_VAR( ::BoolProperty, CheckExtentsOnSpawn, 0x1 )
			ADD_VAR( ::FloatProperty, VehicleDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GameObjectiveDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlagStationDist, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DisplayName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, MICDisplay )
			ADD_VAR( ::IntProperty, CreditCost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DegreeOfMovement, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CooldownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CallTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BuildupTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DatabaseId, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CallInId, 0xFFFFFFFF )
			void Initialize( int NewPrice, int NewBuildup, int NewCooldown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.Initialize" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = NewPrice;
				*( int* )( params + 4 ) = NewBuildup;
				*( int* )( params + 8 ) = NewCooldown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCreditCost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.GetCreditCost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool VerifyCredits(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.VerifyCredits" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool VerifyPower(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.VerifyPower" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FireCompletedCallIn( int CallInOffs, Vector TargetLocation, Vector TargetNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.FireCompletedCallIn" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = CallInOffs;
				*( Vector* )( params + 4 ) = TargetLocation;
				*( Vector* )( params + 16 ) = TargetNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
