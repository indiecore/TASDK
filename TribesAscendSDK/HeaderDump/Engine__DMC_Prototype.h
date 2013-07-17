#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DMC_Prototype." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DMC_Prototype." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DMC_Prototype." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DMC_Prototype : public K2GraphBase
	{
	public:
			ADD_VAR( ::StrProperty, DefaultPropText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FunctionCode, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, GeneratedClass )
			ADD_OBJECT( ScriptClass, ParentClass )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
