#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.TextureRenderTarget." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.TextureRenderTarget." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.TextureRenderTarget." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TextureRenderTarget : public Texture
	{
	public:
			ADD_VAR( ::FloatProperty, TargetGamma, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRenderOnce, 0x4 )
			ADD_VAR( ::BoolProperty, bNeedsTwoCopies, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdateImmediate, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
