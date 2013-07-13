#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_MobileRawInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_MobileRawInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_MobileRawInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileRawInput : public SequenceEvent
	{
	public:
			ADD_VAR( ::FloatProperty, TimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TouchLocationY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TouchLocationX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TouchIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
