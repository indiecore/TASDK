#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RadialBlurComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RadialBlurComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RadialBlurComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RadialBlurComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x2 )
			ADD_VAR( ::BoolProperty, bRenderAsVelocity, 0x1 )
			ADD_VAR( ::FloatProperty, DistanceFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxCullDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurOpacity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurScale, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DepthPriorityGroup, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, Material )
			void SetMaterial( class MaterialInterface* InMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.SetMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )params = InMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBlurScale( float InBlurScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.SetBlurScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InBlurScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBlurFalloffExponent( float InBlurFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.SetBlurFalloffExponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InBlurFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBlurOpacity( float InBlurOpacity )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.SetBlurOpacity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InBlurOpacity;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEnabled( bool bInEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.SetEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBlurScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.OnUpdatePropertyBlurScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBlurFalloffExponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.OnUpdatePropertyBlurFalloffExponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBlurOpacity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RadialBlurComponent.OnUpdatePropertyBlurOpacity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
