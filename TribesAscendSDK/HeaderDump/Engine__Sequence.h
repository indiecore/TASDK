#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Sequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Sequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Sequence." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Sequence : public SequenceOp
	{
	public:
			void FindSeqObjectsByClass( ScriptClass* DesiredClass, bool bRecursive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Sequence.FindSeqObjectsByClass" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )( params + 0 ) = DesiredClass;
				*( bool* )( params + 4 ) = bRecursive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, DefaultViewZoom, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultViewY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultViewX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			void FindSeqObjectsByName( ScriptArray< wchar_t > SeqObjName, bool bCheckComment, bool bRecursive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Sequence.FindSeqObjectsByName" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = SeqObjName;
				*( bool* )( params + 12 ) = bCheckComment;
				*( bool* )( params + 28 ) = bRecursive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Sequence.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEnabled( bool bInEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Sequence.SetEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
