#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimationCompressionAlgorithm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimationCompressionAlgorithm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimationCompressionAlgorithm." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimationCompressionAlgorithm : public Object
	{
	public:
			ADD_VAR( ::ByteProperty, RotationCompressionFormat, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TranslationCompressionFormat, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNeedsSkeleton, 0x1 )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
