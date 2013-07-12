#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimationCompressionAlgorithm_Automatic." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimationCompressionAlgorithm_Automatic." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimationCompressionAlgorithm_Automatic." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_Automatic : public AnimationCompressionAlgorithm
	{
	public:
			ADD_VAR( ::BoolProperty, bRaiseMaxErrorToExisting, 0x40 )
			ADD_VAR( ::BoolProperty, bAutoReplaceIfExistingErrorTooGreat, 0x20 )
			ADD_VAR( ::BoolProperty, bRunCurrentDefaultCompressor, 0x10 )
			ADD_VAR( ::BoolProperty, bTryIntervalKeyRemoval, 0x8 )
			ADD_VAR( ::BoolProperty, bTryLinearKeyRemovalCompression, 0x4 )
			ADD_VAR( ::BoolProperty, bTryPerTrackBitwiseCompression, 0x2 )
			ADD_VAR( ::BoolProperty, bTryFixedBitwiseCompression, 0x1 )
			ADD_VAR( ::FloatProperty, MaxEndEffectorError, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
