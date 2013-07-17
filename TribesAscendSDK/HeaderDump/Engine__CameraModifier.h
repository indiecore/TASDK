#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraModifier." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraModifier." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraModifier." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraModifier : public Object
	{
	public:
			bool AddCameraModifier( class Camera* Camera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.AddCameraModifier" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Camera** )( params + 0 ) = Camera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ProcessViewRotation( class Actor* ViewTarget, float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = ViewTarget;
				*( float* )( params + 4 ) = DeltaTime;
				*( Rotator* )( params + 8 ) = out_ViewRotation;
				*( Rotator* )( params + 20 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 8 );
				out_DeltaRot = *( Rotator* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, TargetAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Alpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AlphaOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AlphaInTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Priority, 0xFFFFFFFF )
			ADD_OBJECT( Camera, CameraOwner )
			ADD_VAR( ::BoolProperty, bDebug, 0x8 )
			ADD_VAR( ::BoolProperty, bExclusive, 0x4 )
			ADD_VAR( ::BoolProperty, bPendingDisable, 0x2 )
			ADD_VAR( ::BoolProperty, bDisabled, 0x1 )
			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ModifyCamera( class Camera* Camera, float DeltaTime, void* &OutPOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.ModifyCamera" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Camera** )( params + 0 ) = Camera;
				*( float* )( params + 4 ) = DeltaTime;
				*( void** )( params + 8 ) = OutPOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPOV = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsDisabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.IsDisabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveCameraModifier( class Camera* Camera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.RemoveCameraModifier" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Camera** )( params + 0 ) = Camera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DisableModifier( bool bImmediate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.DisableModifier" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bImmediate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.EnableModifier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.ToggleModifier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateAlpha( class Camera* Camera, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CameraModifier.UpdateAlpha" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Camera** )( params + 0 ) = Camera;
				*( float* )( params + 4 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
