#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimNodeBlendBySpeed." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimNodeBlendBySpeed." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimNodeBlendBySpeed." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeBlendBySpeed : public AnimNodeBlendList
	{
	public:
			ADD_VAR( ::FloatProperty, BlendDelayRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendDownDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendUpDelay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseAcceleration, 0x1 )
			ADD_VAR( ::FloatProperty, BlendDownPerc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendUpTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastChannel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Speed, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
