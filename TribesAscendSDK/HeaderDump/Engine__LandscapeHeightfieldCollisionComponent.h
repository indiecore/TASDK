#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.LandscapeHeightfieldCollisionComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.LandscapeHeightfieldCollisionComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.LandscapeHeightfieldCollisionComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LandscapeHeightfieldCollisionComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, CollisionScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CollisionSizeQuads, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
