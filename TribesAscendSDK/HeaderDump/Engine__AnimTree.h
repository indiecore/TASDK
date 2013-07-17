#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimTree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimTree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimTree." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimTree : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::IntProperty, PreviewFloorYaw, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviewFloorPos, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, PreviewCamRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviewCamPos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewAnimSetIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewAnimSetListIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewSocketIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviewMeshIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, SocketStaticMesh )
			ADD_OBJECT( SkeletalMesh, SocketSkelMesh )
			ADD_OBJECT( SkeletalMesh, PreviewSkelMesh )
			ADD_VAR( ::FloatProperty, PreviewPlayRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MorphConnDrawY, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRebuildAnimTickArray, 0x8 )
			ADD_VAR( ::BoolProperty, bParentNodeArrayBuilt, 0x4 )
			ADD_VAR( ::BoolProperty, bBeingEdited, 0x2 )
			ADD_VAR( ::BoolProperty, bUseSavedPose, 0x1 )
			class SkelControlBase* FindSkelControl( ScriptName InControlName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.FindSkelControl" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InControlName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkelControlBase** )( params + function->return_val_offset() );
			}

			class MorphNodeBase* FindMorphNode( ScriptName InNodeName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.FindMorphNode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InNodeName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MorphNodeBase** )( params + function->return_val_offset() );
			}

			void SetUseSavedPose( bool bUseSaved )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.SetUseSavedPose" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bUseSaved;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetAnimGroupForNode( class AnimNodeSequence* SeqNode, ScriptName GroupName, bool bCreateIfNotFound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.SetAnimGroupForNode" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( ScriptName* )( params + 4 ) = GroupName;
				*( bool* )( params + 12 ) = bCreateIfNotFound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class AnimNodeSequence* GetGroupSynchMaster( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.GetGroupSynchMaster" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			class AnimNodeSequence* GetGroupNotifyMaster( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.GetGroupNotifyMaster" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			void ForceGroupRelativePosition( ScriptName GroupName, float RelativePosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.ForceGroupRelativePosition" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				*( float* )( params + 8 ) = RelativePosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetGroupRelativePosition( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.GetGroupRelativePosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetGroupRateScale( ScriptName GroupName, float NewRateScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.SetGroupRateScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				*( float* )( params + 8 ) = NewRateScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetGroupRateScale( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.GetGroupRateScale" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetGroupIndex( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimTree.GetGroupIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
