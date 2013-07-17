#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ProcBuilding." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ProcBuilding." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ProcBuilding." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ProcBuilding : public Volume
	{
	public:
			int FindEdgeForTopLevelScope( int TopLevelScopeIndex, byte Edge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.FindEdgeForTopLevelScope" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )( params + 0 ) = TopLevelScopeIndex;
				*( byte* )( params + 4 ) = Edge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void BreakFractureComponent( Vector BoxMin, Vector BoxMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.BreakFractureComponent" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 4 ) = BoxMin;
				*( Vector* )( params + 16 ) = BoxMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetAllGroupedProcBuildings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.GetAllGroupedProcBuildings" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class ProcBuilding* GetBaseMostBuilding(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.GetBaseMostBuilding" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ProcBuilding** )( params + function->return_val_offset() );
			}

			void* FindComponentsForTopLevelScope( int TopLevelScopeIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.FindComponentsForTopLevelScope" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TopLevelScopeIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void ClearBuildingMeshes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ProcBuilding.ClearBuildingMeshes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ProcBuildingRuleset, Ruleset )
			ADD_VAR( ::BoolProperty, bGenerateRoofMesh, 0x1 )
			ADD_VAR( ::BoolProperty, bGenerateFloorMesh, 0x2 )
			ADD_VAR( ::BoolProperty, bApplyRulesToRoof, 0x4 )
			ADD_VAR( ::BoolProperty, bApplyRulesToFloor, 0x8 )
			ADD_VAR( ::BoolProperty, bSplitWallsAtRoofLevels, 0x10 )
			ADD_VAR( ::BoolProperty, bSplitWallsAtWallEdges, 0x20 )
			ADD_VAR( ::BoolProperty, bQuickEdited, 0x40 )
			ADD_VAR( ::BoolProperty, bBuildingBrushCollision, 0x80 )
			ADD_VAR( ::BoolProperty, bDebugDrawEdgeInfo, 0x100 )
			ADD_VAR( ::BoolProperty, bDebugDrawScopes, 0x200 )
			ADD_VAR( ::IntProperty, NumMeshedTopLevelScopes, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFacadeZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinFacadeZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SimpleMeshMassiveLODDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RenderToTexturePullBackAmount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RoofLightmapRes, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NonRectWallLightmapRes, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LODRenderToTextureScale, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ParamSwatchName, 0xFFFFFFFF )
			ADD_OBJECT( StaticMeshActor, LowLODPersistentActor )
			ADD_OBJECT( Actor, CurrentSimpleMeshActor )
			ADD_VAR( ::IntProperty, BuildingInstanceVersion, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
