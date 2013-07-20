#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrLaserTarget." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrLaserTarget." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrLaserTarget." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrLaserTarget : public Actor
	{
	public:
			ADD_VAR( ::ByteProperty, m_nTeamId, 0xFFFFFFFF )
			void SetTeamNum( byte TeamID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.SetTeamNum" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = TeamID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void UpdateLocation( Vector NewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.UpdateLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderForOwner( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir, float Distance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.RenderForOwner" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				*( float* )( params + 32 ) = Distance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderForTeammate( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir, float Distance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrLaserTarget.RenderForTeammate" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				*( float* )( params + 32 ) = Distance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
