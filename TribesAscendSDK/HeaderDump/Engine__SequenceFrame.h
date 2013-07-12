#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SequenceFrame." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SequenceFrame." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SequenceFrame." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SequenceFrame : public SequenceObject
	{
	public:
			ADD_OBJECT( Material, FillMaterial )
			ADD_OBJECT( Texture2D, FillTexture )
			ADD_VAR( ::BoolProperty, bTileFill, 0x4 )
			ADD_VAR( ::BoolProperty, bFilled, 0x2 )
			ADD_VAR( ::BoolProperty, bDrawBox, 0x1 )
			ADD_VAR( ::IntProperty, BorderWidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
