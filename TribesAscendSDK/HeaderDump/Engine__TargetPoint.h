#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TargetPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TargetPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TargetPoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TargetPoint : public Keypoint
	{
	public:
			ADD_VAR( ::IntProperty, SpawnRefCount, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, SpawnSpriteTexture )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
