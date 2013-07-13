#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FractureMaterial." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FractureMaterial." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FractureMaterial." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FractureMaterial : public Object
	{
	public:
			ADD_OBJECT( SoundCue, FractureSound )
			ADD_OBJECT( ParticleSystem, FractureEffect )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
