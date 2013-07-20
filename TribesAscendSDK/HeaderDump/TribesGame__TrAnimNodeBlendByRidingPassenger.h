#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByRidingPassenger : public TrAnimNodeBlendList
	{
	public:
			ADD_OBJECT( AnimNodeSequence, m_FireAnimSeqNode )
			ADD_VAR( ::NameProperty, m_nmFireAnimSeqNodeName, 0xFFFFFFFF )
			ADD_OBJECT( TrPawn, m_TrPawn )
			void PlayIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFire( float RefireTime, ScriptName FireAnimName, float ReloadTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayFire" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = RefireTime;
				*( ScriptName* )( params + 4 ) = FireAnimName;
				*( float* )( params + 12 ) = ReloadTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayReload( float ReloadTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayReload" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = ReloadTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayOffhand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayOffhand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
