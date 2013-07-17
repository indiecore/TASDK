#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LightEnvironmentComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LightEnvironmentComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LightEnvironmentComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LightEnvironmentComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::FloatProperty, DominantShadowFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTranslucencyShadowed, 0x10 )
			ADD_VAR( ::BoolProperty, bAllowPreShadow, 0x8 )
			ADD_VAR( ::BoolProperty, bAllowDynamicShadowsOnTranslucency, 0x4 )
			ADD_VAR( ::BoolProperty, bForceNonCompositeDynamicLights, 0x2 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			void SetEnabled( bool bNewEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightEnvironmentComponent.SetEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsEnabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LightEnvironmentComponent.IsEnabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
