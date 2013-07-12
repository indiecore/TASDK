#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Pylon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Pylon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Pylon." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Pylon : public NavigationPoint
	{
	public:
			ADD_VAR( ::IntProperty, DebugEdgeCount, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ExpansionSphereCenter, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceObstacleMeshCollision, 0x400 )
			ADD_VAR( ::BoolProperty, bDisabled, 0x200 )
			ADD_VAR( ::BoolProperty, bBuildThisPylon, 0x100 )
			ADD_VAR( ::BoolProperty, bDrawObstacleSurface, 0x80 )
			ADD_VAR( ::BoolProperty, bDrawWalkableSurface, 0x40 )
			ADD_VAR( ::BoolProperty, bRenderInShowPaths, 0x20 )
			ADD_VAR( ::BoolProperty, bDrawPolyBounds, 0x10 )
			ADD_VAR( ::BoolProperty, bDrawEdgePolys, 0x8 )
			ADD_VAR( ::BoolProperty, bNeedsCostCheck, 0x4 )
			ADD_VAR( ::BoolProperty, bUseExpansionSphereOverride, 0x2 )
			ADD_VAR( ::BoolProperty, bImportedMesh, 0x1 )
			ADD_VAR( ::FloatProperty, MaxExpansionRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExpansionRadius, 0xFFFFFFFF )
			ADD_OBJECT( Pylon, NextPylon )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
