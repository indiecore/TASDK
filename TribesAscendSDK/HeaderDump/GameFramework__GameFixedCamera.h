#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameFixedCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameFixedCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameFixedCamera." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameFixedCamera : public GameCameraBase
	{
	public:
			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			void UpdateCamera( class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, void* &OutVT )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameFixedCamera.UpdateCamera" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Pawn** )params = P;
				*( class GamePlayerCamera** )( params + 4 ) = CameraActor;
				*( float* )( params + 8 ) = DeltaTime;
				*( void** )( params + 12 ) = OutVT;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVT = *( void** )( params + 12 );
			}

			void OnBecomeActive( class GameCameraBase* OldCamera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameFixedCamera.OnBecomeActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCameraBase** )params = OldCamera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
