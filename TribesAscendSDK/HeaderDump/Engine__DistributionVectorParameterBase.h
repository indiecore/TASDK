#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DistributionVectorParameterBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DistributionVectorParameterBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DistributionVectorParameterBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionVectorParameterBase : public DistributionVectorConstant
	{
	public:
			ADD_VAR( ::ByteProperty, ParamModes, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MaxOutput, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MinOutput, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MaxInput, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MinInput, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ParameterName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
