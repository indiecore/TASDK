#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SkelControlSpline." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SkelControlSpline." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SkelControlSpline." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlSpline : public SkelControlBase
	{
	public:
			ADD_VAR( ::FloatProperty, StartSplineTension, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndSplineTension, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInvertSplineBoneAxis, 0x1 )
			ADD_VAR( ::ByteProperty, BoneRotMode, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SplineLength, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SplineBoneAxis, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
