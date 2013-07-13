#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Canvas." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Canvas." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Canvas." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Canvas : public Object
	{
	public:
			ADD_OBJECT( Font, Font )
			ADD_OBJECT( Texture2D, DefaultTexture )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNoSmooth, 0x2 )
			ADD_VAR( ::BoolProperty, bCenter, 0x1 )
			ADD_VAR( ::FloatProperty, CurYL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClipY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClipX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OrgY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OrgX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
