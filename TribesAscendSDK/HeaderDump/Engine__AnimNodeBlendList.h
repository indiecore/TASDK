#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimNodeBlendList." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimNodeBlendList." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimNodeBlendList." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeBlendList : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::IntProperty, EditorActiveChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SliderPosition, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSkipBlendWhenNotRendered, 0x4 )
			ADD_VAR( ::BoolProperty, bForceChildFullWeightWhenBecomingRelevant, 0x2 )
			ADD_VAR( ::BoolProperty, bPlayActiveChild, 0x1 )
			ADD_VAR( ::IntProperty, ActiveChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
