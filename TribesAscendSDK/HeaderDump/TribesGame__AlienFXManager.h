#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.AlienFXManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.AlienFXManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.AlienFXManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AlienFXManager : public Object
	{
	public:
			ADD_VAR( ::ByteProperty, eLastOverlay, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, eCurrOverlay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fIntervalCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fBoundsPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fHighBounds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fLowBounds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, nTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fDamages, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fObjectiveTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBrighten, 0x8 )
			ADD_VAR( ::BoolProperty, bMenuOpen, 0x4 )
			ADD_VAR( ::BoolProperty, bLoaded, 0x2 )
			ADD_VAR( ::BoolProperty, bShowFX, 0x1 )
			ADD_VAR( ::IntProperty, nHealth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, nTeam, 0xFFFFFFFF )
			void Init( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Close(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Close" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Queued(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Queued" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Objective(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Objective" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwapWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.SwapWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckHealth(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.CheckHealth" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void menu( bool bOpen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.menu" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bOpen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Damage( byte Area )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Damage" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Area;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTeam( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.SetTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHealth( int Health )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.SetHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Health;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Overlay( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.Overlay" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DamageConvert( ScriptArray< wchar_t > Area )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.AlienFXManager.DamageConvert" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Area;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
