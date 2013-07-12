#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ParticleEmitter." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ParticleEmitter." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ParticleEmitter." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleEmitter : public Object
	{
	public:
			ADD_VAR( ::IntProperty, InitialAllocationCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PeakActiveParticles, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCookedOut, 0x8 )
			ADD_VAR( ::BoolProperty, bIsSoloing, 0x4 )
			ADD_VAR( ::BoolProperty, bCollapsed, 0x2 )
			ADD_VAR( ::BoolProperty, ConvertedModules, 0x1 )
			ADD_VAR( ::ByteProperty, EmitterRenderMode, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SubUVDataOffset, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EmitterName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
