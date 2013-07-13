#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.MobileMenuButton." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.MobileMenuButton." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.MobileMenuButton." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobileMenuButton : public MobileMenuObject
	{
	public:
			ADD_VAR( ::StrProperty, Caption, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, Images )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
