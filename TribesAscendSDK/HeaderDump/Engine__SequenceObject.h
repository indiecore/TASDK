#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SequenceObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SequenceObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SequenceObject." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SequenceObject : public Object
	{
	public:
			ADD_VAR( ::IntProperty, ObjInstanceVersion, 0xFFFFFFFF )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceObject.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, DrawHeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DrawWidth, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSuppressAutoComment, 0x10 )
			ADD_VAR( ::BoolProperty, bOutputObjCommentToScreen, 0x8 )
			ADD_VAR( ::BoolProperty, bDrawLast, 0x4 )
			ADD_VAR( ::BoolProperty, bDrawFirst, 0x2 )
			ADD_VAR( ::BoolProperty, bDeletable, 0x1 )
			ADD_VAR( ::StrProperty, ObjComment, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ObjCategory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ObjName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ObjPosY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ObjPosX, 0xFFFFFFFF )
			ADD_OBJECT( Sequence, ParentSequence )
			void ScriptLog( ScriptArray< wchar_t > LogText, bool bWarning )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceObject.ScriptLog" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = LogText;
				*( bool* )( params + 12 ) = bWarning;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class WorldInfo* GetWorldInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceObject.GetWorldInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class WorldInfo** )( params + function->return_val_offset() );
			}

			bool IsValidLevelSequenceObject(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceObject.IsValidLevelSequenceObject" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPastingIntoLevelSequenceAllowed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceObject.IsPastingIntoLevelSequenceAllowed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
