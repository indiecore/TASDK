#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeSequenceBlendByAim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeSequenceBlendByAim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeSequenceBlendByAim." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeSequenceBlendByAim : public AnimNodeSequenceBlendBase
	{
	public:
			ADD_VAR( ::NameProperty, AnimName_RD, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_RC, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_RU, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_CD, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_CC, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_CU, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_LD, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_LC, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AnimName_LU, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
