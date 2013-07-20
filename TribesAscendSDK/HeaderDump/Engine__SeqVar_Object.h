#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqVar_Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqVar_Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqVar_Object." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqVar_Object : public SequenceVariable
	{
	public:
			class Object* GetObjectValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqVar_Object.GetObjectValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Object** )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::VectorProperty, ActorLocation, 0xFFFFFFFF )
			ADD_OBJECT( Object, ObjValue )
			void SetObjectValue( class Object* NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqVar_Object.SetObjectValue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
