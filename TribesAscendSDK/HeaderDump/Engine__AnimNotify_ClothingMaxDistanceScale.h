#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_ClothingMaxDistanceScale." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_ClothingMaxDistanceScale." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_ClothingMaxDistanceScale." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_ClothingMaxDistanceScale : public AnimNotify
	{
	public:
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ScaleMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
