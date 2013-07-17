#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SequenceOp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SequenceOp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SequenceOp." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SequenceOp : public SequenceObject
	{
	public:
			void GetObjectVars( ScriptArray< wchar_t > inDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetObjectVars" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 12 ) = inDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, SearchTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActivateCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, GamepadID, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPendingOutputConnectorRecalc, 0x100 )
			ADD_VAR( ::BoolProperty, bPendingInputConnectorRecalc, 0x80 )
			ADD_VAR( ::BoolProperty, bPendingVarConnectorRecalc, 0x40 )
			ADD_VAR( ::BoolProperty, bHaveMovingOutputConnector, 0x20 )
			ADD_VAR( ::BoolProperty, bHaveMovingInputConnector, 0x10 )
			ADD_VAR( ::BoolProperty, bHaveMovingVarConnector, 0x8 )
			ADD_VAR( ::BoolProperty, bAutoActivateOutputLinks, 0x4 )
			ADD_VAR( ::BoolProperty, bLatentExecution, 0x2 )
			ADD_VAR( ::BoolProperty, bActive, 0x1 )
			bool HasLinkedOps( bool bConsiderInputLinks )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.HasLinkedOps" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bConsiderInputLinks;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetLinkedObjects( ScriptClass* ObjectType, bool bRecurse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetLinkedObjects" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )( params + 12 ) = ObjectType;
				*( bool* )( params + 16 ) = bRecurse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetInterpDataVars( ScriptArray< wchar_t > inDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetInterpDataVars" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 12 ) = inDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetBoolVars( ScriptArray< wchar_t > inDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetBoolVars" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 12 ) = inDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LinkedVariables( ScriptClass* VarClass, class SequenceVariable* &OutVariable, ScriptArray< wchar_t > inDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.LinkedVariables" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )( params + 0 ) = VarClass;
				*( class SequenceVariable** )( params + 4 ) = OutVariable;
				*( ScriptArray< wchar_t >* )( params + 8 ) = inDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVariable = *( class SequenceVariable** )( params + 4 );
			}

			bool ActivateOutputLink( int OutputIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.ActivateOutputLink" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = OutputIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ActivateNamedOutputLink( ScriptArray< wchar_t > LinkDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.ActivateNamedOutputLink" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = LinkDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Activated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.Activated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Deactivated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.Deactivated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VersionUpdated( int OldVersion, int NewVersion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.VersionUpdated" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = OldVersion;
				*( int* )( params + 4 ) = NewVersion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopulateLinkedVariableValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.PopulateLinkedVariableValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PublishLinkedVariableValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.PublishLinkedVariableValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Pawn* GetPawn( class Actor* TheActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = TheActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			class Controller* GetController( class Actor* TheActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.GetController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = TheActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void ForceActivateInput( int InputIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.ForceActivateInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InputIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceActivateOutput( int OutputIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceOp.ForceActivateOutput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = OutputIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
