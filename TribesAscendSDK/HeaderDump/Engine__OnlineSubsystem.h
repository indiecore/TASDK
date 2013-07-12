#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.OnlineSubsystem." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.OnlineSubsystem." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.OnlineSubsystem." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
			ADD_VAR( ::StrProperty, IniLocPatcherClassName, 0xFFFFFFFF )
			ADD_OBJECT( IniLocPatcher, Patcher )
			ADD_VAR( ::BoolProperty, bUseBuildIdOverride, 0x1 )
			ADD_VAR( ::IntProperty, BuildIdOverride, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AsyncMinCompletionTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
