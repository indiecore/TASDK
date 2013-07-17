#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAnimNodeBlendBy3pDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendBy3pDevice : public TrAnimNodeBlendList
	{
	public:
			ADD_VAR( ::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_SkiingReloadName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_SkiingFireName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRefireTimePreview, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCurrentDeviceSupportsAltSkiReloadAnims, 0x10 )
			ADD_VAR( ::BoolProperty, m_bCurrentDeviceSupportsAltSkiFireAnims, 0x8 )
			ADD_VAR( ::BoolProperty, m_bScalePutawayRetrieveAnims, 0x4 )
			ADD_VAR( ::BoolProperty, m_bFirePreview, 0x2 )
			ADD_VAR( ::BoolProperty, m_bScaleFireByRefireTime, 0x1 )
			ADD_OBJECT( TrPawn, m_TrPawn )
			void PlayIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayBuildup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayBuildup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFire( float RefireTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = RefireTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayPutaway( float PutAwayTime, float ForcedRateBuff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayPutaway" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = PutAwayTime;
				*( float* )( params + 4 ) = ForcedRateBuff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRetrieve( float RetrieveTime, float ForcedRateBuff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayRetrieve" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = RetrieveTime;
				*( float* )( params + 4 ) = ForcedRateBuff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayReload( float ReloadTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayReload" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ReloadTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayOffhand( ScriptName OffhandAnimName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayOffhand" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = OffhandAnimName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
