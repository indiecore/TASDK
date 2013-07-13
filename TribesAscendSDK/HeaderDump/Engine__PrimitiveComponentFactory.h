#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PrimitiveComponentFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PrimitiveComponentFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PrimitiveComponentFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PrimitiveComponentFactory : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, CastShadow, 0x80 )
			ADD_VAR( ::BoolProperty, HiddenEditor, 0x40 )
			ADD_VAR( ::BoolProperty, HiddenGame, 0x20 )
			ADD_VAR( ::BoolProperty, BlockRigidBody, 0x10 )
			ADD_VAR( ::BoolProperty, BlockNonZeroExtent, 0x8 )
			ADD_VAR( ::BoolProperty, BlockZeroExtent, 0x4 )
			ADD_VAR( ::BoolProperty, BlockActors, 0x2 )
			ADD_VAR( ::BoolProperty, CollideActors, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
