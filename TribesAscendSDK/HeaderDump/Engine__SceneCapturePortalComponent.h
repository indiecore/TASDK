#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SceneCapturePortalComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SceneCapturePortalComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SceneCapturePortalComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCapturePortalComponent : public SceneCaptureComponent
	{
	public:
			ADD_OBJECT( Actor, ViewDestination )
			ADD_VAR( ::FloatProperty, ScaleFOV, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
			void SetCaptureParameters( class TextureRenderTarget2D* NewTextureTarget, float NewScaleFOV, class Actor* NewViewDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCapturePortalComponent.SetCaptureParameters" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class TextureRenderTarget2D** )( params + 0 ) = NewTextureTarget;
				*( float* )( params + 4 ) = NewScaleFOV;
				*( class Actor** )( params + 8 ) = NewViewDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
