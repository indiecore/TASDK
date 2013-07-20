#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraActor : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bConstrainAspectRatio, 0x1 )
			ADD_VAR( ::FloatProperty, AspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCamOverridePostProcess, 0x2 )
			void GetCameraView( float DeltaTime, void* &OutPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraActor.GetCameraView" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )params = DeltaTime;
				*( void** )( params + 4 ) = OutPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPOV = *( void** )( params + 4 );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraActor.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
