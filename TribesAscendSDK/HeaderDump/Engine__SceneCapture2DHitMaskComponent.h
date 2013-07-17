#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SceneCapture2DHitMaskComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SceneCapture2DHitMaskComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SceneCapture2DHitMaskComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCapture2DHitMaskComponent : public SceneCaptureComponent
	{
	public:
			ADD_VAR( ::FloatProperty, FadingIntervalTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingDurationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingStartTimeSinceHit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HitMaskCullDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ForceLOD, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaterialIndex, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
			void SetCaptureTargetTexture( class TextureRenderTarget2D* InTextureTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCapture2DHitMaskComponent.SetCaptureTargetTexture" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TextureRenderTarget2D** )( params + 0 ) = InTextureTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCaptureParameters( Vector InMaskPosition, float InMaskRadius, Vector InStartupPosition, bool bOnlyWhenFacing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCapture2DHitMaskComponent.SetCaptureParameters" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )( params + 0 ) = InMaskPosition;
				*( float* )( params + 12 ) = InMaskRadius;
				*( Vector* )( params + 16 ) = InStartupPosition;
				*( bool* )( params + 28 ) = bOnlyWhenFacing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFadingStartTimeSinceHit( float InFadingStartTimeSinceHit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCapture2DHitMaskComponent.SetFadingStartTimeSinceHit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = InFadingStartTimeSinceHit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
