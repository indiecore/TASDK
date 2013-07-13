#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Sequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Sequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Sequence." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Sequence : public SequenceOp
	{
	public:
			ADD_VAR( ::FloatProperty, DefaultViewZoom, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultViewY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultViewX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
