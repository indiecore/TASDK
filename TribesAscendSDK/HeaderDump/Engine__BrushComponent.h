#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.BrushComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.BrushComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.BrushComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class BrushComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bBlockComplexCollisionTrace, 0x1 )
			ADD_VAR( ::IntProperty, CachedPhysBrushDataVersion, 0xFFFFFFFF )
			ADD_OBJECT( Model, Brush )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
