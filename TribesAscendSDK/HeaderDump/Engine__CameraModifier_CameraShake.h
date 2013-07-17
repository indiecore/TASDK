#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraModifier_CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraModifier_CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraModifier_CameraShake." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
			ADD_VAR( ::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF )
			float InitializeOffset( void* &Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.InitializeOffset" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Param = *( void** )( params + 0 );
				return *( float* )( params + function->return_val_offset() );
			}

			void ReinitShake( int ActiveShakeIdx, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.ReinitShake" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = ActiveShakeIdx;
				*( float* )( params + 4 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* InitializeShake( class CameraShake* NewShake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.InitializeShake" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class CameraShake** )( params + 0 ) = NewShake;
				*( float* )( params + 4 ) = Scale;
				*( byte* )( params + 8 ) = PlaySpace;
				*( Rotator* )( params + 12 ) = UserPlaySpaceRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void AddCameraShake( class CameraShake* NewShake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.AddCameraShake" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class CameraShake** )( params + 0 ) = NewShake;
				*( float* )( params + 4 ) = Scale;
				*( byte* )( params + 8 ) = PlaySpace;
				*( Rotator* )( params + 12 ) = UserPlaySpaceRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveCameraShake( class CameraShake* Shake )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.RemoveCameraShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CameraShake** )( params + 0 ) = Shake;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveAllCameraShakes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.RemoveAllCameraShakes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCameraShake( float DeltaTime, void* &Shake, void* &OutPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.UpdateCameraShake" );
				byte *params = ( byte* )( malloc( 176 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( void** )( params + 16 ) = Shake;
				*( void** )( params + 160 ) = OutPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Shake = *( void** )( params + 16 );
				OutPOV = *( void** )( params + 160 );
			}

			bool ModifyCamera( class Camera* Camera, float DeltaTime, void* &OutPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier_CameraShake.ModifyCamera" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Camera** )( params + 0 ) = Camera;
				*( float* )( params + 4 ) = DeltaTime;
				*( void** )( params + 8 ) = OutPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPOV = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
