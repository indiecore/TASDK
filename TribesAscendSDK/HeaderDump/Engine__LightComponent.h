#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LightComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LightComponent : public ActorComponent
	{
	public:
			void SetEnabled( bool bSetEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.SetEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bSetEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLightProperties( float NewBrightness, void* NewLightColor, class LightFunction* NewLightFunction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.SetLightProperties" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = NewBrightness;
				*( void** )( params + 4 ) = NewLightColor;
				*( class LightFunction** )( params + 8 ) = NewLightFunction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, Brightness, 0xFFFFFFFF )
			ADD_OBJECT( LightFunction, Function )
			Vector GetOrigin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.GetOrigin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetDirection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.GetDirection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void UpdateColorAndBrightness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.UpdateColorAndBrightness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateLightShaftParameters(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.UpdateLightShaftParameters" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBloomScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.OnUpdatePropertyBloomScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBloomTint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.OnUpdatePropertyBloomTint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyOcclusionMaskDarkness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.OnUpdatePropertyOcclusionMaskDarkness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBrightness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.OnUpdatePropertyBrightness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyLightColor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightComponent.OnUpdatePropertyLightColor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LightEnv_BouncedLightBrightness, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_VAR( ::BoolProperty, CastShadows, 0x2 )
			ADD_VAR( ::BoolProperty, CastStaticShadows, 0x4 )
			ADD_VAR( ::BoolProperty, CastDynamicShadows, 0x8 )
			ADD_VAR( ::BoolProperty, bCastCompositeShadow, 0x10 )
			ADD_VAR( ::BoolProperty, bAffectCompositeShadowDirection, 0x20 )
			ADD_VAR( ::BoolProperty, bNonModulatedSelfShadowing, 0x40 )
			ADD_VAR( ::BoolProperty, bSelfShadowOnly, 0x80 )
			ADD_VAR( ::BoolProperty, bAllowPreShadow, 0x100 )
			ADD_VAR( ::BoolProperty, bForceDynamicLight, 0x200 )
			ADD_VAR( ::BoolProperty, UseDirectLightMap, 0x400 )
			ADD_VAR( ::BoolProperty, bHasLightEverBeenBuiltIntoLightMap, 0x800 )
			ADD_VAR( ::BoolProperty, bOnlyAffectSameAndSpecifiedLevels, 0x1000 )
			ADD_VAR( ::BoolProperty, bCanAffectDynamicPrimitivesOutsideDynamicChannel, 0x2000 )
			ADD_VAR( ::BoolProperty, bUseVolumes, 0x4000 )
			ADD_VAR( ::BoolProperty, bRenderLightShafts, 0x8000 )
			ADD_VAR( ::BoolProperty, bUseImageReflectionSpecular, 0x10000 )
			ADD_VAR( ::BoolProperty, bPrecomputedLightingIsValid, 0x20000 )
			ADD_VAR( ::BoolProperty, bExplicitlyAssignedLight, 0x40000 )
			ADD_VAR( ::ByteProperty, LightAffectsClassification, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LightShadowMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ModShadowFadeoutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ModShadowFadeoutExponent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LightListIndex, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ShadowProjectionTechnique, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ShadowFilterQuality, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinShadowResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxShadowResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ShadowFadeResolution, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionDepthRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomScreenBlendThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialBlurPercent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionMaskDarkness, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, ReflectionTexture )
			ADD_VAR( ::FloatProperty, ReflectionScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
