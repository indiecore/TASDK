#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAnimNodeBlendByDeviceAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAnimNodeBlendByDeviceAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAnimNodeBlendByDeviceAnim." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByDeviceAnim : public TrAnimNodeBlendList
	{
	public:
			ADD_VAR( ::IntProperty, m_nSocketIndex, 0xFFFFFFFF )
			ADD_OBJECT( TrAnimNodeBlendByDeviceAnim, m_SecondaryDeviceBlendNode )
			ADD_VAR( ::NameProperty, m_SecondaryDeviceBlendNodeName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_ReloadPartialClipAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_DryFireAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_FireFinalRoundAnimName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bScalePutawayRetrieveAnims, 0x8 )
			ADD_VAR( ::BoolProperty, m_bScaleFireByRefireTime, 0x4 )
			ADD_VAR( ::BoolProperty, m_bPlayFire, 0x2 )
			ADD_VAR( ::BoolProperty, m_bPlayBuildUp, 0x1 )
			ADD_OBJECT( TrSkelControl_SpinControl, m_BuildupFireSpinControl )
			ADD_VAR( ::NameProperty, m_nmBuildupFireSpinControlName, 0xFFFFFFFF )
			ADD_OBJECT( TrDevice, m_Device )
			ADD_OBJECT( TrPawn, m_TrPawn )
			void StopAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.StopAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActiveChild( int ChildIndex, float BlendTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.SetActiveChild" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ChildIndex;
				*( float* )( params + 4 ) = BlendTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAltIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayAltIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayBuildup( float BuildupTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayBuildup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = BuildupTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFire( int SocketIndex, float RefireTime, int RoundsRemainingInClip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayFire" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = SocketIndex;
				*( float* )( params + 4 ) = RefireTime;
				*( int* )( params + 8 ) = RoundsRemainingInClip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayPutaway( float PutAwayTime, float ForcedRateBuff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayPutaway" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = PutAwayTime;
				*( float* )( params + 4 ) = ForcedRateBuff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRetrieve( float RetrieveTime, float ForcedRateBuff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayRetrieve" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = RetrieveTime;
				*( float* )( params + 4 ) = ForcedRateBuff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayReload( float ReloadTime, int RoundsRemainingInClip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayReload" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = ReloadTime;
				*( int* )( params + 4 ) = RoundsRemainingInClip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayOffhand( float Rate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayOffhand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Rate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStopFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.OnStopFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDryFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayDryFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayQuickRetrieve(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayQuickRetrieve" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
