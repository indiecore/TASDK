#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrStormControlPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrStormControlPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrStormControlPoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStormControlPoint : public TrGameObjective
	{
	public:
			ADD_VAR( ::StrProperty, m_sControlPointName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLaunchTimeDescriptionPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fControlDescriptionPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileFlightTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileLaunchTrackerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileLaunchTracker, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentTransitionAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTransitionSpeed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_CurrentControlPointState, 0xFFFFFFFF )
			void OnPawnTouched( class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.OnPawnTouched" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetControlPointState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.GetControlPointState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireMissile( byte TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.FireMissile" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginTransition( byte TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.BeginTransition" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetControlPointState( byte NewControlPointState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.SetControlPointState" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewControlPointState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetScreenName( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStormControlPoint.GetScreenName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
