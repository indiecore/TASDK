#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.InterpData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.InterpData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.InterpData." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpData : public SequenceVariable
	{
	public:
			ADD_VAR( ::BoolProperty, bShouldBakeAndPrune, 0x1 )
			ADD_VAR( ::FloatProperty, EdSectionEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EdSectionStart, 0xFFFFFFFF )
			ADD_OBJECT( InterpFilter, SelectedFilter )
			ADD_OBJECT( InterpCurveEdSetup, CurveEdSetup )
			ADD_VAR( ::FloatProperty, PathBuildTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpLength, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
