#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PointLightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PointLightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PointLightComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PointLightComponent : public LightComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, Translation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinShadowFalloffRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShadowFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShadowRadiusMultiplier, 0xFFFFFFFF )
			void SetTranslation( Vector NewTranslation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PointLightComponent.SetTranslation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewTranslation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyLightColor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PointLightComponent.OnUpdatePropertyLightColor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyBrightness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PointLightComponent.OnUpdatePropertyBrightness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
