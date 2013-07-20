#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LensFlareComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LensFlareComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LensFlareComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LensFlareComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, NextTraceTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InnerCone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OuterCone, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bVisibleForMobile, 0x40 )
			ADD_VAR( ::BoolProperty, bUsesSceneColor, 0x20 )
			ADD_VAR( ::BoolProperty, bHasUnlitDistortion, 0x10 )
			ADD_VAR( ::BoolProperty, bHasUnlitTranslucency, 0x8 )
			ADD_VAR( ::BoolProperty, bHasTranslucency, 0x4 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x2 )
			ADD_VAR( ::BoolProperty, bAutoActivate, 0x1 )
			ADD_OBJECT( LensFlare, Template )
			void SetTemplate( class LensFlare* NewTemplate, bool bForceSet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareComponent.SetTemplate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class LensFlare** )params = NewTemplate;
				*( bool* )( params + 4 ) = bForceSet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSourceColor( void* InSourceColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareComponent.SetSourceColor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = InSourceColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetIsActive( bool bInIsActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LensFlareComponent.SetIsActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInIsActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
