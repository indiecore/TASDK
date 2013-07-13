#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LocalMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LocalMessage : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bBeep, 0x10 )
			ADD_VAR( ::FloatProperty, Lifetime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsSpecial, 0x1 )
			ADD_VAR( ::BoolProperty, bIsUnique, 0x2 )
			ADD_VAR( ::BoolProperty, bCountInstances, 0x20 )
			ADD_VAR( ::BoolProperty, bIsPartiallyUnique, 0x4 )
			ADD_VAR( ::IntProperty, FontSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PosY, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsConsoleMessage, 0x8 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
