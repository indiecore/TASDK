#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimationCompressionAlgorithm_RemoveLinearKeys." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimationCompressionAlgorithm_RemoveLinearKeys." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimationCompressionAlgorithm_RemoveLinearKeys." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveLinearKeys : public AnimationCompressionAlgorithm
	{
	public:
			ADD_VAR( ::BoolProperty, bActuallyFilterLinearKeys, 0x2 )
			ADD_VAR( ::BoolProperty, bRetarget, 0x1 )
			ADD_VAR( ::FloatProperty, ParentKeyScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EffectorDiffSocket, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinEffectorDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxEffectorDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAngleDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxPosDiff, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
