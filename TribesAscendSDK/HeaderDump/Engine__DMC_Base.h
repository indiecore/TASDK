#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DMC_Base." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DMC_Base." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DMC_Base." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DMC_Base : public Actor
	{
	public:
			void PrintString( ScriptArray< wchar_t > InString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.PrintString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = InString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetWorldTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.GetWorldTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Conv_IntToFloat( int InInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_IntToFloat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = InInt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Conv_FloatToString( float InFloat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_FloatToString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InFloat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Conv_IntToString( int InInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_IntToString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = InInt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Conv_BoolToString( bool InBool )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_BoolToString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = InBool;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Conv_VectorToString( Vector InVec )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_VectorToString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = InVec;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Conv_RotatorToString( Rotator InRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.Conv_RotatorToString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )params = InRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			Vector MakeVector( float X, float Y, float Z )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.MakeVector" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = X;
				*( float* )( params + 4 ) = Y;
				*( float* )( params + 8 ) = Z;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void BreakVector( Vector InVec, float &X, float &Y, float &Z )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.BreakVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = InVec;
				*( float* )( params + 12 ) = X;
				*( float* )( params + 16 ) = Y;
				*( float* )( params + 20 ) = Z;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				X = *( float* )( params + 12 );
				Y = *( float* )( params + 16 );
				Z = *( float* )( params + 20 );
			}

			Rotator MakeRot( float Pitch, float Yaw, float Roll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.MakeRot" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = Pitch;
				*( float* )( params + 4 ) = Yaw;
				*( float* )( params + 8 ) = Roll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void BreakRot( Rotator InRot, float &Pitch, float &Yaw, float &Roll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.BreakRot" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )params = InRot;
				*( float* )( params + 12 ) = Pitch;
				*( float* )( params + 16 ) = Yaw;
				*( float* )( params + 20 ) = Roll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Pitch = *( float* )( params + 12 );
				Yaw = *( float* )( params + 16 );
				Roll = *( float* )( params + 20 );
			}

			void* AddComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.AddComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void DMCCreate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.DMCCreate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DMCTakeDamage( int DamageAmount, Vector HitLocation, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.DMCTakeDamage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = DamageAmount;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DMC_Base.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
